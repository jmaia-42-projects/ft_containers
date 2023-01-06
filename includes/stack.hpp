/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:45:20 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/06 15:28:13 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template<class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack (const container_type& ctnr = container_type());
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();
		protected:
			container_type	c;

		template<class T2, class Container2>
		friend bool operator== (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

		template<class T2, class Container2>
		friend bool operator!= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

		template<class T2, class Container2>
		friend bool operator<  (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

		template<class T2, class Container2>
		friend bool operator<= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

		template<class T2, class Container2>
		friend bool operator>  (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

		template<class T2, class Container2>
		friend bool operator>= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

# include "stack.tpp"
}

#endif
