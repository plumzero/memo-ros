
GnuPG(GNU Privacy Guard)是一个由 GNU 遵照 OpenGPG(RFC4880)规范编写的免费软件，本文展示了关于 GnuPG 的一些使用方法。

关于 OpenPGP 可参见 `http://www.openpgp.org/`，关于 GnuPG 可参见 `http://www.gnupg.org/`。

> 这里创建了一个新的 linux 用户 pgper 用于对 gpg 的使用测试。

这里使用 gpg 的版本信息如下:
```s
$ gpg --version
gpg (GnuPG) 1.4.20
Copyright (C) 2015 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Home: ~/.gnupg
支持的算法：
公钥： RSA, RSA-E, RSA-S, ELG-E, DSA
对称加密： IDEA, 3DES, CAST5, BLOWFISH, AES, AES192, AES256,
                TWOFISH, CAMELLIA128, CAMELLIA192, CAMELLIA256
散列： MD5, SHA1, RIPEMD160, SHA256, SHA384, SHA512, SHA224
压缩： 不压缩, ZIP, ZLIB, BZIP2
```

### 常用命令

#### (1) 生成密钥对

执行命令 `gpg --gen-key` 生成密钥对。按照提示根据需要进行操作，如下:
```s
$ gpg --gen-key
gpg (GnuPG) 1.4.20; Copyright (C) 2015 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

gpg: 已创建目录‘/home/pgper/.gnupg’
gpg: 新的配置文件‘/home/pgper/.gnupg/gpg.conf’已建立
gpg: 警告：在‘/home/pgper/.gnupg/gpg.conf’里的选项于此次运行期间未被使用
gpg: 钥匙环‘/home/pgper/.gnupg/secring.gpg’已建立
gpg: 钥匙环‘/home/pgper/.gnupg/pubring.gpg’已建立
请选择您要使用的密钥种类：
   (1) RSA and RSA (default)
   (2) DSA and Elgamal
   (3) DSA (仅用于签名)
   (4) RSA (仅用于签名)
您的选择？ 1
RSA 密钥长度应在 1024 位与 4096 位之间。
您想要用多大的密钥尺寸？(2048) 2048
您所要求的密钥尺寸是 2048 位
请设定这把密钥的有效期限。
         0 = 密钥永不过期
      <n>  = 密钥在 n 天后过期
      <n>w = 密钥在 n 周后过期
      <n>m = 密钥在 n 月后过期
      <n>y = 密钥在 n 年后过期
密钥的有效期限是？(0) 1y
密钥于 2025年08月02日 星期六 10时25分09秒 CST 过期
以上正确吗？(y/n) y

您需要一个用户标识来辨识您的密钥；本软件会用真实姓名、注释和电子邮件地址组合
成用户标识，如下所示：
    “Heinrich Heine (Der Dichter) <heinrichh@duesseldorf.de>”

真实姓名： Alice
电子邮件地址： alice@example.com
注释： Alice Liddell
您选定了这个用户标识：
    “Alice (Alice Liddell) <alice@example.com>”

更改姓名(N)、注释(C)、电子邮件地址(E)或确定(O)/退出(Q)？ O
您需要一个密码来保护您的私钥。

我们需要生成大量的随机字节。这个时候您可以多做些琐事(像是敲打键盘、移动
鼠标、读写硬盘之类的)，这会让随机数字发生器有更好的机会获得足够的熵数。
....+++++
....+++++
我们需要生成大量的随机字节。这个时候您可以多做些琐事(像是敲打键盘、移动
鼠标、读写硬盘之类的)，这会让随机数字发生器有更好的机会获得足够的熵数。
.......+++++
.....+++++
gpg: /home/pgper/.gnupg/trustdb.gpg：建立了信任度数据库
gpg: 密钥 CE6F17FA 被标记为绝对信任
公钥和私钥已经生成并经签名。

gpg: 正在检查信任度数据库
gpg: 需要 3 份勉强信任和 1 份完全信任，PGP 信任模型
gpg: 深度：0 有效性：  1 已签名：  0 信任度：0-，0q，0n，0m，0f，1u
gpg: 下次信任度数据库检查将于 2025-08-02 进行
pub   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
      密钥指纹 = C2DC 95F9 D5FA F721 F783  659A 63C3 D680 CE6F 17FA
uid                  Alice (Alice Liddell) <alice@example.com>
sub   2048R/F8C5DA12 2024-08-02 [有效至：2025-08-02]
```

#### (2) 列出公钥

通过 `gpg -k` 或 `gpg --list-public-keys` 查看公钥信息。如果参数后面没有指定公钥，则输出所有公钥:
```s
$ gpg -k
/home/pgper/.gnupg/pubring.gpg
------------------------------
pub   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
sub   2048R/F8C5DA12 2024-08-02 [有效至：2025-08-02]
```

#### (3) 列出私钥

通过 `gpg -K` 或 `gpg --list-secret-keys` 查看私钥。如果参数后面没有指定私钥，则输出所有私钥:
```s
$ gpg -K
/home/pgper/.gnupg/secring.gpg
------------------------------
sec   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
ssb   2048R/F8C5DA12 2024-08-02
```

#### (4) 导出公钥

`gpg -a -o public-file.key --export <keyId>`表示导出公钥 keyId 到文件 public-file.key 中。其中:
- `-a` 为 --armor 的简写，表示密钥以 ASCII 的形式输出，默认以二进制的形式输出。
- `-o` 为 --output 的简写，指定写入的文件。

```s
$ gpg -a -o public-file.key --export Alice
```
查看公钥内容:
```s
$ cat public-file.key
-----BEGIN PGP PUBLIC KEY BLOCK-----
Version: GnuPG v1

mQENBGasQ9IBCADUfk/7lR/T/TRn9o5epxzyXOytokAv5idHCyJqOWx2uuu7c5jx
ZcJFL379ftsSjsj7rhC55Wp7TYxqi9lzBp4V6QM4q9NDnaWZAQ/qxzIikHHHtfe6
J9kOGbWKkvmKQWtKrxzcXQ7HfeUGAD9KiaA2+EnxNeuEVttCv1D2mQs/PqaZqAGL
BqNobnl3iljhyBl5iVpfJ7BJ8GOyE+7n3ZgXO+4kcTLtGequLI1PgPb6PNvQVD9d
jZGfDbRxq5bQRhzxTX/lPcVC3CZHOkgthkGDVxrobdIY+8MhFedJX2PXbet6meEX
WfopHd+unNROSrMUkPqsrWfulxkSs96WfBknABEBAAG0KUFsaWNlIChBbGljZSBM
aWRkZWxsKSA8YWxpY2VAZXhhbXBsZS5jb20+iQE+BBMBAgAoBQJmrEPSAhsDBQkB
4TOABgsJCAcDAgYVCAIJCgsEFgIDAQIeAQIXgAAKCRBjw9aAzm8X+sdjB/9Bk6/y
6WQzcTlRprSgGfzLFMwMaHXHHurySZQdV7TxpiLTn5CGEEzLEqYmWtuxyxJY/QNW
sOLLK2EdBA1dwoK+w+ml4Z2Dmn9h106qC9RHgLrqk3Z0YLB+pyx9ZuFy4PRqfZze
QSnBHwKC5vafIiNd6y506WOjOq56fOQVSylBfy8UAt/kw2J9YVcWiKMmqfYFcwRY
h5xp72lPnL/CdiYUpxZuC6/Bol7PIi95or6ea03y1+Fb2Bnclsy5mPjhiIfHmHl7
JU0VcCnyxSu8tHCx8noI/28Rua5naiW/3uag5NaAaAqZrGQGWf+XjoAgDUY5c4Q2
LdIwHLBEB8OO9wYluQENBGasQ9IBCADSc52agoFtP5w3ELQVbWoNvYjv50ThI6Ne
tFX7Yf0ccSuuKcwLICAVTKYDuQ9PcW2mFnmp00C+cyfIh98+dGhgE+9aZKd8H/by
6d7iH39vUhHlMBy0PYQ0dKdgiDgZBO1lpLi3gHpxqpmH4B9G11GNnh2S19Vcmho0
aXK6E5OBHrisnyhAJDldOeIX3uwKRFID/iVIp0jt9i1q+dIwZEfC6gWl6oOc5A+F
BfyvV3Of7GSLBV5MkEJ86yFfNSoIrMh1ADyoCzV4gxvibkmAppl9QUt6beavNwA1
u+KL7oaOMoRJEwoquHvCieW69bk/Up7NXDDS3hgf+4E3tOguImZlABEBAAGJASUE
GAECAA8FAmasQ9ICGwwFCQHhM4AACgkQY8PWgM5vF/rhLwgAn/GGmACLKQdm63Wj
tpww2LmkH6PcrLwLFZVoWgzLpsBeAHcwLPNAY2S42U4LXc38PMkUOX2yexHWex1w
E1JUgseko/GxS05YQZjHHTJAHngImCHK1N+is+GSJGWilbVv1bPMjoQGrzFp2QSc
kcyLJKE5nZ2EPPtQJKIRqunRpzJ2koipTPrtcymVO5CZnbKP94JD2W33C/pNxxvy
raRnR+Oml9GzMEUp/Hpvrpx8nHescC4SAAt+R4vIa14++QxEYyCsCXXb+3q5MMqp
nWBEn6IEiK1F1hI6OyhuJnhNtOXT8M9eYnnzqkE+eHaoP8UB+l7+0s8Xd7VRsugC
RaIuEw==
=iIc1
-----END PGP PUBLIC KEY BLOCK-----
```

#### (5) 导出私钥

`gpg -a -o private-file.key --export-secret-keys <keyId>`表示导出私钥 keyId 到文件 private-file.key 中(导出私钥可能需要输入保护私钥的密码):
```s
$ gpg -a -o private-file.key --export-secret-keys Alice
```
查看私钥内容:
```s
$ cat private-file.key
-----BEGIN PGP PRIVATE KEY BLOCK-----
Version: GnuPG v1

lQPGBGasQ9IBCADUfk/7lR/T/TRn9o5epxzyXOytokAv5idHCyJqOWx2uuu7c5jx
ZcJFL379ftsSjsj7rhC55Wp7TYxqi9lzBp4V6QM4q9NDnaWZAQ/qxzIikHHHtfe6
J9kOGbWKkvmKQWtKrxzcXQ7HfeUGAD9KiaA2+EnxNeuEVttCv1D2mQs/PqaZqAGL
BqNobnl3iljhyBl5iVpfJ7BJ8GOyE+7n3ZgXO+4kcTLtGequLI1PgPb6PNvQVD9d
jZGfDbRxq5bQRhzxTX/lPcVC3CZHOkgthkGDVxrobdIY+8MhFedJX2PXbet6meEX
WfopHd+unNROSrMUkPqsrWfulxkSs96WfBknABEBAAH+BwMCCORymPifAU5gO9AH
J9ClCyy9WG4fv7tC6eflnH+DhQDIMVvK3eghLfjg0X28OUWZdjIdrURDijI32Js8
7rCxt0dz/0xAnorxlUCTXVl2OjR2ySPtqH+iU1JmB070i7HyyI9V6m7MA4WdfSy6
fRgwT7YAeK7BqiVpcSZxL6YtUtESkggyN0zaXLm/Lru4u4cwMwBhBShE6T3dFUgW
ikX2xKJVPC2NaWUKFsI6nClHkKfVKTIpUFVqb+TBTvhGyOBshX6a4WM7y0bhnTiZ
8yzqB+dADWFVS6nu79UziKNEEywWCLZgz5Fd8gXL7NW0syWqJvxpE9b9PhWpB9nM
/QBZC8xJFzweT3B2yh47525R8zWCjqzsy5Kk9FojsbrUkEtjBhS+uFJYiypGIJSe
xcz5kaUyshmoT1+6/gwZc/2cbfJM/hqDnirS6YDZnwJAO9oS1DxzB61lO5vHBEpn
yKoa+thJX5Qc9/qvylez4+kSVP2XxDevz4Ol4Gx+6eLILN6jtm3+nj4BNSOlmg0r
t8KlYjd2Zdp+rQSuAMeNtGGu9wJ/fKVkyraZxLaVew8PnAAdLbVEoXkldCRVjxCR
sDQetuYjePBufcoA+0KQC85Xx6Y+PLTfKR1gAmrjnl4Gzo0sV1vBR+9VlNMjm5/M
RKvix7Q5FEC27HiyYDk0BR73obtRjaP8/P23WH12Nz0S1d1m66LvMvMEngbGLhDt
5IIWcNeDiTGmw5XEEx6NeWrTZQMHWcI6efB/OjAWeIW2KhyUS6u1DEWhtbu1Qfq0
xqY2EHLRZKvzGQaZd3JTMC8ael+geERSAehmpSVUR49c/8DuZTDOEZFC35jrQpKP
zF22KZlhU8ONLN8KueV0PpUfT0pk/cTM53mjY2nXrA6OPA/VbKGGv7caQgJSqnSH
Tft2id+/cagVtClBbGljZSAoQWxpY2UgTGlkZGVsbCkgPGFsaWNlQGV4YW1wbGUu
Y29tPokBPgQTAQIAKAUCZqxD0gIbAwUJAeEzgAYLCQgHAwIGFQgCCQoLBBYCAwEC
HgECF4AACgkQY8PWgM5vF/rHYwf/QZOv8ulkM3E5Uaa0oBn8yxTMDGh1xx7q8kmU
HVe08aYi05+QhhBMyxKmJlrbscsSWP0DVrDiyythHQQNXcKCvsPppeGdg5p/YddO
qgvUR4C66pN2dGCwfqcsfWbhcuD0an2c3kEpwR8Cgub2nyIjXesudOljozquenzk
FUspQX8vFALf5MNifWFXFoijJqn2BXMEWIecae9pT5y/wnYmFKcWbguvwaJezyIv
eaK+nmtN8tfhW9gZ3JbMuZj44YiHx5h5eyVNFXAp8sUrvLRwsfJ6CP9vEbmuZ2ol
v97moOTWgGgKmaxkBln/l46AIA1GOXOENi3SMBywRAfDjvcGJZ0DxgRmrEPSAQgA
0nOdmoKBbT+cNxC0FW1qDb2I7+dE4SOjXrRV+2H9HHErrinMCyAgFUymA7kPT3Ft
phZ5qdNAvnMnyIffPnRoYBPvWmSnfB/28une4h9/b1IR5TActD2ENHSnYIg4GQTt
ZaS4t4B6caqZh+AfRtdRjZ4dktfVXJoaNGlyuhOTgR64rJ8oQCQ5XTniF97sCkRS
A/4lSKdI7fYtavnSMGRHwuoFpeqDnOQPhQX8r1dzn+xkiwVeTJBCfOshXzUqCKzI
dQA8qAs1eIMb4m5JgKaZfUFLem3mrzcANbvii+6GjjKESRMKKrh7wonluvW5P1Ke
zVww0t4YH/uBN7ToLiJmZQARAQAB/gcDAgjkcpj4nwFOYEzbcWx3cb1+4I+YOq9E
YJQwwrkpbmFvwZySuKkctTaI1TjOYTIkEXVMfPOf8tqgkdU2BzuZdSCNw6BY+le5
dOeJ0eJjupm9fuYidyNrfnDpauYBxBS//NAbeV6BPYQCJgjT3TbvVTFbBPgHLAa2
kEGLhrCUVpDTWrxaQtF4Ic3dFthUNNkBaI1IKrBcTaJ8Fkry4WKw7Pk2v8O5o5aO
0+ni+q7Ag686zBszpBArqDP5f0+/PWxV2OLjo7w4525ncixKd6E6rnj0Uq5ycXq+
cisc+gNfngQVALpK023LOxEHw1kumMfV0qUv0YNvxbsWd+nYFSMuyXn+WOpn2Ykt
cpGpmWUi2JiftO3a9SB/4B77s/nwg8Hm/Q4A6fnbYcQADU7P8KqI0FcXZ9moskRa
iDg1bo3z/Fa1gtWA8mjTd5SsOmlULkMzWzz7bcHyqZA9RKatjrE47DRfC75PawmL
Gw+H+dPeOMdivgrB2BUUmdurJ+QR4OMg7xZCc26pyeVIT/d1ZbxjjnYkGN6asx1y
mLbAhF7uNewW1ZUScvjXE7bASXTgCFDGIAadACyRvL4eiApcMprnpFuTExs2fZ9G
8Afp66htnNWQ7Yq2RlCXcrO8ZIeaewdJwo0W9iIjix6DLRB2kxxhbhp6Tn9gHq1t
UwL0MdXRWGICxtgkgGpEHEMVTkDHiRw6xoe9accRgIk4wfXc5JjuKsBUAqU5XE8u
LzlUFPDXiLWO6+f9mhSOP75WKluCd0KzUQ4N+62+vRFGtbOn3mWi0qQogj2QMDa9
fg2MHAnMIu/naLHvmLDKa76AJt3NXvjLYE7HARdSRSNL8YEITzEJvXHBQmpwj8S5
8PkJGAEL2ceSOtnHoOhOoubOA0nh1pbWMfbsOopP0uvVD4WrALHj8adsBJ6ZQIkB
JQQYAQIADwUCZqxD0gIbDAUJAeEzgAAKCRBjw9aAzm8X+uEvCACf8YaYAIspB2br
daO2nDDYuaQfo9ysvAsVlWhaDMumwF4AdzAs80BjZLjZTgtdzfw8yRQ5fbJ7EdZ7
HXATUlSCx6Sj8bFLTlhBmMcdMkAeeAiYIcrU36Kz4ZIkZaKVtW/Vs8yOhAavMWnZ
BJyRzIskoTmdnYQ8+1AkohGq6dGnMnaSiKlM+u1zKZU7kJmdso/3gkPZbfcL+k3H
G/KtpGdH46aX0bMwRSn8em+unHycd6xwLhIAC35Hi8hrXj75DERjIKwJddv7erkw
yqmdYESfogSIrUXWEjo7KG4meE205dPwz15iefOqQT54dqg/xQH6Xv7Szxd3tVGy
6AJFoi4T
=hKX3
-----END PGP PRIVATE KEY BLOCK-----
```

#### (6) 导入公私钥

这里以导入私钥为例进行说明，公钥的导入方法相同。

这里从其他地方拿到一份私钥文件，内容如下:
```s
$ cat private-test.key
-----BEGIN PGP PRIVATE KEY BLOCK-----
Version: GnuPG v1

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
LYxADpgShsNtJiU/Dbn8jA+BlK/77fGnkvnc
=YcIw
-----END PGP PRIVATE KEY BLOCK-----
```
通过命令 `gpg --import private-test.key` 导入私钥(导入私钥可能需要输入保护私钥的密码):
```s
$ gpg --import private-test.key 
gpg: 密钥 80EF08CD：私钥已导入
gpg: 密钥 80EF08CD：公钥“Foo00 (A GPG key for test cases) <bar@baz>”已导入
gpg: 合计被处理的数量：1
gpg:               已导入：1  (RSA: 1)
gpg:       读取的私钥：1
gpg:   导入的私钥：1
```

再次查看公私钥信息，可以看到有了新的内容 Foo00:
```s
$ gpg -K
/home/pgper/.gnupg/secring.gpg
------------------------------
sec   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
ssb   2048R/F8C5DA12 2024-08-02

sec#  2048R/80EF08CD 2017-10-30
uid                  Foo00 (A GPG key for test cases) <bar@baz>
ssb   2048R/FAFDD621 2017-10-30

$ gpg -k
/home/pgper/.gnupg/pubring.gpg
------------------------------
pub   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
sub   2048R/F8C5DA12 2024-08-02 [有效至：2025-08-02]

pub   2048R/80EF08CD 2017-10-30
uid                  Foo00 (A GPG key for test cases) <bar@baz>
sub   2048R/FAFDD621 2017-10-30
```

#### 删除公私钥

`gpg --delete-keys <keyId>` 和 `gpg --delete-secret-keys <keyId>` 可分别用于删除公钥和私钥(删除顺序应是先是私钥，后是公钥):
```s
$ gpg --delete-secret-keys Foo00
gpg (GnuPG) 1.4.20; Copyright (C) 2015 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.


sec  2048R/80EF08CD 2017-10-30 Foo00 (A GPG key for test cases) <bar@baz>

要从钥匙环里删除这把密钥吗？(y/N) y
这是一把私钥！――真的要删除吗？(y/N) y

$ gpg --delete-keys Foo00
gpg (GnuPG) 1.4.20; Copyright (C) 2015 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.


pub  2048R/80EF08CD 2017-10-30 Foo00 (A GPG key for test cases) <bar@baz>

要从钥匙环里删除这把密钥吗？(y/N) y
```
再次查看，可以看到已经没有关于 Foo00 的信息了:
```s
$ gpg -K
/home/pgper/.gnupg/secring.gpg
------------------------------
sec   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
ssb   2048R/F8C5DA12 2024-08-02

$ gpg -k
/home/pgper/.gnupg/pubring.gpg
------------------------------
pub   2048R/CE6F17FA 2024-08-02 [有效至：2025-08-02]
uid                  Alice (Alice Liddell) <alice@example.com>
sub   2048R/F8C5DA12 2024-08-02 [有效至：2025-08-02]
```