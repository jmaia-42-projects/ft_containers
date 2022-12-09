/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_RBTree.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:41:02 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/09 14:18:05 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "RBTree.hpp"

void	printTree(RBTree<int>::RBTreeNode *node, int depth)
{
	if (!node)
		return ;
	std::cout << node->content << " " << (node->color == RBTree<int>::RBTreeNode::BLACK ? "BLACK" : "RED") << std::endl;
	for (int i = 0; i < depth; i++)
		std::cout << "	";
	std::cout << "LEFT: ";
	if (node->left)
		printTree(node->left, depth + 1);
	else
		std::cout << "NULL BLACK" << std::endl;
	for (int i = 0; i < depth; i++)
		std::cout << "	";
	std::cout << "RIGHT: ";
	if (node->right)
		printTree(node->right, depth + 1);
	else
		std::cout << "NULL BLACK" << std::endl;
}

int	main(void)
{
//	unsigned long seed = time(NULL);
	unsigned long seed = 1670519656;
//	unsigned long seed = 1670441658; // Bug with 10 insert and 10 remove
//	unsigned long seed = 1670438921; // Bug with 4 insert and 1 remove
//	unsigned long seed = 1670430283; // Bug with 10 insert and 3 remove
	srand(seed);

	std::cout << "Seed: " << seed << std::endl;
	std::vector<int>	nbrs;
	RBTree<int>			tree;
	for (int i = 0; i < 10; i++)
	{
		int	nbr = rand() % 200;
		nbrs.push_back(nbr);
		tree.insert(nbr);
	}
	for (int i = 0; i < 10; i++)
	{
		int	index = rand() % nbrs.size();
		std::cout << "Removing " << nbrs[index] << std::endl;
		tree.remove(nbrs[index]);
		nbrs.erase(nbrs.begin() + index);
		std::cout << "Size after erasing: " << tree.getSize() << std::endl;
		std::cout << std::endl;
	}
}
