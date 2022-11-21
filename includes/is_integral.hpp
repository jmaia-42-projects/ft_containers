/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:24:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/21 12:08:11 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <cstdint>

# include "integral_constant.hpp"

namespace ft
{
	template<typename T>
	struct is_integral: integral_constant<bool, false> {};

	template<> struct is_integral<bool>: true_type {};
	template<> struct is_integral<char>: true_type {};
	template<> struct is_integral<char16_t>: true_type {};
	template<> struct is_integral<char32_t>: true_type {};
	template<> struct is_integral<wchar_t>: true_type {};
	template<> struct is_integral<signed char>: true_type {};
	template<> struct is_integral<short>: true_type {};
	template<> struct is_integral<int>: true_type {};
	template<> struct is_integral<long>: true_type {};
	template<> struct is_integral<long long>: true_type {};
	template<> struct is_integral<unsigned char>: true_type {};
	template<> struct is_integral<unsigned short>: true_type {};
	template<> struct is_integral<unsigned int>: true_type {};
	template<> struct is_integral<unsigned long>: true_type {};
	template<> struct is_integral<unsigned long long>: true_type {};

	template<> struct is_integral<bool const>: true_type {};
	template<> struct is_integral<char const>: true_type {};
	template<> struct is_integral<char16_t const>: true_type {};
	template<> struct is_integral<char32_t const>: true_type {};
	template<> struct is_integral<wchar_t const>: true_type {};
	template<> struct is_integral<signed char const>: true_type {};
	template<> struct is_integral<short const>: true_type {};
	template<> struct is_integral<int const>: true_type {};
	template<> struct is_integral<long const>: true_type {};
	template<> struct is_integral<long long const>: true_type {};
	template<> struct is_integral<unsigned char const>: true_type {};
	template<> struct is_integral<unsigned short const>: true_type {};
	template<> struct is_integral<unsigned int const>: true_type {};
	template<> struct is_integral<unsigned long const>: true_type {};
	template<> struct is_integral<unsigned long long const>: true_type {};

	template<> struct is_integral<bool volatile>: true_type {};
	template<> struct is_integral<char volatile>: true_type {};
	template<> struct is_integral<char16_t volatile>: true_type {};
	template<> struct is_integral<char32_t volatile>: true_type {};
	template<> struct is_integral<wchar_t volatile>: true_type {};
	template<> struct is_integral<signed char volatile>: true_type {};
	template<> struct is_integral<short volatile>: true_type {};
	template<> struct is_integral<int volatile>: true_type {};
	template<> struct is_integral<long volatile>: true_type {};
	template<> struct is_integral<long long volatile>: true_type {};
	template<> struct is_integral<unsigned char volatile>: true_type {};
	template<> struct is_integral<unsigned short volatile>: true_type {};
	template<> struct is_integral<unsigned int volatile>: true_type {};
	template<> struct is_integral<unsigned long volatile>: true_type {};
	template<> struct is_integral<unsigned long long volatile>: true_type {};

	template<> struct is_integral<bool const volatile>: true_type {};
	template<> struct is_integral<char const volatile>: true_type {};
	template<> struct is_integral<char16_t const volatile>: true_type {};
	template<> struct is_integral<char32_t const volatile>: true_type {};
	template<> struct is_integral<wchar_t const volatile>: true_type {};
	template<> struct is_integral<signed char const volatile>: true_type {};
	template<> struct is_integral<short const volatile>: true_type {};
	template<> struct is_integral<int const volatile>: true_type {};
	template<> struct is_integral<long const volatile>: true_type {};
	template<> struct is_integral<long long const volatile>: true_type {};
	template<> struct is_integral<unsigned char const volatile>: true_type {};
	template<> struct is_integral<unsigned short const volatile>: true_type {};
	template<> struct is_integral<unsigned int const volatile>: true_type {};
	template<> struct is_integral<unsigned long const volatile>: true_type {};
	template<> struct is_integral<unsigned long long const volatile>: true_type {};
}

#endif
