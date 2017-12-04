CXX = g++
LINKCXX	= g++
CFLAGS = -g -Wall -O2

TOP_DIR := $(shell pwd)
SRC_DIRS := $(shell find $(TOP_DIR) -maxdepth 1 -type d)
TARGET := server

# 添加依赖的头文件目录
INC_PATH = -I../../include

# 添加所依赖的库文件目录
LIB_PATH = -L../../lib

# 添加依赖的库,eg:libsayhello.a
#EXT_LIB     = -Wl,-rpath,$(TOP_DIR)/bin/ -lsayhello
EXT_LIB = -lglog

CXX_SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
#CXX_SRCS = server.cpp
CXX_OBJS = $(patsubst %.cpp, %.o, $(CXX_SRCS))

all:$(TARGET)

$(TARGET):$(CXX_OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIB_PATH) $(EXT_LIB)
%.o:%.cpp
	$(CXX) $(INC_PATH) $(CFLAGS) -c -o $@ $<

.PHONY:clean distclean
clean:
	rm -f $(CXX_OBJS) $(C_OBJS)
distclean:
	rm -f $(TARGET) $(CXX_OBJS) $(C_OBJS)
