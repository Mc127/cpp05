CXX = c++
CXXFCLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp  main.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = Bureaucrat

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFCLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFCLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
.PHONY : all clean fclean re
