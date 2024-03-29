/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:29:50 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 15:14:04 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class T, class Allocator>
vector<T, Allocator>::vector(void):
					_allocator(Allocator()),
					_array(NULL),
					_capacity(0),
					_size(0) { }

template<class T, class Allocator>
vector<T, Allocator>::vector(const Allocator &alloc):
					_allocator(alloc),
					_array(NULL),
					_capacity(0),
					_size(0) {}

template<class T, class Allocator>
vector<T, Allocator>::vector(size_type count, const T &value, const Allocator& alloc):
			_allocator(alloc),
			_capacity(count),
			_size(count)
{
	this->_array = this->_allocator.allocate(this->_capacity);
	this->constructObjs(value);
	std::fill(this->begin(), this->begin() + this->_capacity, value);
}

template<class T, class Allocator>
void	vector<T, Allocator>::constructObjs(const T &value)
{
	for (vector<T, Allocator>::iterator it = this->begin(); it != this->begin() + this->_capacity; it++)
		this->_allocator.construct(it, value);
}

template<class T, class Allocator>
vector<T, Allocator>::vector(const vector &obj):
	_allocator(Allocator()),
	_array(NULL),
	_capacity(0),
	_size(0)
{
	*this = obj;
}

template<class T, class Allocator>
template<class InputIt>
vector<T, Allocator>::vector(typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last, const Allocator& alloc):
		_allocator(alloc)
{
	this->_capacity = std::distance(first, last);
	this->_size = 0;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->constructObjs();
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
	if (this == &obj)
		return (*this);
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_allocator = allocator_type(obj._allocator);
	this->_capacity = obj._capacity;
	this->_size = 0;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->constructObjs();
	this->insert(this->end(), obj.begin(), obj.end());
	return (*this);
}

template<class T, class Allocator>
void	vector<T, Allocator>::assign(size_type count, const T &value)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_capacity = count;
	this->_size = count;
	this->_array = this->_allocator.allocate(this->_capacity);
	this->constructObjs();
	std::fill(this->begin(), this->begin() + this->_size, value);
}

template<class T, class Allocator>
template<class InputIt>
void	vector<T, Allocator>::assign(InputIt first, InputIt last,
	typename ft::enable_if<!ft::is_integral<InputIt>::value, int>::type)
{
	this->_allocator.deallocate(this->_array, this->_capacity);
	this->_capacity = std::distance(first, last);
	this->_array = this->_allocator.allocate(this->_capacity);
	this->constructObjs();
	this->_size = 0;
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

template<class T, class Allocator>
typename vector<T, Allocator>::reference	vector<T, Allocator>::operator[](size_type pos)
{
	return (this->_array[pos]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::operator[](size_type pos) const
{
	return (this->_array[pos]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::reference	vector<T, Allocator>::front(void)
{
	return (this->_array[0]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::front(void) const
{
	return (this->_array[0]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::reference	vector<T, Allocator>::back(void)
{
	return (this->_array[this->_size - 1]);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reference	vector<T, Allocator>::back(void) const
{
	return (this->_array[this->_size - 1]);
}

template<class T, class Allocator>
T	*vector<T, Allocator>::data(void)
{
	return (this->_array);
}

template<class T, class Allocator>
const T	*vector<T, Allocator>::data(void) const
{
	return (this->_array);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
{
	return (this->_array);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
{
	return (this->_array);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
{
	return (this->_array + this->_size);
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
{
	return (this->_array + this->_size);
}

template<class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
{
	return (reverse_iterator(this->end()));
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const
{
	return (const_reverse_iterator(this->end()));
}

template<class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend()
{
	return (reverse_iterator(this->begin()));
}

template<class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const
{
	return (const_reverse_iterator(this->begin()));
}

template<class T, class Allocator>
bool	vector<T, Allocator>::empty(void) const
{
	return (this->begin() == this->end());
}

template<class T, class Allocator>
typename vector<T, Allocator>::size_type	vector<T, Allocator>::size(void) const
{
	return (this->_size);
}

template<class T, class Allocator>
typename vector<T, Allocator>::size_type	vector<T, Allocator>::max_size(void) const
{
	return (this->_allocator.max_size());
}

template<class T, class Allocator>
void	vector<T, Allocator>::reserve(typename vector<T, Allocator>::size_type new_cap)
{
	T											*newArray;
	T											*oldArray;
	typename vector<T, Allocator>::size_type	oldSize;

	if (new_cap <= this->_capacity)
		return ;
	if (new_cap > this->max_size())
		throw std::length_error("New capacity is too large");
	newArray = this->_allocator.allocate(new_cap);
	oldArray = this->_array;
	oldSize = this->_size;
	this->_array = newArray;
	this->_capacity = new_cap;
	this->_size = 0;
	this->constructObjs();
	this->insert(this->end(), oldArray, oldArray + oldSize);
	this->_allocator.deallocate(oldArray, oldSize);
}

template<class T, class Allocator>
typename vector<T, Allocator>::size_type	vector<T, Allocator>::capacity(void) const
{
	return (this->_capacity);
}

template<class T, class Allocator>
void	vector<T, Allocator>::clear(void)
{
	this->_size = 0;
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const T &value)
{
	this->shiftRight(pos, 1);
	if (!pos)
		pos = this->end();
	iterator it = const_cast<iterator>(pos);
	*it = value;
	this->_size++;
	return (it);
}

template<class T, class Allocator>
void	vector<T, Allocator>::shiftRight(const_iterator &pos, typename vector<T, Allocator>::size_type n)
{
	vector<T, Allocator>::difference_type relativePos = std::distance(this->begin(), const_cast<iterator>(pos));
	if (this->_size + n > this->_capacity)
	{
		this->reserve(this->_capacity + (n / VEC_EXPAND_SIZE + 1) * VEC_EXPAND_SIZE);
		pos = this->begin() + relativePos;
	}
	if (this->_size == 0)
		return ;
	for (const_iterator it = this->end() - 1; it >= pos; it--)
		*const_cast<iterator>(it + n) = *it;
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, size_type count, const T &value)
{
	this->shiftRight(pos, count);
	if (!pos)
		pos = this->end();
	iterator it = const_cast<iterator>(pos);
	std::fill(it, it + count, value);
	this->_size += count;
	return (it);
}

template<class T, class Allocator>
template<class InputIt>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(typename vector<T, Allocator>::const_iterator pos, typename enable_if<!is_integral<InputIt>::value, InputIt>::type first, InputIt last)
{
	size_type count = std::distance(first, last);
	this->shiftRight(pos, count);
	if (!pos)
		pos = this->end();
	iterator it = const_cast<iterator>(pos);
	while (first != last)
	{
		*it = *first;
		++it;
		++first;
	}
	this->_size += count;
	return (it);
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(typename vector<T, Allocator>::iterator pos)
{
	this->shiftLeft(pos, 1);
	return (pos);
}

template<class T, class Allocator>
void	vector<T, Allocator>::shiftLeft(const_iterator pos, typename vector<T, Allocator>::size_type n)
{
	if (this->_size == 0)
		return ;
	if (!pos || pos == this->end())
		return ;
	iterator first = const_cast<iterator>(pos);
	for (iterator it = first; it != this->end() - n; it++)
		*it = *(it + n);
	this->_size -= n;
}

template<class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last)
{
	this->shiftLeft(first, std::distance(first, last));
	return (first);
}

template<class T, class Allocator>
void	vector<T, Allocator>::push_back(const T &value)
{
	this->insert(this->end(), value);
}

template<class T, class Allocator>
void	vector<T, Allocator>::pop_back(void)
{
	this->_size--;
}

template<class T, class Allocator>
void	vector<T, Allocator>::resize(size_type count, T value)
{
	if (count <= this->_size)
		this->_size = count;
	else
		this->insert(this->end(), count - this->_size, value);
}

template<class T, class Allocator>
void	vector<T, Allocator>::swap(vector<T, Allocator> &obj)
{
	ft::swap(this->_array, obj._array);
	ft::swap(this->_allocator, obj._allocator);
	ft::swap(this->_capacity, obj._capacity);
	ft::swap(this->_size, obj._size);
}

template<class T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<class T, class Allocator>
bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (typename vector<T, Allocator>::const_iterator it = lhs.begin(), it2 = rhs.begin(); it != lhs.end(); it++, it2++)
	{
		if (*it != *it2)
			return (false);
	}
	return (true);
}

template<class T, class Allocator>
bool operator!=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	return (!(lhs == rhs));
}

template<class T, class Allocator>
bool operator<(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	return (ft::lexicographical_compare<typename vector<T, Allocator>::const_iterator, typename vector<T, Allocator>::const_iterator>(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Allocator>
bool operator<=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	return (lhs < rhs || lhs == rhs);
}

template<class T, class Allocator>
bool operator>(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	return (!(lhs <= rhs));
}

template<class T, class Allocator>
bool operator>=(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
{
	return (!(lhs < rhs));
}

template<class T, class Allocator>
void swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs)
{
	lhs.swap(rhs);
}
