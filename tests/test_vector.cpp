/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:54:56 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/24 15:17:57 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT
# include "vector.hpp"
#else
# include <vector>
namespace ft = std;
#endif

#include <iostream>
#include <list>

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
	/* Constructor tests */
	{
		ft::vector<int>	v1;
		for (ft::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v2((std::allocator<int>()));
		for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v3(5);
		for (ft::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v4(0);
		for (ft::vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v4.rbegin(); it != v4.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v6(5, 4);
		for (ft::vector<int>::iterator it = v6.begin(); it != v6.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v6.rbegin(); it != v6.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v7(5, 4, std::allocator<int>());
		for (ft::vector<int>::iterator it = v7.begin(); it != v7.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v7.rbegin(); it != v7.rend(); it++)
			std::cout << *it << std::endl;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v8(filler.begin(), filler.end());
		for (ft::vector<int>::iterator it = v8.begin(); it != v8.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v8.rbegin(); it != v8.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<int>	v9(filler.end(), filler.end());
		for (ft::vector<int>::iterator it = v9.begin(); it != v9.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v9.rbegin(); it != v9.rend(); it++)
			std::cout << *it << std::endl;
	}
}
