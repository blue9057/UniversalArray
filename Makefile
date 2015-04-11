CUR_DIR = $(shell pwd)
CFLAGS = -std=c++11 -I$(CUR_DIR)

all: test1

test1: test/test1.cc UniversalArray.hpp
	c++ -o out/test1 test/test1.cc $(CFLAGS)

clean:
	rm -rf out/*
