/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:42:49 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/20 16:55:10 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstdlib>

# include "lexicographical_compare.hpp"

template<typename T, typename TreeCompare>
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

				RBTreeNode	&operator=(RBTreeNode const &obj);

				RBTreeNode	*getUncle(void);
				bool		isLeftChild(void);
				bool		isRightChild(void);
				void		switchColor(void);
				void		leftRotate(void);
				void		rightRotate(void);
				RBTreeNode	*getMinNode();
				RBTreeNode	*getMaxNode();
				void		deleteTree();

				class iterator
				{
					private:
						RBTreeNode	*ptr;
						bool		isEnd;
					public:
						typedef std::ptrdiff_t difference_type;
						typedef T value_type;
						typedef T* pointer;
						typedef T& reference;
						typedef std::bidirectional_iterator_tag iterator_category;

						iterator();
						iterator(RBTreeNode *node, bool isEnd);
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
			friend class RBTree<T, TreeCompare>;
		};
	private:
		size_t		_size;
		RBTreeNode	*_root;
		TreeCompare	_comp;

		RBTree();
		RBTreeNode	*put(T elem);
		void		fixRBTree(RBTreeNode *node);
		void		fixRoot(void);
		void		transplant(RBTreeNode *oldNode, RBTreeNode *newNode);
		void		applyDeleteFix(RBTreeNode *node);
	public:
		RBTree(TreeCompare _comp);
		~RBTree(void);
		RBTree(RBTree const &obj);

		RBTree	&operator=(RBTree const &obj);

		size_t		_getSize(void) const;
		bool		_insert(T elem);
		bool		_remove(T elem);
		template<typename K>
		RBTreeNode	*_get(K key);
		RBTreeNode	*_getRoot(void);
		template<typename K>
		bool		_contains(K key);
};

template<typename T, typename TreeCompare>
bool operator==(const RBTree<T, TreeCompare> &lhs,
			 const RBTree<T, TreeCompare> &rhs);

template<typename T, typename TreeCompare>
bool operator!=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs );

template<typename T, typename TreeCompare>
bool operator<( const RBTree<T, TreeCompare>& lhs,
			const RBTree<T, TreeCompare>& rhs );

template<typename T, typename TreeCompare>
bool operator<=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs );

template<typename T, typename TreeCompare>
bool operator>( const RBTree<T, TreeCompare>& lhs,
			const RBTree<T, TreeCompare>& rhs );

template<typename T, typename TreeCompare>
bool operator>=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs );

template<typename T, typename TreeCompare>
void swap(RBTree<T, TreeCompare>& lhs, RBTree<T, TreeCompare>& rhs );

# include "RBTree.tpp"

#endif
