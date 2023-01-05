/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:22:17 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 13:37:08 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>

# include "pair.hpp"
# include "RBTree.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			class value_compare;

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const Key, T> value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename RBTree<value_type, value_compare, Allocator>::RBTreeNode::iterator iterator;
			typedef typename RBTree<value_type, value_compare, Allocator>::RBTreeNode::const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		private:
			Allocator										_allocator;
			Compare											_compare;
			RBTree<value_type, value_compare, Allocator>	_tree;
		public:
			map();
			explicit map(const Compare &comp, const Allocator &alloc = Allocator());
			template<class InputIt>
			map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			map(const map &other);
			~map();

			map &operator=(const map &other);

			allocator_type get_allocator() const;

			/* Element access */
			T &at(const Key &key);
			const T &at(const Key &key) const;
			T &operator[](const Key &key);

			/* Iterators */
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

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
			size_type erase(const Key &key);
			void swap(map &other);

			/* Lookup */
			size_type count(const Key &key) const;
			iterator find(const Key &key);
			const_iterator find(const Key &key) const;
			ft::pair<iterator, iterator> equal_range(const Key &key);
			ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const;
			iterator lower_bound(const Key &key);
			const_iterator lower_bound(const Key &key) const;
			iterator upper_bound(const Key &key);
			const_iterator upper_bound(const Key &key) const;

			/* Observers */
			key_compare key_comp() const;
			ft::map<Key, T, Compare, Allocator>::value_compare value_comp() const;

			class value_compare
			{
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					value_compare(Compare c);
					bool operator()(const value_type& lhs, const value_type& rhs) const;
				protected:
					Compare comp;
			};
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
                 const ft::map<Key, T, Compare, Alloc> &rhs);

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	void swap(ft::map<Key,T,Compare,Alloc>& lhs,
			   ft::map<Key,T,Compare,Alloc>& rhs );

# include "map.tpp"
}

#endif
