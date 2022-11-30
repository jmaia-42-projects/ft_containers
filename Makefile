CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -std=c++98
INCLUDE		=	-I includes/

all		:	tests

clean	:
	rm -Rf build/

fclean	: clean
	rm -f test_vector_ft test_vector_std

re		:	fclean all

build/	:
	mkdir -p build/

test_vector_ft: build/ tests/test_vector.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_vector_ft.d $(INCLUDE) -fdiagnostics-color=always -D FT tests/test_vector.cpp -o test_vector_ft

-include build/test_vector_ft.d

test_vector_std: tests/test_vector.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -fdiagnostics-color=always tests/test_vector.cpp -o test_vector_std

test_vector: test_vector_ft test_vector_std
	bash -c "diff <(./test_vector_ft 2>&1) <(./test_vector_std 2>&1)"

tests: test_vector

.PHONY	:	all clean fclean re test_vector tests
