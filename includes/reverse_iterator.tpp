/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:35:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 09:40:25 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<typename I>
reverse_iterator<I>::reverse_iterator(void): current() { }

template<typename I>
reverse_iterator<I>::reverse_iterator(iterator_type x): current(x) { }

template<typename I>
template<class U>
reverse_iterator<I>::reverse_iterator(const reverse_iterator<U> &other)
{
	*this = other;
}
