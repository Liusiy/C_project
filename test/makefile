CFLAGS := gcc
CFLAGS += -DBDCOM
CFLAGS += -DHELLO

TARGET := test.o

OBJECT := test.c

$(TARGET):$(OBJECT)
	@$(CFLAGS) -g $^ -o $@

.PHONY:clean
clean:
	@erase *.o

