#显示所有警告
#CFLAG += -Wall -Wextra -std=c++0x
#CFLAG += -O #基本优化
# -g选项，产生供gdb调试用的可执行文件
# Maybe add: -Wextra
# CFLAG += -O -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wno-parentheses \
# 		 -Wcast-align -Wstrict-prototypes -Wconversion -Wformat \
# 		 -Wformat-nonliteral -Wmissing-braces -Wuninitialized \
# 		 -Wmissing-declarations  -Winline \
# 		 -Wmissing-prototypes -Wtraditional -Wredundant-decls -pedantic

CXXFLAGS += -Wall -Wextra -Werror -Wfatal-errors -std=c++11
# CXXFLAGS += -O -Wpointer-arith \
# 		-Wno-parentheses -Wunreachable-code -Wundef -Wctor-dtor-privacy \
# 		-Wcast-align -Wconversion -Wformat -Wchar-subscripts \
# 		-Wformat-nonliteral -Wmissing-braces -Wuninitialized \
# 		-Winline -Wcast-qual -Wconversion -Wconversion-null -Wcoverage-mismatch \
# 		-Wdiv-by-zero -Wdouble-promotion \
# 		-Weffc++ -Wempty-body -Wendif-labels -Wenum-compare 

# CXXFLAGS += -pedantic -Wabi -Wcast-qual -Wfloat-equal  \
# 		-Wmissing-declarations -Wmissing-format-attribute -Wno-long-long -Wpacked -Wredundant-decls \
# 		-Wshadow -Wno-missing-field-initializers -Wno-missing-braces -Wno-sign-compare -Wno-multichar 

#-Wfatal-errors 
#-fmax-errors=N    // 在出现第 N 此错误的时候停止编译，GCC 4.6 and later
#-pedantic 以ANSI/ISO C标准列出的所有警告
#-Wabi	当编译器生成的代码和标准C++ ABI不兼容的时候发出警告。
#-Wmissing-declarations
#-Werror 把警告当作错误。出现任何警告就放弃编译。
#-Wshadow 当一个局部变量遮盖住了另一个局部变量，或者全局变量时，给出警告
#-Wpointer-arith	对函数指针或者void *类型的指针进行算术操作时给出警告
#-Wcast-qual	当强制转化丢掉了类型修饰符时给出警告
#-Waggregate-return	如果定义或调用了返回结构体或联合体的函数，编译器就发出警告
#-Winline  如果某函数不能内联，编译器都将发出警告
#-Wunreachable-code 如果编译器探测到永远不会执行到的代码，就给出警告
#-Wcast-align 一旦某个指针类型强制转换导致目标所需的地址对齐增加时，编译器就发出警告
#-Wundef 当一个没有定义的符号出现在 #if 中时，给出警告。
#-Wredundant-decls 如果在同一个可见域内某定义多次声明，编译器就发出警告，即使这些重复声明有效并且毫无差别。
#-Wctor-dtor-privacy 当一个类没有用时给出警告
#-Wcast-align 当转换指针类型导致对齐边界增长时给出警告
#-Wcast-qual 当类型转换丢失限定信息时给出警告
# -Wconversion 当隐式类型转换可能改变值时给出警告
# -Wconversion-null 将 NULL 转换为非指针类型时给出警告
#-Wdiv-by-zero 对编译时发现的零除给出警告
#-Wdouble-promotion 对从“float”到“double”的隐式转换给出警告
#-Weffc++ 对不遵循《Effetive C++》的风格给出警告 
#-Wempty-body 当 if 或 else 语句体为空时给出警告
#-Wendif-labels 当 #elif 和 #endif 后面跟有其他标识符时给出警告 
#-Wenum-compare 对不同枚举类型之间的比较给出警告
#-Werror-implicit-function-declaration 不建议使用此开关；请改用 -Werror=implicit-function-declaration 
#-Wfloat-equal 当比较浮点数是否相等时给出警告

CC = g++

PROJECT = main
SYSLIB = 

OBJDIR = .
#SRCS = $(wildcard ./*.cpp)
SRCDIRS = ./ch06
SRCS = $(SRCDIRS)/BinaryTree_test.cpp


 #指定头文件目录，代码中就不需要把头文
INCLUDE_DIRS = -I. -I./ch06
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

$(PROJECT):$(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(SYSLIB)
#	mv $(OBJS_BASE) $(OBJDIR)
$(OBJS):%.o:%.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@ $(INCLUDE_DIRS)

test:test.cpp
	$(CC) $(CXXFLAGS) test.cpp -o main
.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o $(SRCDIRS)/*.o $(PROJECT)

# CC = g++

# #INCLUDE = -I./simple/

# SRC = prob15.cpp

# main:$(SRC) 
# 	$(CC) $(CXXFLAGS)  $(SRC) -o main

# test:test.cpp
# 	$(CC) $(CXXFLAGS)  test.cpp -o main
	
# .PHONY:clean
# clean:
# 	rm -f *.o main
