/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:42:49 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/09 18:08:57 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstdlib>

template<typename T>
class	RBTree
{
	public:
		struct RBTreeNode
		{
			enum color {RED, BLACK};

			private:
				RBTreeNode(void);
			public:
				T			content;
				RBTreeNode	*left;
				RBTreeNode	*right;
				RBTreeNode	*parent;
				enum color	color;

				RBTreeNode(T value, enum color color);
				RBTreeNode(RBTreeNode const &obj);
				~RBTreeNode(void);

				bool	operator=(RBTreeNode const &obj);

				bool	operator==(RBTreeNode const &obj);
				bool	operator<(RBTreeNode const &obj);
				bool	operator<=(RBTreeNode const &obj);
				bool	operator>(RBTreeNode const &obj);
				bool	operator>=(RBTreeNode const &obj);
				bool	operator!=(RBTreeNode const &obj);

				RBTreeNode	*getUncle(void);
				bool		isLeftChild(void);
				bool		isRightChild(void);
				void		switchColor(void);
				void		leftRotate(void);
				void		rightRotate(void);
				RBTreeNode	*getMinNode();
				RBTreeNode	*getMaxNode();

				class iterator
				{
					private:
						RBTreeNode	*ptr;
					public:
						typedef std::ptrdiff_t difference_type;
						typedef RBTreeNode value_type;
						typedef RBTreeNode* pointer;
						typedef RBTreeNode& reference;
						typedef std::bidirectional_iterator_tag iterator_category;

						iterator();
						iterator(RBTreeNode *node);
						iterator(iterator const &obj);
						~iterator();

						iterator &operator=(iterator const &obj);

						reference	operator*();
						pointer		operator->();
						iterator	&operator++();
						iterator	operator++(int);
						iterator	&operator--();
						iterator	operator--(int);
						bool		operator==(iterator const &it);
						bool		operator!=(iterator const &it);
				};
			friend class RBTree<T>;
		};
	private:
		size_t		_size;
		RBTreeNode	*_root;

		RBTreeNode	*put(T elem);
		void		fixRBTree(RBTreeNode *node);
		void		fixRoot(void);
		void		transplant(RBTreeNode *oldNode, RBTreeNode *newNode);
		void		applyDeleteFix(RBTreeNode *node);
	protected:
		RBTree(void);
		~RBTree(void);
		RBTree(RBTree const &obj);

		RBTree	&operator=(RBTree const &obj);

		size_t		getSize(void) const;
		bool		insert(T elem);
		bool		remove(T elem);
		T			contains(void);
		template<typename K>
		RBTreeNode	*get(K key);
		template<typename K>
		bool		contains(K key);
};

# include "RBTree.tpp"

#endif
