CC := gcc
CFLAGS := -Wall -Wextra -pedantic -O2 -lulfius

EXE := ipReturn
SRCS := $(wildcard *.c)

define rmExistFile
	@rm -f $1
endef

define compile
	$(CC) $(1) -o $(2) $(3)
endef

$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

$(EXE)_debug: $(SRCS)
	$(CC) $(CFLAGS) -g $^ -o $@

.PHONY: run
run: $(EXE)
	./$(EXE)

.PHONY: compile
compile: $(EXE)
	@echo "Done!"

.PHONY: debug
debug: $(EXE)_debug
	@gdb $(EXE)_debug

.PHONY: build
build: clean compile

.PHONY: clean
clean:
	$(call rmExistFile,$(EXE))
	$(call rmExistFile,$(EXE)_debug)
