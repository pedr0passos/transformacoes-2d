# Compilador
CC = gcc

# Diretórios
SRC_DIR = src
INC_DIR = $(SRC_DIR)/include
LIB_DIR = $(SRC_DIR)/lib

# Flags de compilação
CFLAGS = -Wall -g -I$(INC_DIR)

# Flags de linkagem
LDFLAGS = -L$(LIB_DIR) -lmingw32 -lSDL2main -lSDL2

# Arquivos fonte e objeto
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
TARGET = programa

# Regra padrão
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compilação de .c para .o
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Limpeza
clean:
	del /Q $(SRC_DIR)\*.o *.exe
