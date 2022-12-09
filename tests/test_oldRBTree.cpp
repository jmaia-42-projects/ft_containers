/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_oldRBTree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:12:51 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/06 17:31:20 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <algorithm>

#include "RBTree.hpp"

void	printTree(RBTree<int>::RBTreeNode *node, int depth)
{
	if (!node)
		std::cout << "NULL" << ": BLACK" << std::endl;
	else
	{
		std::cout << node->content << ": " << (node->color == RBTree<int>::RBTreeNode::BLACK ? "BLACK" : "RED") << std::endl;
		for (int i = 0; i < depth + 1; i++)
			std::cout << " ";
		std::cout << "Left : ";
		printTree(node->left, depth + 1);
		for (int i = 0; i < depth + 1; i++)
			std::cout << " ";
		std::cout << "Right : ";
		printTree(node->right, depth + 1);
	}
}

int	main(void)
{
	RBTree<int>	tree;
	std::vector<int> vec;

	srand(time(0));
	vec.push_back(786);
	vec.push_back(122);
	vec.push_back(593);
	vec.push_back(567);
	vec.push_back(398);
	vec.push_back(504);
	vec.push_back(874);
	vec.push_back(613);
	vec.push_back(734);
	vec.push_back(533);
	for (int i = 0; i < 10; i++)
	{
//		int	nbr = rand() % 1000;
//		vec.push_back(nbr);
		tree.insert(vec[i]);
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int>	deletingOrder;
	deletingOrder.push_back(1);
	deletingOrder.push_back(0);
	deletingOrder.push_back(0);
	printTree(tree._root, 0);
	std::cout << std::endl;
	for (int i = 0; i < 3; i++)
	{
//		int	r_index = rand() % vec.size();
//		std::cout << "hello, deleting index " << r_index << " with value " << vec[r_index] << std::endl;
//		tree.remove(vec[r_index]);
//		vec.erase(vec.begin() + r_index);
		tree.remove(vec[deletingOrder[i]]);
		vec.erase(vec.begin() + deletingOrder[i]);
		printTree(tree._root, 0);
		std::cout << std::endl;
	}
//	printTree(tree._root, 0);
}
