/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:29:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/22 12:50:17 by jmaia            ###   ###               */
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

template<class T, class Allocator>
vector<T, Allocator>::vector(size_type count, const T &value, const Allocator& alloc): _size(count),
			_allocator(alloc),
			_capacity(count)
{
	this->_array = this->_allocator.allocate(this->_capacity);
	std::fill(this->begin(), this->begin + this->_capacity, value);
}

template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &obj)
{
	*this = obj;
}

template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc): _allocator(alloc)
{
	this->_capacity = std::distance(first, last);
	this->_size = this->_capacity;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->insert(this->end(), first, last);
}

template<class T, class Allocator>
vector<T, Allocator>::~vector(void)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
}
