/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:35:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 11:04:33 by jmaia            ###   ###               */
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

template<typename I>
template<class U>
reverse_iterator<I> &reverse_iterator<I>::operator=(const reverse_iterator<U> &other)
{
	this->current = other.base();
	return (*this);
}

template<typename I>
typename reverse_iterator<I>::iterator_type reverse_iterator<I>::base(void) const
{
	return (this->current);
}

template<typename I>
typename reverse_iterator<I>::reference reverse_iterator<I>::operator*(void) const
{
	return (*(this->current - 1));
}

template<typename I>
typename reverse_iterator<I>::pointer reverse_iterator<I>::operator->(void) const
{
	return (this->current - 1);
}

template<typename I>
typename reverse_iterator<I>::reference reverse_iterator<I>::operator[](difference_type n) const
{
	return (this->base[-n - 1]);
}

template<typename I>
reverse_iterator<I> &reverse_iterator<I>::operator++(void)
{
	--this->current;
	return (*this);
}

template<typename I>
reverse_iterator<I> reverse_iterator<I>::operator++(int _)
{
	reverse_iterator tmp = *this;
	++(*this);
	return (tmp);
}

template<typename I>
reverse_iterator<I> &reverse_iterator<I>::operator--(void)
{
	++this->current;
	return (*this);
}

template<typename I>
reverse_iterator<I> reverse_iterator<I>::operator--(int _)
{
	reverse_iterator tmp = *this;
	--(*this);
	return (tmp);
}

template<typename I>
reverse_iterator<I> reverse_iterator<I>::operator+(difference_type n) const
{
	return (reverse_iterator(base() - n));
}

template<typename I>
reverse_iterator<I> reverse_iterator<I>::operator-(difference_type n) const
{
	return (reverse_iterator(base() + n));
}

template<typename I>
reverse_iterator<I> &reverse_iterator<I>::operator+=(difference_type n)
{
	this->current -= n;
	return (*this);
}

template<typename I>
reverse_iterator<I> &reverse_iterator<I>::operator-=(difference_type n)
{
	this->current += n;
	return (*this);
}

template<class It1, class It2>
bool operator==(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template<class It1, class It2>
bool operator!=(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template<class It1, class It2>
bool operator<(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template<class It1, class It2>
bool operator<=(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template<class It1, class It2>
bool operator>(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template<class It1, class It2>
bool operator>=(const reverse_iterator<It1>& lhs,
				const reverse_iterator<It2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template<class It>
reverse_iterator<It> operator+(typename reverse_iterator<It>::difference_type n,
								const reverse_iterator<It>& it)
{
	return (reverse_iterator<It>(it.base() - n));
}

template<class It1, class It2>
typename reverse_iterator<It1>::difference_type operator-(const reverse_iterator<It1>& lhs,
														const reverse_iterator<It2>& rhs)
{
	return (rhs.base() - lhs.base());
}