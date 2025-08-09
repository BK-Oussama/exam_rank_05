


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCs = *.cpp 
HDRs = *.hpp
NAME = execute

all: $(NAME)

$(NAME): $(SRCs) $(HDRs)
	$(CC) $(CFLAGS) $(SRCs) -o $(NAME)
	
clean:
	rm -f $(NAME)

re: clean all