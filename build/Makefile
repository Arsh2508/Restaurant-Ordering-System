CXX      = g++
CFLAGS   = -I../include -Wall -Wextra 

NAME     = Restaurant

SRC_DIR  = ../src
OBJ_DIR  = obj

SRC      = $(wildcard $(SRC_DIR)/*.cpp)
OBJ      = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(NAME)

.PHONY: clean
