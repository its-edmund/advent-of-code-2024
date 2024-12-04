# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR := advent
BUILD_DIR := ../build
BIN_DIR := ../bin

# Target Executable
TARGET := $(BIN_DIR)/advent_of_code

# Source Files (dynamically find all .cpp files in SRC_DIR)
SRCS := $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Object Files (place them in BUILD_DIR)
OBJS := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(notdir $(SRCS)))

# Default Target
all: $(TARGET)

# Build Target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build Object Files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean Build
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Phony Targets
.PHONY: all clean run

