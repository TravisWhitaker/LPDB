CC=clang
CFLAGS=
SOURCE= $(wildcard src/*.c)
INCLUDE=-I./include
OUT=-o
EXECUTABLE=lpdb

all:
	$(CC) $(CFLAGS) $(INCLUDE) $(OUT) $(EXECUTABLE) $(SOURCE)

clean:
	rm $(EXECUTABLE)
