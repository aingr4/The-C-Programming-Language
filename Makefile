FILES := $(wildcard *.c)
PARAMS := 
FLAGS :=

all: build run

build:
	@echo "********** make $@ **********"
	gcc -o a.out $(FILES) $(FLAGS)
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