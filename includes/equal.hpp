/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:11:19 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:13:14 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	template<class It1, class It2>
	bool equal(It1 first1, It1 last1, It2 first2);

	template<class It1, class It2, class BinaryPredicate>
	bool equal(It1 first1, It1 last1, It2 first2, BinaryPredicate p);

# include "equal.tpp"
}

#endif
