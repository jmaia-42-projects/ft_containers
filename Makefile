NAME		=	a.out

SRCS		=

_OBJS		=	${SRCS:.cpp=.o}
OBJS		=	$(addprefix build/, $(_OBJS))

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98 -g3
INCLUDE		=	-I includes/

all		:	$(NAME)

build/%.o	:	%.cpp
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean	:
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

test_vector:
	$(CC) $(CFLAGS) $(INCLUDE) -fdiagnostics-color=always -D FT tests/test_vector.cpp -o test_vector_ft
	$(CC) $(CFLAGS) $(INCLUDE) tests/test_vector.cpp -o test_vector_std
	bash -c "diff <(./test_vector_ft) <(./test_vector_std)"

clean_test:
	rm -f test_vector_ft test_vector_std

.PHONY	:	all clean fclean re test_vector
