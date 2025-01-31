# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -pthread

# Executable name
TARGET = gc_program

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/gc.c

# Object files
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/gc.o

# Default rule: Build the program
all: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile the program
$(TARGET): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each C file into an object file
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/gc.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/gc.o: $(SRC_DIR)/gc.c $(SRC_DIR)/gc.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/gc.c -o $(BUILD_DIR)/gc.o

# Clean up compiled files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run the program
run: all
	./$(TARGET)

.PHONY: all clean run
