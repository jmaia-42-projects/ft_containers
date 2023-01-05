/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:54:56 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/04 01:22:50 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

/* Random tests
 * Check if allocation is done with allocator
 * */

#ifdef FT
# include "vector.hpp"
#else
# include <vector>
namespace ft = std;
#endif

#include <iostream>
#include <list>
#include <string>

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
	/* Assign with range on filled */
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

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);

		v.assign(filler.begin(), filler.end());
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
	/* Assignment operator tests */
	{
		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v(filler.begin(), filler.end());
		ft::vector<int> v2 = v;
		for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* At() tests */
	{
		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v(filler.begin(), filler.end());
		std::cout << v.at(0) << std::endl;
		std::cout << v.at(1) << std::endl;
		std::cout << v.at(2) << std::endl;
		std::cout << v.at(3) << std::endl;
		try
		{
			std::cout << v.at(-1) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(4) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(5) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(-1) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
	}
	/* At() tests on empty list */
	{
		ft::vector<int> v;
		try
		{
			v.at(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
	}
	/* operator[] tests */
	{
		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v(filler.begin(), filler.end());
		std::cout << v[0] << std::endl;
		std::cout << v[1] << std::endl;
		std::cout << v[2] << std::endl;
		std::cout << v[3] << std::endl;
	}
	/* Empty() tests */
	{
		ft::vector<int> v;
		std::cout << v.empty() << std::endl;
		std::list<int>	filler;
		filler.push_back(5);
		ft::vector<int>	v2(filler.begin(), filler.end());
		std::cout << v.empty() << std::endl;
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v3(filler.begin(), filler.end());
		std::cout << v.empty() << std::endl;
	}
	/* size() tests */
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
		std::cout << v.size() << std::endl;

		ft::vector<int> v2;
		std::cout << v2.size() << std::endl;
	}
	/* reserve(0) test */
	{
		ft::vector<int> v;

		v.reserve(0);
		std::cout << v.capacity() << std::endl;
		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* reserve(3) test */
	{
		ft::vector<int> v;

		v.reserve(3);
		std::cout << v.capacity() << std::endl;
		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		std::cout << v.capacity() << std::endl;
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* reserve(5) test */
	{
		ft::vector<int> v;

		v.reserve(5);
		std::cout << v.capacity() << std::endl;
		v.push_back(-1);
		v.push_back(5);
		v.push_back(3);
		std::cout << v.capacity() << std::endl;
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Clear on empty vector test */
	{
		ft::vector<int> v;

		v.clear();
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
	}
	/* Clear on filled vector test */
	{
		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		ft::vector<int>	v(filler.begin(), filler.end());
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.clear();
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert one value to vector tests */
	{
		ft::vector<int>	v;

		v.insert(v.begin(), 5);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), 3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), 1);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert many values on vector tests */
	{
		ft::vector<int>	v;

		std::cout << v.size() << std::endl;
		v.insert(v.begin(), 5, 3);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), 3, 12);
		std::cout << v.size() << std::endl;
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), 1, 15);
		std::cout << v.size() << std::endl;
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert range on vector tests */
	{
		ft::vector<int>	v;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Erase pos test */
	{
		ft::vector<int>	v;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());
		v.erase(v.begin());
		v.erase(v.begin() + 2);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Erase range test */
	{
		ft::vector<int>	v;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());

		v.erase(v.begin() + 1, v.end());
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Resize on empty vector test */
	std::cout << "Resize on empty vector test" << std::endl;
	{
		ft::vector<int>	v;

		v.resize(0, 5);
		v.resize(5, 5);
		v.resize(10, 5);
		v.resize(12, 5);
		v.resize(40, 5);
		v.resize(47, 5);
		v.resize(50, 5);
		v.resize(55, 5);
		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Test swap */
	std::cout << "Swap" << std::endl;
	{
		ft::vector<int>	v;
		ft::vector<int>	v2;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<int>	filler2;
		filler2.push_back(0);
		filler2.push_back(1);
		filler2.push_back(23842);
		filler2.push_back(2);
		filler2.push_back(3);
		filler2.push_back(2488723);
		filler2.push_back(0);
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

		v.swap(v2);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Test external swap */
	std::cout << "External swap" << std::endl;
	{
		ft::vector<int>	v;
		ft::vector<int>	v2;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<int>	filler2;
		filler2.push_back(0);
		filler2.push_back(1);
		filler2.push_back(23842);
		filler2.push_back(2);
		filler2.push_back(3);
		filler2.push_back(2488723);
		filler2.push_back(0);
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

		swap(v, v2);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Tests comparisons equals */
	std::cout << "Comparisons" << std::endl;
	{
		ft::vector<int>	v;
		ft::vector<int>	v2;

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());
		v2.insert(v2.begin(), filler.begin(), filler.end());

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
		ft::vector<int>	v;
		ft::vector<int>	v2;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<int>	filler2;
		filler.push_back(1);
		filler.push_back(1423);
		filler.push_back(-1);
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

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
		ft::vector<int>	v;
		ft::vector<int>	v2;

		std::list<int>	filler;
		filler.push_back(5);
		filler.push_back(3);
		filler.push_back(1);
		filler.push_back(0);
		v.insert(v.begin(), filler.begin(), filler.end());

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}

	/* TESTS WITH STRING */

	/* Basic test */
	{
		ft::vector<std::string> v;

		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		v.pop_back();
		v.pop_back();
		v.push_back("2147483647");
		v.push_back("-2147483648");
		v.pop_back();
		v.push_back("0");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
		std::cout << v.front() << std::endl;
		std::cout << v.back() << std::endl;
	}
	/* Empty vector test */
	{
		ft::vector<std::string> v;

		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* One element test */
	{
		ft::vector<std::string> v;

		v.push_back("5");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
		std::cout << v.front() << std::endl;
		std::cout << v.back() << std::endl;
	}
	/* Assign on empty */
	{
		ft::vector<std::string> v;

		v.assign(5, "3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Assign on filled */
	{
		ft::vector<std::string> v;

		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		v.pop_back();
		v.pop_back();
		v.push_back("2147483647");
		v.push_back("-2147483648");
		v.pop_back();
		v.push_back("0");
		v.assign(5, "3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Empty assign on filled */
	{
		ft::vector<std::string> v;

		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		v.pop_back();
		v.pop_back();
		v.push_back("2147483647");
		v.push_back("-2147483648");
		v.pop_back();
		v.push_back("0");
		v.assign(0, "3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Assign with range on filled */
	{
		ft::vector<std::string> v;

		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		v.pop_back();
		v.pop_back();
		v.push_back("2147483647");
		v.push_back("-2147483648");
		v.pop_back();
		v.push_back("0");

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");

		v.assign(filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Constructor tests */
	{
		ft::vector<std::string>	v1;
		for (ft::vector<std::string>::iterator it = v1.begin(); it != v1.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v1.rbegin(); it != v1.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v2((std::allocator<std::string>()));
		for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v3(5);
		for (ft::vector<std::string>::iterator it = v3.begin(); it != v3.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v3.rbegin(); it != v3.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v4(0);
		for (ft::vector<std::string>::iterator it = v4.begin(); it != v4.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v4.rbegin(); it != v4.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v6(5, "4");
		for (ft::vector<std::string>::iterator it = v6.begin(); it != v6.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v6.rbegin(); it != v6.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v7(5, "4", std::allocator<std::string>());
		for (ft::vector<std::string>::iterator it = v7.begin(); it != v7.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v7.rbegin(); it != v7.rend(); it++)
			std::cout << *it << std::endl;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v8(filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v8.begin(); it != v8.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v8.rbegin(); it != v8.rend(); it++)
			std::cout << *it << std::endl;

		ft::vector<std::string>	v9(filler.end(), filler.end());
		for (ft::vector<std::string>::iterator it = v9.begin(); it != v9.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v9.rbegin(); it != v9.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* Assignment operator tests */
	{
		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v(filler.begin(), filler.end());
		ft::vector<std::string> v2 = v;
		for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
			std::cout << *it << std::endl;
	}
	/* At() tests */
	{
		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v(filler.begin(), filler.end());
		std::cout << v.at(0) << std::endl;
		std::cout << v.at(1) << std::endl;
		std::cout << v.at(2) << std::endl;
		std::cout << v.at(3) << std::endl;
		try
		{
			std::cout << v.at(-1) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(4) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(5) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
		try
		{
			std::cout << v.at(-1) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
	}
	/* At() tests on empty list */
	{
		ft::vector<std::string> v;
		try
		{
			v.at(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Yeah, exception thrown !" << std::endl;
		}
	}
	/* operator[] tests */
	{
		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v(filler.begin(), filler.end());
		std::cout << v[0] << std::endl;
		std::cout << v[1] << std::endl;
		std::cout << v[2] << std::endl;
		std::cout << v[3] << std::endl;
	}
	/* Empty() tests */
	{
		ft::vector<std::string> v;
		std::cout << v.empty() << std::endl;
		std::list<std::string>	filler;
		filler.push_back("5");
		ft::vector<std::string>	v2(filler.begin(), filler.end());
		std::cout << v.empty() << std::endl;
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v3(filler.begin(), filler.end());
		std::cout << v.empty() << std::endl;
	}
	/* size() tests */
	{
		ft::vector<std::string> v;

		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		v.pop_back();
		v.pop_back();
		v.push_back("2147483647");
		v.push_back("-2147483648");
		v.pop_back();
		v.push_back("0");
		std::cout << v.size() << std::endl;

		ft::vector<std::string> v2;
		std::cout << v2.size() << std::endl;
	}
	/* reserve(0) test */
	{
		ft::vector<std::string> v;

		v.reserve(0);
		std::cout << v.capacity() << std::endl;
		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* reserve(3) test */
	{
		ft::vector<std::string> v;

		v.reserve(3);
		std::cout << v.capacity() << std::endl;
		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		std::cout << v.capacity() << std::endl;
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* reserve(5) test */
	{
		ft::vector<std::string> v;

		v.reserve(5);
		std::cout << v.capacity() << std::endl;
		v.push_back("-1");
		v.push_back("5");
		v.push_back("3");
		std::cout << v.capacity() << std::endl;
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Clear on empty vector test */
	{
		ft::vector<std::string> v;

		v.clear();
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
	}
	/* Clear on filled vector test */
	{
		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		ft::vector<std::string>	v(filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.clear();
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert one value to vector tests */
	{
		ft::vector<std::string>	v;

		v.insert(v.begin(), "5");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), "3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), "1");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert many values on vector tests */
	{
		ft::vector<std::string>	v;

		std::cout << v.size() << std::endl;
		v.insert(v.begin(), 5, "3");
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), 3, "12");
		std::cout << v.size() << std::endl;
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		v.insert(v.begin(), 1, "15");
		std::cout << v.size() << std::endl;
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Insert range on vector tests */
	{
		ft::vector<std::string>	v;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		std::cout << v.size() << std::endl;
	}
	/* Erase pos test */
	{
		ft::vector<std::string>	v;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());
		v.erase(v.begin());
		v.erase(v.begin() + 2);
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Erase range test */
	{
		ft::vector<std::string>	v;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());

		v.erase(v.begin() + 1, v.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Resize on empty vector test */
	std::cout << "Resize on empty vector test" << std::endl;
	{
		ft::vector<std::string>	v;

		v.resize(0, "5");
		v.resize(5, "5");
		v.resize(10, "5");
		v.resize(12, "5");
		v.resize(40, "5");
		v.resize(47, "5");
		v.resize(50, "5");
		v.resize(55, "5");
		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Test swap */
	std::cout << "Swap" << std::endl;
	{
		ft::vector<std::string>	v;
		ft::vector<std::string>	v2;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<std::string>	filler2;
		filler2.push_back("0");
		filler2.push_back("1");
		filler2.push_back("23842");
		filler2.push_back("2");
		filler2.push_back("3");
		filler2.push_back("2488723");
		filler2.push_back("0");
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

		v.swap(v2);
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Test external swap */
	std::cout << "External swap" << std::endl;
	{
		ft::vector<std::string>	v;
		ft::vector<std::string>	v2;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<std::string>	filler2;
		filler2.push_back("0");
		filler2.push_back("1");
		filler2.push_back("23842");
		filler2.push_back("2");
		filler2.push_back("3");
		filler2.push_back("2488723");
		filler2.push_back("0");
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

		swap(v, v2);
		for (ft::vector<std::string>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << std::endl;
		for (ft::vector<std::string>::iterator it = v2.begin(); it != v2.end(); it++)
			std::cout << *it << std::endl;
	}
	/* Tests comparisons equals */
	std::cout << "Comparisons" << std::endl;
	{
		ft::vector<std::string>	v;
		ft::vector<std::string>	v2;

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());
		v2.insert(v2.begin(), filler.begin(), filler.end());

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
		ft::vector<std::string>	v;
		ft::vector<std::string>	v2;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());

		std::list<std::string>	filler2;
		filler.push_back("1");
		filler.push_back("1423");
		filler.push_back("-1");
		v2.insert(v2.begin(), filler2.begin(), filler2.end());

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
		ft::vector<std::string>	v;
		ft::vector<std::string>	v2;

		std::list<std::string>	filler;
		filler.push_back("5");
		filler.push_back("3");
		filler.push_back("1");
		filler.push_back("0");
		v.insert(v.begin(), filler.begin(), filler.end());

		std::cout << (v == v2) << std::endl;
		std::cout << (v != v2) << std::endl;
		std::cout << (v <= v2) << std::endl;
		std::cout << (v >= v2) << std::endl;
		std::cout << (v < v2) << std::endl;
		std::cout << (v > v2) << std::endl;
	}

}
