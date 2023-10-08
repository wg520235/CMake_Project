#########################################
#概要：项目工程代码编译脚本
#创建者：Nik_TellYou
#时间：2023年10月1日
#########################################

#将编译输出的可执行文件命名为main
SET(PROG_NAME main)

#指定工程编译所引用到的头文件的路径
include_directories (
		${PROJECT_SOURCE_DIR}/include/png
		${PROJECT_SOURCE_DIR}/include/zlib

		${PROJECT_SOURCE_DIR}/modules/encode
		${PROJECT_SOURCE_DIR}/modules/my_test
		)
					
#将encode模块的源文件路径名称, 重命名为ENCODE_SRC
set(ENCODE_SRC ${PROJECT_SOURCE_DIR}/modules/encode/encode_png.c)

#将src目录下的所有.c文件名称, 保存到变量SRC_LIST
aux_source_directory (. SRC_LIST )


#指定工程编译所用到的库文件的路径
link_directories(
		${PROJECT_SOURCE_DIR}/lib/png
		${PROJECT_SOURCE_DIR}/lib/zlib
		${PROJECT_SOURCE_DIR}/lib/my_test
		)
				
#生成可以执行文件main
add_executable (${PROG_NAME} 
		${SRC_LIST}	#主函数main所在文件main.c
		${ENCODE_SRC} #主函数main里引用了encode_png模块的接口函数，所以生成可执行文件的时候这里要加上encode_png模块，其他的功能模块类似。
		)
				


#链接可执行文件所需要的库文件
target_link_libraries (${PROG_NAME}	
		-lpng
		-lz
		-lm	
		-lmy_test
		)
#将生成的可执行文件输出保存到bin目录下
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)