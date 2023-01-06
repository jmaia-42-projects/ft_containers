/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:00:05 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/06 15:24:50 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#include <list>

#ifdef FT
# include "stack.hpp"
#else
# include <stack>
namespace ft = std;
#endif

/* Check that each function of stack, call a function of the underlying container */

int	main(void)
{
	/* Testing member types */
	{
		ft::stack<std::string>::value_type		value_type = "coucou";
		ft::stack<std::string>::container_type	container_type;
		ft::stack<std::string>::size_type		pouet = 5;
		(void) pouet;
	}
	/* Testing constructor */
	{
		ft::stack<std::string>	stack;
		ft::stack<std::string, std::deque<std::string> >	stack2((std::deque<std::string>()));
	}
	/* Testing everything */
	{
		ft::stack<std::string>	stack;

		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push("salut");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push("salut");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push("salut");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push("salut");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push("salut");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push("pouet");
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
	}
	/* Testing everything with const and another underlying container*/
	{
		std::list<std::string>	under_c;

		under_c.push_back("salut");
		under_c.push_back("comment");
		under_c.push_back("ca");
		under_c.push_back("va");
		ft::stack<std::string, std::list<std::string> >	const stack(under_c);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
	}
	/* Tests comparisons equals */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<std::string>	v;
		ft::stack<std::string>	v2;

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;

		v.push("5");
		v.push("3");
		v.push("1");
		v.push("0");
		v2.push("5");
		v2.push("3");
		v2.push("1");
		v2.push("0");

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
	/* Tests comparisons differents */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<std::string>	v;
		ft::stack<std::string>	v2;

		v.push("5");
		v.push("3");
		v.push("1");
		v.push("0");

		v2.push("1");
		v2.push("1423");
		v2.push("-1");

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
	/* Tests comparisons with empty */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<std::string>	v;
		ft::stack<std::string>	v2;

		v.push("5");
		v.push("3");
		v.push("1");
		v.push("0");

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
	/* TESTING WITH INT */
	/* Testing member types */
	{
		ft::stack<int>::value_type		value_type = 3;
		ft::stack<int>::container_type	container_type;
		ft::stack<int>::size_type		pouet = 5;
		(void) pouet;
		(void) value_type;
	}
	/* Testing constructor */
	{
		ft::stack<int>	stack;
		ft::stack<int, std::deque<int> >	stack2((std::deque<int>()));
	}
	/* Testing everything */
	{
		ft::stack<int>	stack;

		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push(3);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		stack.push(3);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push(3);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push(3);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push(3);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.push(4);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
		stack.pop();
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
	}
	/* Testing everything with const and another underlying container*/
	{
		std::list<int>	under_c;

		under_c.push_back(3);
		under_c.push_back(1);
		under_c.push_back(-4);
		under_c.push_back(0);
		ft::stack<int, std::list<int> >	const stack(under_c);
		std::cout << stack.empty() << std::endl;
		std::cout << stack.size() << std::endl;
		std::cout << stack.top() << std::endl;
	}
	/* Tests comparisons equals */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<int>	v;
		ft::stack<int>	v2;

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;

		v.push(5);
		v.push(3);
		v.push(1);
		v.push(0);
		v2.push(5);
		v2.push(3);
		v2.push(1);
		v2.push(0);

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
	/* Tests comparisons differents */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<int>	v;
		ft::stack<int>	v2;

		v.push(5);
		v.push(3);
		v.push(1);
		v.push(0);

		v2.push(1);
		v2.push(1423);
		v2.push(-1);

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
	/* Tests comparisons with empty */
	std::cout << "Comparisons" << std::endl;
	{
		ft::stack<int>	v;
		ft::stack<int>	v2;

		v.push(5);
		v.push(3);
		v.push(1);
		v.push(0);

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}
}
