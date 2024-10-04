## PROJECT INITIAL CONFIGURATION
EXE_NAME					:= divide-and-conquer
STD_FLAGS					:= -Wall -Wextra -Werror -std=c++98 -ggdb
OBJS_PATH					:= obj/
GTEST_PATH					:= gtest/

## PROJECT FILES
HEADERS						:= Account.hpp Bank.hpp
SRCS						:= main.cpp Account.cpp Bank.cpp
OBJ							:= $(patsubst %.cpp, $(OBJS_PATH)%.o, $(SRCS))

## COLOR VARIABLES
RED							= 	\e[91m
GREEN						= 	\e[92m
YELLOW						= 	\e[93m
RC							= 	\e[0m

all: $(EXE_NAME)

$(EXE_NAME): $(OBJS_PATH) $(OBJ)
	@			printf "\n$(YELLOW)Creating Project '$(OBJ)'$(RC)\n" 
	@			c++ $(STD_FLAGS) $(OBJ) $(HEADERS) -o $(EXE_NAME)
	@			printf "$(GREEN)$(EXE_NAME) created$(RC)\n"

$(OBJ): %.o: %.cpp $(HEADERS)
	@			c++ -I $(HEADERS) $(STD_FLAGS) -c $< -o $@
	@			printf "$(GREEN).$(RC)"

$(OBJS_PATH):
	@			mkdir $@

clean:
	@		rm -rf $(OBJS_PATH)	
	@		printf "$(RED)$(EXE_NAME) objects removed$(RC)\n"

fclean:
	@		rm -rf $(EXE_NAME)
	@		printf "$(RED)$(EXE_NAME) removed$(RC)\n"

re: fclean all

$(GTEST_PATH):
	@		mkdir -p $@

bt: $(GTEST_PATH)
	cmake -S . -B $<
	cmake --build $<

rt:
	@			cd $(GTEST_PATH) && ctest --verbose

rte:
	@			cd $(GTEST_PATH) && ctest --rerun-failed --output-on-failure --verbose --interactive-debug-mode

.PHONY: re all fclean clean