/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:43:18 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 11:53:05 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

namespace ft
{
	template<class T, T v>
	struct integral_constant
	{
		static constexpr T value = v;
		using value_type = T;
		using type = integral_constant;
		constexpr operator value_type() const noexcept { return value; };
	};

	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
}

#endif
