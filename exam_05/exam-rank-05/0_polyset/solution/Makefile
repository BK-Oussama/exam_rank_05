NAME = polyset
SRCS = main.cpp \
	   searchable_tree_bag.cpp \
	   searchable_array_bag.cpp \
	   set.cpp \
	   tree_bag.cpp \
	   array_bag.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	rm -f $(NAME)

re: fclean all