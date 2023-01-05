/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:18:18 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/05 13:38:02 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class T, class Compare, class Allocator>
set<T, Compare, Allocator>::set():
	_allocator(Allocator()),
	_compare(Compare()),
	_tree(set<T, Compare, Allocator>::value_compare(_compare), _allocator) {}

template<class T, class Compare, class Allocator>
set<T, Compare, Allocator>::set(const Compare &comp, const Allocator &alloc):
	_allocator(alloc),
	_compare(comp),
	_tree(set<T, Compare, Allocator>::value_compare(_compare), _allocator) {}

template<class T, class Compare, class Allocator>
template<class InputIt>
set<T, Compare, Allocator>::set(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc):
	_allocator(alloc),
	_compare(comp),
	_tree(set<T, Compare, Allocator>::value_compare(_compare), _allocator)
{
	for (InputIt it = first; it != last; it++)
		this->insert(*it);
}

template<class T, class Compare, class Allocator>
set<T, Compare, Allocator>::set(const set &other):
	_tree(set<T, Compare, Allocator>::value_compare(_compare), _allocator)
{
	*this = other;
}

template<class T, class Compare, class Allocator>
set<T, Compare, Allocator>::~set() {}

template<class T, class Compare, class Allocator>
set<T, Compare, Allocator> &set<T, Compare, Allocator>::operator=(const set &other)
{
	this->_allocator = other._allocator;
	this->_compare = other._compare;
	this->_tree.empty();
	for (set<T, Compare, Allocator>::const_iterator it = other.begin(); it != other.end(); it++)
		this->insert(*it);
	return (*this);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::allocator_type set<T, Compare, Allocator>::get_allocator() const
{
	return (this->_allocator);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::begin() const
{
	if (this->_tree._getSize() == 0)
		return (iterator());
	return (iterator(this->_tree._getRoot()->getMinNode(), false));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::end() const
{
	if (this->_tree._getSize() == 0)
		return (iterator());
	return (iterator(this->_tree._getRoot()->getMaxNode(), true));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rbegin() const
{
	return (reverse_iterator(this->end()));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::reverse_iterator set<T, Compare, Allocator>::rend() const
{
	return (reverse_iterator(iterator(this->begin())));
}

template<class T, class Compare, class Allocator>
bool set<T, Compare, Allocator>::empty() const
{
	return (this->_tree._getSize() == 0);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::size() const
{
	return (this->_tree._getSize());
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::max_size() const
{
	return (this->_allocator.max_size());
}

template<class T, class Compare, class Allocator>
void set<T, Compare, Allocator>::clear()
{
	this->_tree.empty();
}

template<class T, class Compare, class Allocator>
ft::pair<typename set<T, Compare, Allocator>::iterator, bool> set<T, Compare, Allocator>::insert(const value_type &value)
{
	ft::pair<set<T, Compare, Allocator>::iterator, bool> ret;
	
	ret.second = this->_tree._insert(value);
	ret.first = iterator(this->_tree._get(value), false);
	return (ret);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::insert(iterator pos, const value_type &value)
{
	(void) pos;
	this->_tree._insert(value);
	return (iterator(this->_tree._get(value), false));
}

template<class T, class Compare, class Allocator>
template<class InputIt>
void set<T, Compare, Allocator>::insert(InputIt first, InputIt last)
{
	for (InputIt it = first; it != last; it++)
		this->insert(*it);
}

template<class T, class Compare, class Allocator>
void set<T, Compare, Allocator>::erase(iterator pos)
{
	this->_tree._remove(*pos);
}

template<class T, class Compare, class Allocator>
void set<T, Compare, Allocator>::erase(iterator first, iterator last)
{
	iterator	next;
	iterator	cur;

	next = first;
	while (next != last)
	{
		cur = next;
		next++;
		this->erase(cur);
	}
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::erase(const T &key)
{
	return (this->_tree._remove(key));
}	

template<class T, class Compare, class Allocator>
void set<T, Compare, Allocator>::swap(set<T, Compare, Allocator> &other)
{
	this->_tree.swap(other._tree);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::size_type set<T, Compare, Allocator>::count(const T &key) const
{
	return (this->_tree._contains(key));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::find(const T &key) const
{
	typename RBTree<value_type, value_compare, Allocator>::RBTreeNode	*elem;

	elem = this->_tree._get(key);
	if (elem == NULL)
		return this->end();
	else
		return (iterator(elem, false));
	return (iterator(this->_tree._get(key), false));
}

template<class T, class Compare, class Allocator>
ft::pair<typename set<T, Compare, Allocator>::iterator, typename set<T, Compare, Allocator>::iterator> set<T, Compare, Allocator>::equal_range(const T &key) const
{
	return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::lower_bound(const T &key) const
{
	iterator	it;
	bool		found;

	found = false;
	for (it = this->begin(); it != this->end(); it++)
	{
		if (!this->_compare(*it, key))
		{
			found = true;
			break;
		}
	}
	if (!found)
		it = this->end();
	return (it);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::iterator set<T, Compare, Allocator>::upper_bound(const T &key) const
{
	iterator	it;
	bool		found;

	found = false;
	for (it = this->begin(); it != this->end(); it++)
	{
		if (this->_compare(key, *it))
		{
			found = true;
			break;
		}
	}
	if (!found)
		it = this->end();
	return (it);
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::key_compare set<T, Compare, Allocator>::key_comp() const
{
	return (key_compare(this->_compare));
}

template<class T, class Compare, class Allocator>
typename set<T, Compare, Allocator>::value_compare set<T, Compare, Allocator>::value_comp() const
{
	return (value_compare(this->_compare));
}

template<class T, class Compare, class Alloc>
bool	operator==(const ft::set<T, Compare, Alloc> &lhs,
			const ft::set<T, Compare, Alloc> &rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

template< class T, class Compare, class Alloc >
bool 	operator!=( const ft::set<T,Compare,Alloc>& lhs,
			const ft::set<T,Compare,Alloc>& rhs )
{
	return !(lhs == rhs);
}

template< class T, class Compare, class Alloc >
bool	operator<( const ft::set<T,Compare,Alloc>& lhs,
			const ft::set<T,Compare,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Compare, class Alloc >
bool	operator<=( const ft::set<T,Compare,Alloc>& lhs,
			 const ft::set<T,Compare,Alloc>& rhs )
{
	return (lhs == rhs) || (lhs < rhs);
}

template< class T, class Compare, class Alloc >
bool	operator>( const ft::set<T,Compare,Alloc>& lhs,
			const ft::set<T,Compare,Alloc>& rhs )
{
	return !(lhs <= rhs);
}

template< class T, class Compare, class Alloc >
bool	operator>=( const ft::set<T,Compare,Alloc>& lhs,
			 const ft::set<T,Compare,Alloc>& rhs )
{
	return (lhs > rhs) || (lhs == rhs);
}

template< class T, class Compare, class Alloc >
void swap(ft::set<T,Compare,Alloc>& lhs,
		   ft::set<T,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
}
