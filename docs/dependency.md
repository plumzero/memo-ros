
openssl 略

### 通过 apt 方式安装依赖

可以通过 `apt-cache search 名称` 来尝试搜索。

#### 1 libgpg-error

目标: gpg-error.h/libgpg-error.so

```s
  sudo apt-get install libgpg-error-dev
```

#### 2 gpgme

目标: assuan.h/libassuan.so 和 gpgme.h/libgpgme.so

```s
  sudo apt-get install libgpgme11-dev
```
顺利的话，头文件和库文件分别会安装到 `/usr/include` 和 `/usr/lib/x86_64-linux-gnu` 中去。

其中 libgpgme.so 依赖于 libassuan.so 。

### 通过编译方式生成依赖库

注: 如果执行 `configure` 出错，可以先执行一下 `autogen.sh`，再执行 `configure` 试一下。

首先清楚需要安装 libgpg-error、libassuan、libgpgme 这三个库，然后需要了解它们的依赖关系，即 libassuan 和 libgpgme 均依赖 libgpg-error，同时 libgpgme 又依赖 libassuan 。最后要注意版本适配，这里统一选择 2015 年的最后一个版本。

#### 1 libgpg-error

[历史参考版本](https://www.gnupg.org/ftp/gcrypt/libgpg-error/)

选择版本: 1.21
```s
  ./configure --prefix=/usr/local/libgpg-error
  make
  sudo make install
```


#### 2 libassuan

[历史参考版本](https://www.gnupg.org/ftp/gcrypt/libassuan/)

选择版本: 2.4.2
```s
  ./configure --with-libgpg-error-prefix=/usr/local/libgpg-error --prefix=/usr/local/libassuan
  make
  sudo make install
```

#### 3 gpgme

[历史参考版本](https://www.gnupg.org/ftp/gcrypt/gpgme/)

选择版本: 1.6.0
```s
  ./configure --with-libgpg-error-prefix=/usr/local/libgpg-error --with-libassuan-prefix=/usr/local/libassuan --prefix=/usr/local/gpgme
  make
  sudo make install
```
