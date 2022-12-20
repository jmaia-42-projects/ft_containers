/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:30:57 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/20 16:57:07 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<typename T1, typename T2>
pair<T1, T2>::pair(void) { }
template<typename T1, typename T2>
pair<T1, T2>::pair(const T1 &x, const T2 &y): first(x), second(y) {}
template<typename T1, typename T2>
template<typename U1, typename U2>
pair<T1, T2>::pair(const pair<U1, U2> &p):
	first(p.first),
	second(p.second) {}

template<typename T1, typename T2>
pair<T1, T2>::pair(const pair<T1, T2> &p):
	first(p.first),
	second(p.second) {}

template<typename T1, typename T2>
pair<T1, T2> &pair<T1, T2>::operator=(const pair<T1, T2>& other)
{
	this->first = other.first;
	this->second = other.second;
	return (*this);
}

template<class T1, class T2>
pair<T1, T2> make_pair(T1 t, T2 u)
{
	return (pair<T1, T2>(t, u));
}

template<class T1, class T2>
pair<T1, T2> make_pair(T1 t, T2 u);

template<class T1, class T2>
bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template<class T1, class T2>
bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (!(lhs == rhs));
}

template<class T1, class T2>
bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
}

template<class T1, class T2>
bool operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (lhs == rhs || lhs < rhs);
}

template<class T1, class T2>
bool operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (lhs != rhs && !(lhs < rhs));
}

template<class T1, class T2>
bool operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
{
	return (!(lhs < rhs));
}
