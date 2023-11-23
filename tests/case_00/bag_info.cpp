
#include "cmdline.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"

#include <algorithm>
#include <map>
#include <string>

#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {
  cmdline::parser args;
  args.add<std::string>("bag-name", 'b', "specify the path of a bag", true, "");
  args.add("all", 0, "get summary information about a bag");
  args.add("more", 0, "get more information about a bag or a topic");
  args.add<std::string>("topic", 0, "get information about specified topic",
                        false, "");
  args.add("help", 'h', "print this message");
  args.set_program_name("bag_info");

  bool ok = args.parse(argc, argv);
  if (argc == 1 || args.exist("help")) {
    std::cerr << args.usage();
    return 0;
  }

  if (!ok) {
    std::cerr << args.error() << std::endl << args.usage();
    return 0;
  }

  // parse parameters
  std::string bag_name = args.get<std::string>("bag-name");
  bool all = args.exist("all");
  bool more = args.exist("more");
  std::string topic_name = "";
  if (args.exist("topic")) {
    topic_name = args.get<std::string>("topic");
  }

  rosbag::Bag bag;
  bag.open(bag_name, rosbag::bagmode::Read);
  if (!bag.isOpen()) {
    printf("open %s failed\n", bag_name.c_str());
    return -1;
  }

  rosbag::View view(bag);

  // path
  { printf("%-12s %s\n", "path:", bag.getFileName().c_str()); }

  // version
  {
    printf("%-12s %d.%d\n", "version:", bag.getMajorVersion(),
           bag.getMinorVersion());
  }

  // duration && start && end
  {
    ros::Time bag_begin_time = view.getBeginTime();
    ros::Time bag_end_time = view.getEndTime();
    double duration = (bag_end_time - bag_begin_time).toSec();
    int mins = duration / 60;
    int secs = duration - mins * 60;

    time_t begin_time = bag_begin_time.toSec();
    char begin_tmbuf[64] = {0};
    struct tm* begin_tm;
    begin_tm = localtime(&begin_time);
    strftime(begin_tmbuf, sizeof(begin_tmbuf), "%Y-%m-%d %H:%M:%S", begin_tm);

    time_t end_time = bag_end_time.toSec();
    char end_tmbuf[64] = {0};
    struct tm* end_tm;
    end_tm = localtime(&end_time);
    strftime(end_tmbuf, sizeof(end_tmbuf), "%Y-%m-%d %H:%M:%S", end_tm);

    printf("%-12s %d:%02ds (%ds)\n", "duration:", mins, secs, (int)duration);
    printf("%-12s %s (%.2f)\n", "start:", begin_tmbuf, bag_begin_time.toSec());
    printf("%-12s %s (%.2f)\n", "end:", end_tmbuf, bag_end_time.toSec());
  }

  // size
  {
    uint64_t bag_size = bag.getSize();
    char bag_size_buf[64] = {0};
    if (bag_size > 1024 * 1024) {
      snprintf(bag_size_buf, sizeof(bag_size_buf), "%ld (%.2f MB)", bag_size,
               (double)bag_size / 1024 / 1024);
    } else {
      snprintf(bag_size_buf, sizeof(bag_size_buf), "%ld", bag_size);
    }
    printf("%-12s %s\n", "size:", bag_size_buf);
  }

  // messages
  { printf("%-12s %d\n", "messages:", view.size()); }

  // compression
  {
    int compression_type = bag.getCompression();
    char compression_type_buf[64] = {0};
    if (compression_type == 1) {
      snprintf(compression_type_buf, sizeof(compression_type_buf), "%s", "bz2");
    } else if (compression_type == 2) {
      snprintf(compression_type_buf, sizeof(compression_type_buf), "%s", "lz4");
    } else {
      snprintf(compression_type_buf, sizeof(compression_type_buf), "%s",
               "none");
    }
    printf("%-12s %s\n", "compression:", compression_type_buf);
  }

  // chunks
  { printf("%-12s %u\n", "chunks:", bag.getChunkThreshold()); }

  // topics
  {
    auto conns = view.getConnections();
    printf("%-12s %lu\n", "topics:", conns.size());
    if (all) {
      std::sort(conns.begin(), conns.end(),
                [](const decltype(*conns.begin())& lhs,
                   const decltype(*conns.begin())& rhs) {
                  return lhs->topic < rhs->topic;
                });
      std::map<std::string, uint32_t> topic_count;
      std::map<std::string, std::pair<double, double>> topic_start_end;
      for (auto iter = view.begin(); iter != view.end(); iter++) {
        std::string name = iter->getTopic();
        topic_count[name]++;
        if (topic_start_end.find(name) != topic_start_end.end()) {
          topic_start_end[name].second = iter->getTime().toSec();
        } else {
          topic_start_end[name].first = iter->getTime().toSec();
        }
      }

      char buf[1024] = {0};
      int offset = 0;
      offset += snprintf(buf, sizeof(buf) - offset, "%-12s %-50s %6s %8s", "",
                         "TOPIC", "COUNT", "FREQ(Hz)");
      if (more) {
        offset += snprintf(buf + offset, sizeof(buf) - offset,
                           " %-15s %-15s %-45s %-35s", "START-TIME", "END-TIME",
                           "DATATYPE", "MD5SUM");
      }
      printf("%s\n", buf);

      for (const auto& conn : conns) {
        char buf[1024] = {0};
        int offset = 0;
        std::string name = conn->topic;
        uint32_t count = topic_count[name];
        double freq = (double)count / (topic_start_end[name].second -
                                       topic_start_end[name].first);
        offset += snprintf(buf, sizeof(buf) - offset, "%-12s %-50s %6d %8.2f",
                           "", name.c_str(), count, freq);
        if (more) {
          offset += snprintf(buf + offset, sizeof(buf) - offset,
                             " %-15.2f %-15.2f %-45s %-35s",
                             topic_start_end[name].first,
                             topic_start_end[name].second,
                             conn->datatype.c_str(), conn->md5sum.c_str());
        }
        printf("%s\n", buf);
      }
    }
  }

  // specified topic
  {
    if (!topic_name.empty()) {
      auto conns = view.getConnections();
      auto iter_found =
          std::find_if(conns.begin(), conns.end(),
                       [topic_name](const decltype(*conns.begin()) ele) {
                         return ele->topic == topic_name;
                       });
      if (iter_found == conns.end()) {
        printf("\ncould not found %s !!!\n", topic_name.c_str());
      } else {
        printf("\n%s's info:\n\n", topic_name.c_str());
        printf("DATATYPE: %s\n", (*iter_found)->datatype.c_str());
        printf("MD5SUM:   %s\n", (*iter_found)->md5sum.c_str());
        std::string msg_def = (*iter_found)->msg_def;
        if (!more) {
          size_t pos = msg_def.find("=======================================");
          if (pos != std::string::npos) {
            msg_def = std::string(msg_def.begin(), msg_def.begin() + pos);
          }
        }
        printf("MESSAGE_DEFINITION:\n%s\n", msg_def.c_str());
      }
    }
  }

  bag.close();

  return 0;
}