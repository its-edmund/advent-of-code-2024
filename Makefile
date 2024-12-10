# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Compiler and Flags
CXX := g++-14
CXXFLAGS := -std=c++20 -Wall -Iinclude -Isrc
LDFLAGS := -Wl,-ld_classic

# Target Executable
TARGET := $(BIN_DIR)/advent_of_code

# Source Files (dynamically find all .cpp files in SRC_DIR)
SRCS := $(wildcard ${SRC_DIR}/**/*.cpp) src/main.cpp

# Object Files (place them in BUILD_DIR)
# OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default Target
all: test

# Build Target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

# Build Object Files

# Compile Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

# $(BUILD_DIR)/main.o: main.cpp
# 	@mkdir -p $(BUILD_DIR)
#	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

solve: $(TARGET)
	./$(TARGET) solve

test: $(TARGET)
	./$(TARGET) test

# Phony Targets
.PHONY: all clean run solve test

