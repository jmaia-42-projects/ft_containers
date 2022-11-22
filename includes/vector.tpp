/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:29:50 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/22 13:46:38 by jmaia            ###   ###               */
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
	std::fill(this->begin(), this->begin() + this->_capacity, value);
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
	this->_size = 0;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->insert(this->end(), first, last);
}

template<class T, class Allocator>
vector<T, Allocator>::~vector(void)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
}

template<class T, class Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=(const vector &obj)
{
	this->_array.deallocate(this->_array, this->_capacity);
	this->_allocator = allocator_type(obj._allocator);
	this->_capacity = obj._capacity;
	this->_size = 0;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->insert(this->end(), obj.begin(), obj.end());
	return (*this);
}

template<class T, class Allocator>
void	vector<T, Allocator>::assign(size_type count, const T &value)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_capacity = count;
	this->_size = count;
	this->_array = this->_alocator.allocate(this->_capacity);
	std::fill(this->begin(), this->begin() + this->_size, value);
}

template<class T, class Allocator>
template<class InputIt>
void	vector<T, Allocator>::assign(InputIt first, InputIt last)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_size = std::distance(first, last);
	this->_capacity = this->_size;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->insert(this->end(), first, last);
}

template<class T, class Allocator>
typename vector<T, Allocator>::allocator_type	vector<T, Allocator>::get_allocator(void) const
{
	return (this->_allocator);
}

template<class T, class Allocator>
typename vector<T, Allocator>::reference	vector<T, Allocator>::at(size_type pos)
{
	if (pos >= this->_size)
		throw std::out_of_range("Index out of range !");
	return (this->_array[pos]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::at(size_type pos) const
{
	if (pos >= this->_size)
		throw std::out_of_range("Index out of range !");
	return (this->_array[pos]);
}
