TARGET = philo
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

CC = cc
CFLAGS = -pthread
all: $(TARGET)
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
fclean: clean

re: fclean all

.PHONY: all clean fclean re