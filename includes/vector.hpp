/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:12:48 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/22 13:54:42 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

# include "reverse_iterator.hpp"


# include <algorithm>
# include <stdexcept>

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
	class vector
	{
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = typename Allocator::pointer;
		using const_pointer = typename Allocator::const_pointer;
		using iterator = T*;
		using const_iterator = T const *;
		using const_reverse_iterator = reverse_iterator<const_iterator>;
		using reverse_iterator = reverse_iterator<iterator>;

		private:
			Allocator	_allocator;
			T			*_array;
			size_type	_capacity;
			size_type	_size;

		public:
			vector(void);
			explicit vector(const Allocator &alloc);
			explicit vector(size_type count, const T &value = T(), const Allocator& alloc = Allocator());
			vector(const vector &obj);
			template<class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
			~vector(void);

			vector	&operator=(const vector &obj);
			void	assign(size_type count, const T &value);
			template<class InputIt>
			void	assign(InputIt first, InputIt last);

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
			constexpr iterator insert(const_iterator pos, size_type count, const T &value);
			template<class InputIt>
			iterator insert(const_iterator pos, InputIt first, InputIt last);
			iterator erase(iterator pos);
			iterator erase(iterator first, iterator last);
			void	push_back(const T &value);
			void	pop_back(void);
			void	resize(size_type count, T value = T());
			void	swap(vector &obj);
	};

	/* Operators */
	template<class T>
	bool operator==(const vector<T> &lhs, const vector<T> &rhs);

	template<class T>
	bool operator!=(const vector<T> &lhs, const vector<T> &rhs);

	template<class T>
	bool operator<(const vector<T> &lhs, const vector<T> &rhs);

	template<class T>
	bool operator<=(const vector<T> &lhs, const vector<T> &rhs);

	template<class T>
	bool operator>(const vector<T> &lhs, const vector<T> &rhs);

	template<class T>
	bool operator>=(const vector<T> &lhs, const vector<T> &rhs);


	template<class T>
	void swap(vector<T> &lhs, vector<T> &rhs);

# include "vector.tpp"
}

#endif
