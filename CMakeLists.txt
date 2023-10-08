cmake_minimum_required (VERSION 3.5.1)#cmake 的最低版本

project (My_Project)#项目的名称

set (CMAKE_C_COMPILER "gcc")#指定编译c代码的编译器
set (CMAKE_CXX_COMPILER "g++")#指定编译c++代码的编译器

#添加编译子目录my_test，脚本执行到这里的时候，会去执行子目录下的cmake脚本
add_subdirectory(modules/my_test)

#2、再执行src目录下的CMakeLists.txt脚本
add_subdirectory (src)


