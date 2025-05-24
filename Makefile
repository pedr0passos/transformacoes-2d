CC       = gcc

SRC_DIR  = src
BUILD_DIR= build
BIN_DIR  = bin
INCLUDE_DIR = include
LIB_DIR  = src/lib 

SRC = $(wildcard $(SRC_DIR)/*.c) \
      $(wildcard $(SRC_DIR)/core/*.c) \
      $(wildcard $(SRC_DIR)/utils/*.c)

OBJ = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

CFLAGS = -Wall -g \
         -I$(INCLUDE_DIR) \
         -Isrc \
         -Isrc/core \
         -Isrc/utils

LDFLAGS = -L$(LIB_DIR) -lmingw32 -lSDL2main -lSDL2

TARGET = $(BIN_DIR)/programa

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
