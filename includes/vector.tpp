/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:29:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/22 11:51:57 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class T, class Allocator>
vector<T, Allocator>::vector(void): _size(0),
					_array(NULL),
					_allocator(Allocator()),
					_capacity(0) { }

template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc): _size(0),
					_array(NULL),
					_allocator(alloc),
					_capacity(0) { }
