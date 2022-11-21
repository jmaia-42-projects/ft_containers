/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:11:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 09:17:17 by jmaia            ###   ###               */
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
		public:
			typedef I iterator_type;
			typedef typename iterator_traits<I>::iterator_category iterator_category;
			typedef typename iterator_traits<I>::value_type value_type;
			typedef typename iterator_traits<I>::difference_type difference_type;
			typedef typename iterator_traits<I>::pointer pointer;
			typedef typename iterator_traits<I>::reference reference;
	};
}

#endif
