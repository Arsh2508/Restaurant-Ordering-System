CXX := g++
CXXFLAGS := -Wall -Wextra -I../include

SRC_DIR := ../src
TEST_DIR := ../googletests
OBJ_DIR := obj
BIN_DIR := bin

MAIN_TARGET := $(BIN_DIR)/restaurant
TEST_TARGET := $(BIN_DIR)/runTests

SRC_FILES := $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
MAIN_SRC := $(SRC_DIR)/main.cpp
TEST_SRC := $(wildcard $(TEST_DIR)/*.cpp)

MAIN_OBJ := $(MAIN_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
COMMON_OBJ := $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ := $(TEST_SRC:$(TEST_DIR)/%.cpp=$(OBJ_DIR)/%.test.o)

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(COMMON_OBJ) $(MAIN_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_TARGET): $(COMMON_OBJ) $(TEST_OBJ) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -lgtest -lgtest_main -pthread -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean test
