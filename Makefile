CXX			=	clang++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -g3 -fstandalone-debug -O0 -fsanitize=address -fdiagnostics-color=always
INCLUDE		=	-I includes/

all		:	tests

clean	:
	rm -Rf build/

fclean	: clean
	rm -f test_vector_ft test_vector_std test_map_ft test_map_std test_set_ft test_set_std test_stack_ft test_stack_std

re		:	fclean all

build/	:
	mkdir -p build/

test_vector_ft: build/ tests/test_vector.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_vector_ft.d $(INCLUDE) -D FT tests/test_vector.cpp -o test_vector_ft

-include build/test_vector_ft.d

test_vector_std: tests/test_vector.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) tests/test_vector.cpp -o test_vector_std

test_vector: test_vector_std test_vector_ft
	bash -c "diff <(./test_vector_ft 2>&1) <(./test_vector_std 2>&1)"

test_map_ft: build/ tests/test_map.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_map_ft.d $(INCLUDE) -D FT tests/test_map.cpp -o test_map_ft

-include build/test_map_ft.d

test_map_std: tests/test_map.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -fdiagnostics-color=always tests/test_map.cpp -o test_map_std

test_map: test_map_std test_map_ft
	bash -c "diff <(./test_map_ft 2>&1) <(./test_map_std 2>&1)"

test_set_ft: build/ tests/test_set.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_set_ft.d $(INCLUDE) -D FT tests/test_set.cpp -o test_set_ft

-include build/test_set_ft.d

test_set_std: tests/test_set.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) tests/test_set.cpp -o test_set_std

test_set: test_set_std test_set_ft
	bash -c "diff <(./test_set_ft 2>&1) <(./test_set_std 2>&1)"

test_stack_ft: build/ tests/test_stack.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF build/test_stack_ft.d $(INCLUDE) -D FT tests/test_stack.cpp -o test_stack_ft

-include build/test_stack_ft.d

test_stack_std: tests/test_stack.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) tests/test_stack.cpp -o test_stack_std

test_stack: test_stack_std test_stack_ft
	bash -c "diff <(./test_stack_ft 2>&1) <(./test_stack_std 2>&1)"

tests: test_vector test_map test_set test_stack

.PHONY	:	all clean fclean re test_vector test_map test_set test_stack tests
