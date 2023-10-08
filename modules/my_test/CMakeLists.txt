# 查找当前my_test目录下的所有源文件，并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(. DIR_LIB_SRCS)

# 将所有的.c文件生成my_test库文件
add_library (my_test ${DIR_LIB_SRCS})

# 指定my_test库的输出路径为lib/my_test/目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/my_test)