CFLAGS := -W -Wall

TEST_CFLAGS := $(CFLAGS)
TEST_LIBDIR := -L/usr/lib
TEST_LIB := -lcunit

all: test run_test

test: test.c
	gcc $^ $(TEST_CFLAGS) $(TEST_LIBDIR) $(TEST_LIB) -o $@

build: test

run: test
	./test

.PHONY: clean build run
clean:
	rm test

.DEFAULT_GOAL=run