/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:25:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:36:33 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		using first_type = T1;
		using second_type = T2;

		T1	first;
		T2	second;

		pair(void);
		pair(const T1 &x, const T2 &y);
		template<typename U1, typename U2>
		pair(const pair<U1, U2> &p);

		pair &operator=(const pair& other);
	};
# include "pair.tpp"
}

#endif
