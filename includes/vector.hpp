/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:12:48 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/03 20:28:30 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template<class T>
	class vector
	{
		using value_type = T;
		using allocator_type = std::allocator<value_type>;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = std::allocator<value_type>::pointer;
		using const_pointer = std::allocator<value_type>::const_pointer;
		using iterator = vectorIterator<value_type>;
		using const_iterator = vectorIterator<const value_type>; // A bit weird
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
		public:
			vector(void);
			vector(const vector &obj);
			~vector(void);

			vector	&operator=(const vector *obj);
			void	assign(size_type count, const T &value);

			template<class InputIt>
			void	assign(InputIt first, InputIt last);

			std::allocator<T>	get_allocator(void) const;

			/* Element access */
			T		&at(size_type pos);
			const T	&at(size_type pos) const;
			T		&operator[](size_type pos);
			const T	&operator[](size_type pos) const;
			T		&front(void);
			const T	&front(void) const;
			T		&back(void);
			const T &back(void) const;
			T		*data(void);
			const T	*data(void) const;

			/* Iterators */
			// TODO

			/* Capacity */
			bool	empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;
			void	reserve(size_type new_cap);
			size_type	capacity(void) const;

			/* Modifiers */
			void	clear(void);
			// TODO Add insert prototypes function here. Need iterator
			// TODO Add erase prototypes function here. Need iterator
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
}

#endif
