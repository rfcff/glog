CXX = g++
LINKCXX = g++
CFLAGS = -g -Wall -O2

TOP_DIR := $(shell pwd)
SRC_DIRS := $(shell find $(TOP_DIR) -maxdepth 1 -type d)
TARGET := libglog.a

# 添加依赖的头文件目录
INC_PATH := -I../../include

# 添加所依赖的库文件目录
LIB_PATH := -L../../lib

# 添加依赖的库,eg:libsayhello.a
#EXT_LIB     = -Wl,-rpath,$(TOP_DIR)/bin/ -lsayhello

CPP_SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
CC_SRCS += $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cc))
HPP_SRCS += $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.hpp))
CXX_SRCS += $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cxx))

CPP_OBJS = $(patsubst %.cpp, %.o, $(CPP_SRCS))
CC_OBJS += $(patsubst %.cc, %.o, $(CC_SRCS))
HPP_OBJS += $(patsubst %.hpp, %.o, $(HPP_SRCS))
CXX_OBJS += $(patsubst %.cxx, %.o, $(CXX_SRCS))

all:$(TARGET)

$(TARGET):$(CPP_OBJS) $(CC_OBJS) $(HPP_OBJS) $(CXX_OBJS)
	ar crv $(TARGET) $^
	cp $(TARGET) ../../lib/
%.o:%.cpp
	$(CXX) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.cc
	$(CXX) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.hpp 
	$(CXX) $(INC_PATH) $(CFLAGS) -c -o $@ $<
%.o:%.cxx
	$(CXX) $(INC_PATH) $(CFLAGS) -c -o $@ $<

.PHONY:clean distclean
clean:
	rm -f $(CPP_OBJS) $(CC_OBJS) $(HPP_OBJS) $(CXX_OBJS)
distclean:
	rm -f $(TARGET) $(CPP_OBJS) $(CC_OBJS) $(HPP_OBJS) $(CXX_OBJS) 
