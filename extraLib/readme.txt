1、先编译zlib,因为libpng依赖zlib,步骤如下：
cd zlib-1.2.11
export CC=gcc CXX=g++
mkdir install_dir
 ./configure --prefix=/home/nik/Projects/CMake_Project/extra/zlib-1.2.11/install_dir
make && make install

2、编译libpng库， 步骤如下：
cd libpng-1.6.37
mkdir install_dir
CC=gcc CXX=g++ ./configure --prefix=/home/nik/Projects/CMake_Project/extra/libpng-1.6.37/install_dir LIBS=-L/home/nik/Projects/CMake_Project/extra/zlib-1.2.11/install_dir/lib CPPFLAGS=-I/home/nik/Projects/CMake_Project/extra/zlib-1.2.11/install_dir/include

make && make install;