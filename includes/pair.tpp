/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:30:57 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:33:24 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<typename T1, typename T2>
pair<T1, T2>::pair(void) { }
template<typename T1, typename T2>
pair<T1, T2>::pair(const T1 &x, const T2 &y): first(x), second(y) {}
template<typename T1, typename T2>
template<typename U1, typename U2>
pair<T1, T2>::pair(const pair<U1, U2> &p)
{
	*this = p;
}
