/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.tpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:20:02 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:25:02 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */


template<class It1, class It2>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2)
{
	for (; (first1 != last1) && (first2 != last2); first1++, first2++)
	{
		if (*first1 < *first2)
			return (true);
		if (*first2 < *first1)
			return (false);
	}
	return (first1 == last1) && (first2 != last2);
}

template<class It1, class It2, class Compare>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); first1++, first2++)
	{
		if (comp(*first1 < *first2))
			return (true);
		if (comp(*first2 < *first1))
			return (false);
	}
	return (first1 == last1) && (first2 != last2);
}
