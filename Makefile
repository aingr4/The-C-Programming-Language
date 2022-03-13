FILES := $(wildcard *.c)
USER_LIBRARIES := /home/aingram/C/The-C-Programming-Language/extras/stack
PARAMS := 
FLAGS :=

all: build run

build:
	@echo "********** make $@ **********"
	gcc -o a.out -I$(USER_LIBRARIES) $(FILES) $(FLAGS)
	@echo "\n"

run:
	@echo "********** make $@ **********"
ifeq ($(strip $(PARAMS)),)
	./a.out
else
	./a.out $(PARAMS)
endif

clean:
	@echo "********** make $@ **********"
	find . -name "*.out" -type f -delete