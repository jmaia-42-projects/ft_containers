/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:22:17 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 14:17:39 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

//# include <functional>
//# include <memory>
//
# include "pair.hpp"
# include "RBTree.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:
			typedef T key_type;
			typedef T value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Compare value_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename RBTree<T, value_compare, Allocator>::RBTreeNode::const_iterator iterator;
			typedef typename RBTree<T, value_compare, Allocator>::RBTreeNode::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		private:
			Allocator										_allocator;
			Compare											_compare;
			RBTree<T, value_compare, Allocator>	_tree;
		public:
			set();
			explicit set(const Compare &comp, const Allocator &alloc = Allocator());
			template<class InputIt>
			set(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			set(const set &other);
			~set();

			set &operator=(const set &other);

			allocator_type get_allocator() const;

			/* Iterators */
			iterator begin() const;
			iterator end() const;
			reverse_iterator rbegin() const;
			reverse_iterator rend() const;

			/* Capacity */
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

			/* Modifiers */
			void clear();
			ft::pair<iterator, bool> insert(const value_type &value);
			iterator insert(iterator pos, const value_type &value);
			template<class InputIt>
			void insert(InputIt first, InputIt last);
			void erase(iterator pos);
			void erase(iterator first, iterator last);
			size_type erase(const value_type &val);
			void swap(set &other);

			/* Lookup */
			size_type count(const value_type &val) const;
			iterator find(const value_type &val) const;
			ft::pair<iterator, iterator> equal_range(const value_type &val) const;
			iterator lower_bound(const value_type &val) const;
			iterator upper_bound(const value_type &val) const;

			/* Observers */
			key_compare key_comp() const;
			value_compare value_comp() const;
	};

	template<class T, class Compare, class Alloc>
	bool operator==(const ft::set<T, Compare, Alloc> &lhs,
                 const ft::set<T, Compare, Alloc> &rhs);

	template< class T, class Compare, class Alloc >
	bool operator!=( const ft::set<T,Compare,Alloc>& lhs,
                 const ft::set<T,Compare,Alloc>& rhs );

	template< class T, class Compare, class Alloc >
	bool operator<( const ft::set<T,Compare,Alloc>& lhs,
                const ft::set<T,Compare,Alloc>& rhs );

	template< class T, class Compare, class Alloc >
	bool operator<=( const ft::set<T,Compare,Alloc>& lhs,
                 const ft::set<T,Compare,Alloc>& rhs );

	template< class T, class Compare, class Alloc >
	bool operator>( const ft::set<T,Compare,Alloc>& lhs,
                const ft::set<T,Compare,Alloc>& rhs );

	template< class T, class Compare, class Alloc >
	bool operator>=( const ft::set<T,Compare,Alloc>& lhs,
                 const ft::set<T,Compare,Alloc>& rhs );

	template< class T, class Compare, class Alloc >
	void swap(ft::set<T,Compare,Alloc>& lhs,
			   ft::set<T,Compare,Alloc>& rhs );

# include "set.tpp"
}

#endif
