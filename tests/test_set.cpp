/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:01:39 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 17:42:07 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

/* Random tests
 * Check if allocation is done with allocator
 * */

#include <iostream>
#include <vector>

#ifdef FT
# include "set.hpp"
#else
# include <set>
namespace ft = std;
#endif

int	main(void)
{
	std::cout << "Basic tests with int" << std::endl;
	{
		ft::set<int>	my_set;

		my_set.insert(4);
		my_set.insert(0);
		my_set.insert(6);
		my_set.insert(1);
		my_set.insert(40);
		for (ft::set<int>::iterator it = my_set.begin(); it != my_set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<int>::reverse_iterator it = my_set.rbegin(); it != my_set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}

		my_set.get_allocator();
	}
	std::cout << "Basic tests with string" << std::endl;
	{
		ft::set<std::string>	my_set;

		my_set.insert("4");
		my_set.insert("0");
		my_set.insert("6");
		my_set.insert("1");
		my_set.insert("40");

		for (ft::set<std::string>::iterator it = my_set.begin(); it != my_set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::reverse_iterator it = my_set.rbegin(); it != my_set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	/* Testing member types */
	{
		ft::set<std::string>::key_type	key_type = "oh";
		ft::set<std::string>::value_type value_type = "yeah";
		ft::set<std::string>::key_compare key_compare;
		ft::set<std::string>::value_compare *value_compare;
		ft::set<std::string>::allocator_type allocator_type;
		ft::set<std::string>::reference ref = value_type;
		ft::set<std::string>::const_reference const_ref = value_type;
		ft::set<std::string>::pointer ptr = &value_type;
		ft::set<std::string>::const_pointer const_ptr = &value_type;
		ft::set<std::string>::iterator it;
		ft::set<std::string>::const_iterator const_it;
		ft::set<std::string>::reverse_iterator rit;
		ft::set<std::string>::const_reverse_iterator const_rit;
		ft::set<std::string>::difference_type diff_type = -3;
		ft::set<std::string>::size_type size_type = 4;
		std::cout << key_type << std::endl;
		std::cout << value_type << std::endl;
		std::cout << ref << std::endl;
		std::cout << const_ref << std::endl;
		std::cout << *ptr << std::endl;
		std::cout << *const_ptr << std::endl;
		std::cout << diff_type << std::endl;
		std::cout << size_type << std::endl;
		(void) key_compare;
		(void) value_compare;
	}
	std::cout << "Testing constructors" << std::endl;
	{
		std::cout << "Constructor with comparator" << std::endl;
		ft::set<std::string>	set1((std::less<std::string>()));
		for (ft::set<std::string>::iterator it = set1.begin(); it != set1.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::reverse_iterator it = set1.rbegin(); it != set1.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << "Constructor with iterators" << std::endl;
		std::string data[4];

		data[0] = "Salut les copains";
		data[1] = "Salins";
		data[2] = "Salut lpains";
		data[3] = "S";
		ft::set<std::string>	set2(data, data + 4);

		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}

		for (ft::set<std::string>::reverse_iterator it = set2.rbegin(); it != set2.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << "Constructor with copy" << std::endl;
		std::string data[4];

		data[0] = "Salut les copains";
		data[1] = "Salins";
		data[2] = "Salut lpains";
		data[3] = "S";
		ft::set<std::string>	set2(data, data + 4);

		ft::set<std::string>	set3(set2);

		for (ft::set<std::string>::iterator it = set3.begin(); it != set3.end(); it++)
		{
			std::cout << *it << std::endl;
		}

		for (ft::set<std::string>::reverse_iterator it = set3.rbegin(); it != set3.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing assignation" << std::endl;
	{
		std::cout << "Test 1" << std::endl;
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set = set2;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << "Test 2" << std::endl;
		std::string data[4];

		data[0] = "Salut les copains";
		data[1] = "Salins";
		data[2] = "Salut lpains";
		data[3] = "S";
		ft::set<std::string>	set;
		ft::set<std::string>	set2(data, data + 4);

		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set = set2;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	{
		std::cout << "Test 3" << std::endl;
		std::string data[4];

		data[0] = "Salut les copains";
		data[1] = "Salins";
		data[2] = "Salut lpains";
		data[3] = "S";
		ft::set<std::string>	set;
		ft::set<std::string>	set2(data, data + 4);

		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set2 = set;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing begin() iterator" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string> set(data, data + 4);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing begin() iterator with empty set" << std::endl;
	{
		ft::set<std::string> set;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing begin() const iterator" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string> const set(data, data + 4);
		for (ft::set<std::string>::const_iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing begin() const iterator with empty set" << std::endl;
	{
		ft::set<std::string> const set;
		for (ft::set<std::string>::const_iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing rbegin() iterator" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string> set(data, data + 4);
		for (ft::set<std::string>::reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing rbegin() iterator with empty set" << std::endl;
	{
		ft::set<std::string> set;
		for (ft::set<std::string>::reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing rbegin() const iterator" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string> const set(data, data + 4);
		for (ft::set<std::string>::const_reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing rbegin() const iterator with empty set" << std::endl;
	{
		ft::set<std::string> const set;
		for (ft::set<std::string>::const_reverse_iterator it = set.rbegin(); it != set.rend(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing empty() and size() with empty set" << std::endl;
	{
		ft::set<std::string> set;
		std::cout << set.empty() << set.size() << std::endl;
	}
	std::cout << "Testing empty() and size() with set with one element" << std::endl;
	{
		ft::set<std::string> set;

		set.insert("salut");
		std::cout << set.empty() << set.size() << std::endl;
	}
	std::cout << "testing empty() and size() with set with many elements" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";

		ft::set<std::string> set(data, data + 4);
		set.insert("salut");
		std::cout << set.empty() << set.size() << std::endl;
	}
	std::cout << "testing empty() and size() with set with many elements inserted and removed" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";

		ft::set<std::string> set(data, data + 4);
		std::cout << set.empty() << set.size() << std::endl;
		set.insert("yeah");
		std::cout << set.empty() << set.size() << std::endl;

		std::string data2[4];
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		set.insert(data2, data2 + 4);
		std::cout << set.empty() << set.size() << std::endl;
		set.erase("salut");
		std::cout << set.empty() << set.size() << std::endl;
		set.erase("wowihrwoeiehrwo");
		std::cout << set.empty() << set.size() << std::endl;
		set.erase("yeah");
		std::cout << set.empty() << set.size() << std::endl;
		ft::set<std::string>::iterator beg = set.begin();
		ft::set<std::string>::iterator end = set.end();
		end--;
		end--;
		end--;
		set.erase(beg, end);
		std::cout << set.empty() << set.size() << std::endl;
		set.erase(set.begin(), set.end());
		std::cout << set.empty() << set.size() << std::endl;
	}
	{
		ft::set<std::string> set;

		set.insert("salut");
		std::cout << (set.max_size() > 0) << std::endl; // Not useful to compare this to std one
	}
	std::cout << "Testing clear() with empty set" << std::endl;
	{
		ft::set<std::string> set;

		set.clear();
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set.clear();
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing clear() with one element" << std::endl;
	{
		ft::set<std::string> set;
		set.insert("pouet");
		set.clear();
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing clear() with many elements inserted and removed" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";

		ft::set<std::string> set(data, data + 4);
		set.insert("yeah");

		std::string data2[4];
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		set.insert(data2, data2 + 4);
		set.erase("salut");
		set.erase("wieurhwerh");
		set.erase("top");
		ft::set<std::string>::iterator beg = set.begin();
		ft::set<std::string>::iterator end = set.end();
		end--;
		end--;
		end--;
		set.erase(beg, end);
		set.erase(set.begin(), set.end());
		set.clear();
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing clear(): many elements inserted and removed then clear() then inserted again" << std::endl;
	{
		std::string data[4];

		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";

		ft::set<std::string> set(data, data + 4);
		set.insert("yeah");

		std::string data2[4];
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		set.insert(data2, data2 + 4);
		set.erase("salut");
		set.erase("wihrwhir");
		set.erase("yeah");
		ft::set<std::string>::iterator beg = set.begin();
		ft::set<std::string>::iterator end = set.end();
		end--;
		end--;
		end--;
		set.erase(beg, end);
		set.erase(set.begin(), set.end());
		set.clear();
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set.insert(data, data + 4);
		set.insert("salut");
		set.insert(data2, data2 + 4);
		set.erase("salut");
		set.erase("wieurwier");
		set.erase("top");
		beg = set.begin();
		end = set.end();
		end--;
		end--;
		end--;
		set.erase(beg, end);
		set.erase(set.begin(), set.end());
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing insert(iterator, value_type)" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";

		ft::set<std::string>	set(data, data + 4);
		set.insert(set.begin(), "yeah");
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		ft::set<std::string>::iterator it = set.begin();
		it++;
		it++;
		set.insert(it, "plop");
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing insert(InputIt, InputIt)" << std::endl;
	{
		ft::set<std::string>	set;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::string data2[4];
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		std::vector<std::string > set2(data2, data2 + 4);
		set.insert(set2.begin(), set2.end());
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing erase(iterator)" << std::endl;
	{
		ft::set<std::string>	set;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);

		ft::set<std::string>::iterator it = set.begin();
		it++;
		it++;
		ft::set<std::string>::iterator it2 = it;
		it2++;
		set.erase(it);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set.erase(it2);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing erase(iterator, iterator)" << std::endl;
	{
		ft::set<std::string>	set;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);

		set.erase(set.begin(), set.end());
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set.insert(data, data + 4);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		ft::set<std::string>::iterator it;
		it = set.end();
		it--;
		set.erase(set.begin(), it);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing erase(Key)" << std::endl;
	{
		ft::set<std::string>	set;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		std::cout << set.erase("ohriwhrw") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("worhwui") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("salut") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("pouet") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("top") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("top") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("youpi") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		std::cout << set.erase("youpi") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing swap" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		end1--;
		set.swap(set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing swap with set filled and empty" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		end1--;
		set.swap(set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing swap with 2 set empty" << std::endl;
	{
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		set.swap(set2);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing swap with 2 set filled" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		data2[0] = "hello";
		data2[1] = "c'est genial ceci";
		data2[2] = "yeah";
		data2[3] = "amazing";
		set2.insert(data2, data2 + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		ft::set<std::string>::iterator begin2 = set2.begin();
		ft::set<std::string>::iterator end2 = set2.end();
		end1--;
		end2--;
		set.swap(set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = begin2; it != end2; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing count" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string>	set;
		std::cout << set.count("pouet") << std::endl;
		std::cout << set.count("salut") << std::endl;
		std::cout << set.count("iuwehriwh") << std::endl;
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "testing find" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string>	set;
		for (ft::set<std::string>::iterator it = set.find("pouet"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		set.insert(data, data + 4);
		for (ft::set<std::string>::iterator it = set.find("pouet"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.find("salut"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.find("youpi"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.find("top"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.find("iuwhiwu"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "testing const find" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string> const set(data, data + 4);
		for (ft::set<std::string>::const_iterator it = set.find("pouet"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::const_iterator it = set.find("salut"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::const_iterator it = set.find("youpi"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::const_iterator it = set.find("top"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::const_iterator it = set.find("iuewhruiw"); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing equal_range" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string>	set;
		ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> pair = set.equal_range(0);
		set.insert(data, data + 4);
		pair = set.equal_range("pouet");
		std::cout << "(" << *pair.first << " - " << *pair.second;
		pair = set.equal_range("salut");
		std::cout << "(" << *pair.first << " - " << *pair.second;
		pair = set.equal_range("iuwhiuw");
		std::cout << "(" << *pair.first << " - " << *pair.second;
	}
	std::cout << "Testing const equal_range" << std::endl;
	{
		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		ft::set<std::string>	set;
		ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> pair = set.equal_range(0);
		set.insert(data, data + 4);
		pair = set.equal_range("pouet");
		std::cout << "(" << *pair.first << " - " << *pair.second;
		pair = set.equal_range("salut");
		std::cout << "(" << *pair.first << " - " << *pair.second;
		pair = set.equal_range("iwghriuewh");
		std::cout << "(" << *pair.first << " - " << *pair.second;
	}
	std::cout << "Testing lower bound" << std::endl;
	{
		std::string data[4];
		data[0] = "b";
		data[1] = "d";
		data[2] = "f";
		data[3] = "h";
		ft::set<std::string>	set(data, data + 4);
		std::cout << *set.lower_bound("a") << std::endl;
		std::cout << *set.lower_bound("b") << std::endl;
		std::cout << *set.lower_bound("c") << std::endl;
		std::cout << *set.lower_bound("d") << std::endl;
		std::cout << *set.lower_bound("e") << std::endl;
		std::cout << *set.lower_bound("f") << std::endl;
		std::cout << *set.lower_bound("g") << std::endl;
		std::cout << *set.lower_bound("h") << std::endl;
		std::cout << (set.lower_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing lower bound empty" << std::endl;
	{
		ft::set<std::string>	set;
		std::cout << (set.lower_bound("a") == set.end()) << std::endl;
	}
	std::cout << "Testing const lower bound" << std::endl;
	{
		std::string data[4];
		data[0] = "b";
		data[1] = "d";
		data[2] = "f";
		data[3] = "h";
		ft::set<std::string>	const set(data, data + 4);
		std::cout << *set.lower_bound("a") << std::endl;
		std::cout << *set.lower_bound("b") << std::endl;
		std::cout << *set.lower_bound("c") << std::endl;
		std::cout << *set.lower_bound("d") << std::endl;
		std::cout << *set.lower_bound("e") << std::endl;
		std::cout << *set.lower_bound("f") << std::endl;
		std::cout << *set.lower_bound("g") << std::endl;
		std::cout << *set.lower_bound("h") << std::endl;
		std::cout << (set.lower_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing const lower bound empty" << std::endl;
	{
		ft::set<std::string> const set;
		std::cout << (set.lower_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing upper bound" << std::endl;
	{
		std::string data[4];
		data[0] = "b";
		data[1] = "d";
		data[2] = "f";
		data[3] = "h";
		ft::set<std::string>	set(data, data + 4);
		std::cout << *set.upper_bound("a") << std::endl;
		std::cout << *set.upper_bound("b") << std::endl;
		std::cout << *set.upper_bound("c") << std::endl;
		std::cout << *set.upper_bound("d") << std::endl;
		std::cout << *set.upper_bound("e") << std::endl;
		std::cout << *set.upper_bound("f") << std::endl;
		std::cout << *set.upper_bound("g") << std::endl;
		std::cout << *set.upper_bound("h") << std::endl;
		std::cout << (set.upper_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing upper bound empty" << std::endl;
	{
		ft::set<std::string>	set;
		std::cout << (set.upper_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing const upper bound" << std::endl;
	{
		std::string data[4];
		data[0] = "b";
		data[1] = "d";
		data[2] = "f";
		data[3] = "h";
		ft::set<std::string>	const set(data, data + 4);
		std::cout << *set.upper_bound("a") << std::endl;
		std::cout << *set.upper_bound("b") << std::endl;
		std::cout << *set.upper_bound("c") << std::endl;
		std::cout << *set.upper_bound("d") << std::endl;
		std::cout << *set.upper_bound("e") << std::endl;
		std::cout << *set.upper_bound("f") << std::endl;
		std::cout << *set.upper_bound("g") << std::endl;
		std::cout << *set.upper_bound("h") << std::endl;
		std::cout << (set.upper_bound("i") == set.end()) << std::endl;
	}
	std::cout << "Testing const upper bound empty" << std::endl;
	{
		ft::set<std::string> const set;
		std::cout << (set.upper_bound("i") == set.end()) << std::endl;
	}
	std::cout << "key_comp and value_comp test" << std::endl;
	{
		ft::set<std::string> const set;

		set.key_comp();
		set.value_comp();
	}
	std::cout << "test operators" << std::endl;
	{
		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		ft::set<std::string>	set(data, data + 4);
		ft::set<std::string>	set2(data2, data2 + 4);
		std::cout << (set == set2) << std::endl;
		std::cout << (set != set2) << std::endl;
		std::cout << (set < set2) << std::endl;
		std::cout << (set <= set2) << std::endl;
		std::cout << (set > set2) << std::endl;
		std::cout << (set >= set2) << std::endl;
	}
	std::cout << "test operators differents" << std::endl;
	{
		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		ft::set<std::string>	set(data, data + 4);
		ft::set<std::string>	set2(data2, data2 + 3);
		std::cout << (set == set2) << std::endl;
		std::cout << (set != set2) << std::endl;
		std::cout << (set < set2) << std::endl;
		std::cout << (set <= set2) << std::endl;
		std::cout << (set > set2) << std::endl;
		std::cout << (set >= set2) << std::endl;
	}
	std::cout << "test operators differents same size" << std::endl;
	{
		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "top";
		ft::set<std::string>	set(data, data + 4);
		ft::set<std::string>	set2(data2, data2 + 4);
		std::cout << (set == set2) << std::endl;
		std::cout << (set != set2) << std::endl;
		std::cout << (set < set2) << std::endl;
		std::cout << (set <= set2) << std::endl;
		std::cout << (set > set2) << std::endl;
		std::cout << (set >= set2) << std::endl;
	}
	std::cout << "test operators differents same keys" << std::endl;
	{
		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		data2[0] = "pouet";
		data2[1] = "salut";
		data2[2] = "youpi";
		data2[3] = "coucou";
		ft::set<std::string>	set(data, data + 4);
		ft::set<std::string>	set2(data2, data2 + 4);
		std::cout << (set == set2) << std::endl;
		std::cout << (set != set2) << std::endl;
		std::cout << (set < set2) << std::endl;
		std::cout << (set <= set2) << std::endl;
		std::cout << (set > set2) << std::endl;
		std::cout << (set >= set2) << std::endl;
	}
	std::cout << "Testing external swap" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		end1--;
		swap(set, set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing external swap with set filled and empty" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		end1--;
		swap(set, set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing external swap with 2 set empty" << std::endl;
	{
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		swap(set, set2);
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing external swap with 2 set filled" << std::endl;
	{
		// Swap must preserve iterators
		ft::set<std::string>	set;
		ft::set<std::string>	set2;

		std::string data[4];
		std::string data2[4];
		data[0] = "pouet";
		data[1] = "salut";
		data[2] = "youpi";
		data[3] = "top";
		set.insert(data, data + 4);
		data2[0] = "hello";
		data2[1] = "c'est genial ceci";
		data2[2] = "yeah";
		data2[3] = "amazing";
		set2.insert(data2, data2 + 4);
		ft::set<std::string>::iterator begin1 = set.begin();
		ft::set<std::string>::iterator end1 = set.end();
		ft::set<std::string>::iterator begin2 = set2.begin();
		ft::set<std::string>::iterator end2 = set2.end();
		end1--;
		end2--;
		swap(set, set2);
		for (ft::set<std::string>::iterator it = begin1; it != end1; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = begin2; it != end2; it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
		for (ft::set<std::string>::iterator it = set2.begin(); it != set2.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
	std::cout << "Testing conversion from iterator to const_iterator" << std::endl;
	{
		std::string data[4];

		data[0] = "Salut les copains";
		data[1] = "Salins";
		data[2] = "Salut lpains";
		data[3] = "S";
		ft::set<std::string>	set(data, data + 4);
		for (ft::set<std::string>::const_iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << *it << std::endl;
		}
	}
}
