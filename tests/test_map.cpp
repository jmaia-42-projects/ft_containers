/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:01:39 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/02 12:59:17 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifdef FT
# include "map.hpp"
#else
# include <map>
namespace ft = std;
#endif

int	main(void)
{
	std::cout << "Basic tests with int" << std::endl;
	{
		ft::map<int, int>	my_map;

		my_map.insert(ft::pair<int, int>(4, 3));
		my_map.insert(ft::pair<int, int>(0, 3));
		my_map.insert(ft::pair<int, int>(6, 3));
		my_map.insert(ft::pair<int, int>(1, 3));
		my_map.insert(ft::pair<int, int>(40, 3));
		std::cout << my_map.at(4) << std::endl;

		for (ft::map<int, int>::iterator it = my_map.begin(); it != my_map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<int, int>::reverse_iterator it = my_map.rbegin(); it != my_map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}

		my_map.get_allocator();
	}
	std::cout << "Basic tests with string" << std::endl;
	{
		ft::map<std::string, std::string>	my_map;

		my_map.insert(ft::pair<std::string, std::string>("4", "3"));
		my_map.insert(ft::pair<std::string, std::string>("0", "3"));
		my_map.insert(ft::pair<std::string, std::string>("6", "3"));
		my_map.insert(ft::pair<std::string, std::string>("1", "3"));
		my_map.insert(ft::pair<std::string, std::string>("40", "3"));
		std::cout << my_map.at("4") << std::endl;

		for (ft::map<std::string, std::string>::iterator it = my_map.begin(); it != my_map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<std::string, std::string>::reverse_iterator it = my_map.rbegin(); it != my_map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}

		my_map.get_allocator();
	}
	std::cout << "Testing constructors" << std::endl;
	{
		std::cout << "Constructor with comparator" << std::endl;
		ft::map<std::string, std::string>	map1((std::less<std::string>()));
		for (ft::map<std::string, std::string>::iterator it = map1.begin(); it != map1.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<std::string, std::string>::reverse_iterator it = map1.rbegin(); it != map1.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	{
		std::cout << "Constructor with iterators" << std::endl;
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ?");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string>	map2(data, data + 4);

		for (ft::map<std::string, std::string>::iterator it = map2.begin(); it != map2.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}

		for (ft::map<std::string, std::string>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	{
		std::cout << "Constructor with copy" << std::endl;
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ?");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string>	map2(data, data + 4);

		ft::map<std::string, std::string>	map3(map2);

		for (ft::map<std::string, std::string>::iterator it = map3.begin(); it != map3.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}

		for (ft::map<std::string, std::string>::reverse_iterator it = map3.rbegin(); it != map3.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	std::cout << "Testing assignation" << std::endl;
	{
		std::cout << "Test 1" << std::endl;
		ft::map<std::string, std::string>	map;
		ft::map<std::string, std::string>	map2;

		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		map = map2;
		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<std::string, std::string>::iterator it = map2.begin(); it != map2.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	{
		std::cout << "Test 2" << std::endl;
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ?");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string>	map;
		ft::map<std::string, std::string>	map2(data, data + 4);

		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		map = map2;
		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<std::string, std::string>::iterator it = map2.begin(); it != map2.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	{
		std::cout << "Test 3" << std::endl;
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ?");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string>	map;
		ft::map<std::string, std::string>	map2(data, data + 4);

		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		map2 = map;
		for (ft::map<std::string, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		for (ft::map<std::string, std::string>::iterator it = map2.begin(); it != map2.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	std::cout << "Testing at()" << std::endl;
	{
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ? 2");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string>	map(data, data + 4);

		try
		{
			std::cout << map.at("Salut les copains") << std::endl;
			std::cout << map.at("Salins") << std::endl;
			std::cout << map.at("Salut lpains") << std::endl;
			std::cout << map.at("S") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at("pouet") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at("") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing at() with numbers" << std::endl;
	{
		ft::pair<int, int> data[4];

		data[0] = ft::make_pair(0, 2);
		data[1] = ft::make_pair(5, 502);
		data[2] = ft::make_pair(-3, 12);
		data[3] = ft::make_pair(33, -4);
		ft::map<int, int>	map(data, data + 4);

		try
		{
			std::cout << map.at(0) << std::endl;
			std::cout << map.at(5) << std::endl;
			std::cout << map.at(-3) << std::endl;
			std::cout << map.at(33) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(23) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(22) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing at() with mixed" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string>	map(data, data + 4);

		try
		{
			std::cout << map.at(0) << std::endl;
			std::cout << map.at(5) << std::endl;
			std::cout << map.at(-3) << std::endl;
			std::cout << map.at(33) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(23) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(22) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing at() const" << std::endl;
	{
		ft::pair<std::string, std::string> data[4];

		data[0] = ft::make_pair("Salut les copains", "ca va ?");
		data[1] = ft::make_pair("Salins", "ca va ? 2");
		data[2] = ft::make_pair("Salut lpains", "?");
		data[3] = ft::make_pair("S", "ca v");
		ft::map<std::string, std::string> const map(data, data + 4);

		try
		{
			std::cout << map.at("Salut les copains") << std::endl;
			std::cout << map.at("Salins") << std::endl;
			std::cout << map.at("Salut lpains") << std::endl;
			std::cout << map.at("S") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at("pouet") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at("") << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing at() const with numbers" << std::endl;
	{
		ft::pair<int, int> data[4];

		data[0] = ft::make_pair(0, 2);
		data[1] = ft::make_pair(5, 502);
		data[2] = ft::make_pair(-3, 12);
		data[3] = ft::make_pair(33, -4);
		ft::map<int, int> const map(data, data + 4);

		try
		{
			std::cout << map.at(0) << std::endl;
			std::cout << map.at(5) << std::endl;
			std::cout << map.at(-3) << std::endl;
			std::cout << map.at(33) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(23) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(22) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing at() const with mixed" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string> const map(data, data + 4);

		try
		{
			std::cout << map.at(0) << std::endl;
			std::cout << map.at(5) << std::endl;
			std::cout << map.at(-3) << std::endl;
			std::cout << map.at(33) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must not appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(23) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
		try
		{
			std::cout << map.at(22) << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "Index out of range ! This must appear !" << std::endl;
		}
	}
	std::cout << "Testing begin() iterator" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string> map(data, data + 4);
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing begin() iterator with empty map" << std::endl;
	{
		ft::map<int, std::string> map;
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing begin() const iterator" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string> const map(data, data + 4);
		for (ft::map<int, std::string>::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing begin() const iterator with empty map" << std::endl;
	{
		ft::map<int, std::string> const map;
		for (ft::map<int, std::string>::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing rbegin() iterator" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string> map(data, data + 4);
		for (ft::map<int, std::string>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing rbegin() iterator with empty map" << std::endl;
	{
		ft::map<int, std::string> map;
		for (ft::map<int, std::string>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing rbegin() const iterator" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");
		ft::map<int, std::string> const map(data, data + 4);
		for (ft::map<int, std::string>::const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing rbegin() const iterator with empty map" << std::endl;
	{
		ft::map<int, std::string> const map;
		for (ft::map<int, std::string>::const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
		}
	}
	std::cout << "Testing empty() and size() with empty map" << std::endl;
	{
		ft::map<int, std::string> map;
		std::cout << map.empty() << map.size() << std::endl;
	}
	std::cout << "Testing empty() and size() with map with one element" << std::endl;
	{
		ft::map<int, std::string> map;

		map.insert(ft::make_pair(0, "salut"));
		std::cout << map.empty() << map.size() << std::endl;
	}
	std::cout << "testing empty() and size() with map with many elements" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");

		ft::map<int, std::string> map(data, data + 4);
		map.insert(ft::make_pair(1, "salut"));
		std::cout << map.empty() << map.size() << std::endl;
	}
	std::cout << "testing empty() and size() with map with many elements inserted and removed" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");

		ft::map<int, std::string> map(data, data + 4);
		std::cout << map.empty() << map.size() << std::endl;
		map.insert(ft::make_pair(1, "salut"));
		std::cout << map.empty() << map.size() << std::endl;

		ft::pair<int, std::string> data2[4];
		data2[0] = ft::make_pair(12, "pouet");
		data2[1] = ft::make_pair(-2, "salut");
		data2[2] = ft::make_pair(15, "youpi");
		data2[3] = ft::make_pair(1, "top");
		map.insert(data2, data2 + 4);
		std::cout << map.empty() << map.size() << std::endl;
		map.erase(5);
		std::cout << map.empty() << map.size() << std::endl;
		map.erase(232);
		std::cout << map.empty() << map.size() << std::endl;
		map.erase(1);
		std::cout << map.empty() << map.size() << std::endl;
		ft::map<int, std::string>::iterator beg = map.begin();
		ft::map<int, std::string>::iterator end = map.end();
		end--;
		end--;
		end--;
		map.erase(beg, end);
		std::cout << map.empty() << map.size() << std::endl;
		map.erase(map.begin(), map.end());
		std::cout << map.empty() << map.size() << std::endl;
	}
	{
		ft::map<int, std::string> map;

		map.insert(ft::make_pair(0, "salut"));
		std::cout << (map.max_size() > 0) << std::endl; // Not useful to compare this to std one
	}
	std::cout << "Testing clear() with empty map" << std::endl;
	{
		ft::map<int, std::string> map;

		map.clear();
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		map.clear();
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	std::cout << "Testing clear() with one element" << std::endl;
	{
		ft::map<int, std::string> map;
		map.insert(ft::make_pair(4, "pouet"));
		map.clear();
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	std::cout << "Testing clear() with many elements inserted and removed" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");

		ft::map<int, std::string> map(data, data + 4);
		map.insert(ft::make_pair(1, "salut"));

		ft::pair<int, std::string> data2[4];
		data2[0] = ft::make_pair(12, "pouet");
		data2[1] = ft::make_pair(-2, "salut");
		data2[2] = ft::make_pair(15, "youpi");
		data2[3] = ft::make_pair(1, "top");
		map.insert(data2, data2 + 4);
		map.erase(5);
		map.erase(232);
		map.erase(1);
		ft::map<int, std::string>::iterator beg = map.begin();
		ft::map<int, std::string>::iterator end = map.end();
		end--;
		end--;
		end--;
		map.erase(beg, end);
		map.erase(map.begin(), map.end());
		map.clear();
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
	std::cout << "Testing clear(): many elements inserted and removed then clear() then inserted again" << std::endl;
	{
		ft::pair<int, std::string> data[4];

		data[0] = ft::make_pair(0, "pouet");
		data[1] = ft::make_pair(5, "salut");
		data[2] = ft::make_pair(-3, "youpi");
		data[3] = ft::make_pair(33, "top");

		ft::map<int, std::string> map(data, data + 4);
		map.insert(ft::make_pair(1, "salut"));

		ft::pair<int, std::string> data2[4];
		data2[0] = ft::make_pair(12, "pouet");
		data2[1] = ft::make_pair(-2, "salut");
		data2[2] = ft::make_pair(15, "youpi");
		data2[3] = ft::make_pair(1, "top");
		map.insert(data2, data2 + 4);
		map.erase(5);
		map.erase(232);
		map.erase(1);
		ft::map<int, std::string>::iterator beg = map.begin();
		ft::map<int, std::string>::iterator end = map.end();
		end--;
		end--;
		end--;
		map.erase(beg, end);
		map.erase(map.begin(), map.end());
		map.clear();
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
		map.insert(data, data + 4);
		map.insert(ft::make_pair(1, "salut"));
		map.insert(data2, data2 + 4);
		map.erase(5);
		map.erase(232);
		map.erase(1);
		beg = map.begin();
		end = map.end();
		end--;
		end--;
		end--;
		map.erase(beg, end);
		map.erase(map.begin(), map.end());
		for (ft::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << it->first << " - " << it->second << std::endl;
			std::cout << (*it).first << " - " << (*it).second << std::endl;
		}
	}
}
