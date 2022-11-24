/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:54:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/24 13:57:01 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT
# include "vector.hpp"
#else
# include <vector>
namespace ft = std;
#endif

#include <iostream>

int	main(void)
{
	/* Basic test */
	{
		ft::vector<int> v;

		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		v.pop_back();
		v.pop_back();
		v.push_back(2147483647);
		v.push_back(-2147483648);
		v.pop_back();
		v.push_back(0);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
		std::cout << v.front() << std::endl;
		std::cout << v.back() << std::endl;
	}
	/* Empty vector test */
	{
		ft::vector<int> v;

		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
		std::cout << v.front() << std::endl;
		std::cout << v.back() << std::endl;
	}
	/* One element test */
	{
		ft::vector<int> v;

		v.push_back(5);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
		std::cout << v.front() << std::endl;
		std::cout << v.back() << std::endl;
	}
	/* Assign on empty */
	{
		ft::vector<int> v;

		v.assign(5, 3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Assign on filled */
	{
		ft::vector<int> v;

		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		v.pop_back();
		v.pop_back();
		v.push_back(2147483647);
		v.push_back(-2147483648);
		v.pop_back();
		v.push_back(0);
		v.assign(5, 3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Empty assign on filled */
	{
		ft::vector<int> v;

		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		v.pop_back();
		v.pop_back();
		v.push_back(2147483647);
		v.push_back(-2147483648);
		v.pop_back();
		v.push_back(0);
		v.assign(0, 3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
}
