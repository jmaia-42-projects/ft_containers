/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:26 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:17:03 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class It1, class It2>
bool equal(It1 first1, It1 last1, It2 first2)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (!(*first1 == *first2))
			return (false);
	}
	return (true);
}

template<class It1, class It2, class BinaryPredicate>
bool equal(It1 first1, It1 last1, It2 first2, BinaryPredicate p)
{
	for (; first1 != last1; first1++, first2++)
	{
		if (!p(first1, first2))
			return (false);
	}
	return (true);

}
