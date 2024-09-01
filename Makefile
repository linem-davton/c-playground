BUILD_DIR = build
SRC_DIR = src
CC = gcc
CFLAGS = -Wall -g

SRCS := $(wildcard $(SRC_DIR)/*.c)
EXECS := $(addprefix $(BUILD_DIR)/,$(basename $(notdir $(SRCS))))

all: $(EXECS) 

$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	$(info Building $@ $<)
	$(info SRCS: $(SRCS)  EXECS: $(EXECS))
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f build/*
