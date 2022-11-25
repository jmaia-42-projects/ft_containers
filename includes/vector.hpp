/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:12:48 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/25 14:33:46 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "enable_if.hpp"
# include "is_integral.hpp"
# include "reverse_iterator.hpp"


# include <algorithm>
# include <iterator>
# include <stdexcept>

# include "lexicographical_compare.hpp"

# define VEC_EXPAND_SIZE 50

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef T* iterator;
			typedef T const * const_iterator;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;

			vector(void);
			explicit vector(const Allocator &alloc);
			explicit vector(size_type count, const T &value = T(), const Allocator& alloc = Allocator());
			vector(const vector<T, Allocator> &obj);
			template<class InputIt>
			vector(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator& alloc = Allocator());
			~vector(void);

			vector<T, Allocator>	&operator=(const vector<T, Allocator> &obj);
			void	assign(size_type count, const T &value);
			template<class InputIt>
			void	assign(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last);

			allocator_type	get_allocator(void) const;

			/* Element access */
			reference		at(size_type pos);
			const_reference	at(size_type pos) const;
			reference		operator[](size_type pos);
			const_reference	operator[](size_type pos) const;
			reference		front(void);
			const_reference	front(void) const;
			reference		back(void);
			const_reference	back(void) const;
			T				*data(void);
			const T			*data(void) const;

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
			bool	empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;
			void	reserve(size_type new_cap);
			size_type	capacity(void) const;

			/* Modifiers */
			void	clear(void);
			iterator insert(const_iterator pos, const T &value);
			iterator insert(const_iterator pos, size_type count, const T &value);
			template<class InputIt>
			iterator insert(const_iterator pos, typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last);
			iterator erase(iterator pos);
			iterator erase(iterator first, iterator last);
			void	push_back(const T &value);
			void	pop_back(void);
			void	resize(size_type count, T value = T());
			void	swap(vector<T, Allocator> &obj);
		private:
			Allocator	_allocator;
			T			*_array;
			size_type	_capacity;
			size_type	_size;

			void	shiftRight(const_iterator &it, size_type n);
			void	shiftLeft(const_iterator it, size_type n);
	};

	/* Operators */
	template<class T, class Allocator>
	bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template<class T, class Allocator>
	bool operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template<class T, class Allocator>
	bool operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template<class T, class Allocator>
	bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template<class T, class Allocator>
	bool operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);

	template<class T, class Allocator>
	bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs);


	template<class T, class Allocator>
	void swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs);

	template<class T>
	void	swap(T &a, T &b);

# include "vector.tpp"
}

#endif
