/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:11:50 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/06 15:20:27 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class T, class Container>
stack<T, Container>::stack (const stack::container_type& ctnr):
	c(ctnr) {}

template<class T, class Container>
bool stack<T, Container>::empty() const
{
	return (this->c.empty());
}

template<class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const
{
	return (this->c.size());
}

template<class T, class Container>
typename stack<T, Container>::value_type& stack<T, Container>::top()
{
	return (this->c.back());
}

template<class T, class Container>
const typename stack<T, Container>::value_type& stack<T, Container>::top() const
{
	return (this->c.back());
}

template<class T, class Container>
void stack<T, Container>::push (const stack::value_type& val)
{
	this->c.push_back(val);
}

template<class T, class Container>
void stack<T, Container>::pop()
{
	this->c.pop_back();
}

template <class T, class Container>
bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <class T, class Container>
bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c != rhs.c);
}

template <class T, class Container>
bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <class T, class Container>
bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c <= rhs.c);
}

template <class T, class Container>
bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c > rhs.c);
}

template <class T, class Container>
bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
{
	return (lhs.c >= rhs.c);
}
