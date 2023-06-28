CC := gcc
CFLAGS := -Wall -Wextra -pedantic -O2 -lulfius

EXE := ipReturn

ENV_DIR := env
LOGGER_DIR := logger
ROUTER_DIR := router
CONTROLLER_DIR := controller

SRCS := $(wildcard *.c) \
        $(LOGGER_DIR)/logger.c \
        $(ENV_DIR)/env.c \
        $(ROUTER_DIR)/router.c \
        $(CONTROLLER_DIR)/controller.c

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
