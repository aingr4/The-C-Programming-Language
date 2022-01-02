
FILE := $(wildcard *.c)
PARAMS := 

all: build run

build:
	@echo "********** make $@ **********"
	gcc -o a.out $(FILE)
	@echo "\n"

run:
	@echo "********** make $@ **********"
ifeq ($(strip $(PARAMS)),)
	./a.out
else
	./a.out $(PARAMS)
endif

