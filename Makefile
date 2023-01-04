CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98# -g3 -fstandalone-debug -O0 -fsanitize=address
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

test_vector: test_vector_std test_vector_ft
	bash -c "diff <(./test_vector_ft 2>&1) <(./test_vector_std 2>&1)"

test_map_ft: build/ tests/test_map.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_map_ft.d $(INCLUDE) -fdiagnostics-color=always -D FT tests/test_map.cpp -o test_map_ft

-include build/test_map_ft.d

test_map_std: tests/test_map.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -fdiagnostics-color=always tests/test_map.cpp -o test_map_std

test_map: test_map_std test_map_ft
	bash -c "diff <(./test_map_ft 2>&1) <(./test_map_std 2>&1)"

tests: test_vector test_map

.PHONY	:	all clean fclean re test_vector tests
