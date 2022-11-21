/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:11:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 10:09:23 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template<typename I>
	class reverse_iterator
	{
		protected:
			I current;
		public:
			typedef I iterator_type;
			typedef typename iterator_traits<I>::iterator_category iterator_category;
			typedef typename iterator_traits<I>::value_type value_type;
			typedef typename iterator_traits<I>::difference_type difference_type;
			typedef typename iterator_traits<I>::pointer pointer;
			typedef typename iterator_traits<I>::reference reference;

			reverse_iterator(void);
			explicit reverse_iterator(iterator_type x);
			template<class U>
			reverse_iterator(const reverse_iterator<U> &other);

			template<class U>
			reverse_iterator &operator=(const reverse_iterator<U> &other);

			iterator_type base(void) const;

			reference operator*(void) const;
			pointer operator->(void) const;

			reference operator[](difference_type n) const;

			reverse_iterator &operator++(void);
			reverse_iterator operator++(int _);
			reverse_iterator &operator--(void);
			reverse_iterator operator--(int _);
			reverse_iterator operator+(difference_type n) const;
			reverse_iterator operator-(difference_type n) const;
			reverse_iterator &operator+=(difference_type n);
			reverse_iterator &operator-=(difference_type n);
	};

# include "reverse_iterator.tpp"
}

#endif
