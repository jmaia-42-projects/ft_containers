/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:01:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/20 13:58:13 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifdef FT
# include "map.hpp"
#else
# include <map>
namespace ft = std;
#endif

int	main(void)
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

	my_map.get_allocator();
}
