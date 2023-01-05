/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:42:49 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 14:20:32 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstdlib>

# include "lexicographical_compare.hpp"

template<typename T, typename TreeCompare, typename Alloc>
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
				typename Alloc::template rebind<RBTreeNode>::other alloc;

				RBTreeNode(T value, enum color color, Alloc alloc);
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

				class iterator;

				class const_iterator
				{
					private:
						RBTreeNode const	*ptr;
						bool				isEnd;
						friend class iterator;

					public:
						typedef std::ptrdiff_t difference_type;
						typedef T const value_type;
						typedef T const * pointer;
						typedef T const & reference;
						typedef std::bidirectional_iterator_tag iterator_category;

						const_iterator();
						const_iterator(RBTreeNode const *node, bool isEnd);
						const_iterator(const_iterator const &obj);
						const_iterator(iterator const &obj);
						~const_iterator();

						const_iterator &operator=(const_iterator const &obj);

						reference	operator*() const;
						pointer		operator->() const;
						const_iterator	&operator++();
						const_iterator	operator++(int);
						const_iterator	&operator--();
						const_iterator	operator--(int);

						bool	operator==(const_iterator const &rhs) const;
						bool	operator!=(const_iterator const &rhs) const;
				};

				class iterator
				{
					private:
						RBTreeNode	*ptr;
						bool		isEnd;

						friend class const_iterator;
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

						reference	operator*() const;
						pointer		operator->() const;
						iterator	&operator++();
						iterator	operator++(int);
						iterator	&operator--();
						iterator	operator--(int);

						bool	operator==(const_iterator const &rhs) const;
						bool	operator!=(const_iterator const &rhs) const;
				};

			friend class RBTree<T, TreeCompare, Alloc>;
		};
	private:
		size_t								_size;
		RBTreeNode							*_root;
		TreeCompare							_comp;
		typename Alloc::template rebind<RBTreeNode>::other	_alloc;

		RBTree();
		RBTreeNode	*put(T elem);
		void		fixRBTree(RBTreeNode *node);
		void		fixRoot(void);
		void		transplant(RBTreeNode *oldNode, RBTreeNode *newNode);
		void		applyDeleteFix(RBTreeNode *node);
	public:
		RBTree(TreeCompare _comp, Alloc alloc);
		~RBTree(void);
		RBTree(RBTree const &obj);

		RBTree	&operator=(RBTree const &obj);

		size_t		_getSize(void) const;
		bool		_insert(T elem);
		bool		_remove(T elem);
		template<typename K>
		RBTreeNode	*_get(K key) const;
		RBTreeNode	*_getRoot(void) const;
		template<typename K>
		bool		_contains(K key) const;
		void		empty(void);
		void		swap(RBTree &other);
};

template<typename T, typename TreeCompare, typename Alloc>
bool operator==(const RBTree<T, TreeCompare, Alloc> &lhs,
			 const RBTree<T, TreeCompare, Alloc> &rhs);

template<typename T, typename TreeCompare, typename Alloc>
bool operator!=( const RBTree<T, TreeCompare, Alloc>& lhs,
			 const RBTree<T, TreeCompare, Alloc>& rhs );

template<typename T, typename TreeCompare, typename Alloc>
bool operator<( const RBTree<T, TreeCompare, Alloc>& lhs,
			const RBTree<T, TreeCompare, Alloc>& rhs );

template<typename T, typename TreeCompare, typename Alloc>
bool operator<=( const RBTree<T, TreeCompare, Alloc>& lhs,
			 const RBTree<T, TreeCompare, Alloc>& rhs );

template<typename T, typename TreeCompare, typename Alloc>
bool operator>( const RBTree<T, TreeCompare, Alloc>& lhs,
			const RBTree<T, TreeCompare, Alloc>& rhs );

template<typename T, typename TreeCompare, typename Alloc>
bool operator>=( const RBTree<T, TreeCompare, Alloc>& lhs,
			 const RBTree<T, TreeCompare, Alloc>& rhs );

template<typename T, typename TreeCompare, typename Alloc>
void swap(RBTree<T, TreeCompare, Alloc>& lhs, RBTree<T, TreeCompare, Alloc>& rhs );

# include "RBTree.tpp"

#endif
