/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:01:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/20 16:47:04 by jmaia            ###   ###               */
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
}
