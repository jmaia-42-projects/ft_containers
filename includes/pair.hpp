/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:25:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/22 16:34:40 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1	first;
		T2	second;

		pair(void);
		pair(const T1 &x, const T2 &y);
		template<typename U1, typename U2>
		pair(const pair<U1, U2> &p);

		pair &operator=(const pair& other);
	};

	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u);

	template<class T1, class T2>
	bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);
	template<class T1, class T2>
	bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);
	template<class T1, class T2>
	bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);
	template<class T1, class T2>
	bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);
	template<class T1, class T2>
	bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);
	template<class T1, class T2>
	bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs);

# include "pair.tpp"
}

#endif
