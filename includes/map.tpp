/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:18:18 by jmaia             #+#    #+#             */
/*   Updated: 2023/01/02 12:39:47 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator>::map():
	_allocator(Allocator()),
	_compare(Compare()),
	_tree(map<Key, T, Compare, Allocator>::value_compare(_compare)) {}

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator>::map(const Compare &comp, const Allocator &alloc):
	_allocator(alloc),
	_compare(comp),
	_tree(map<Key, T, Compare, Allocator>::value_compare(_compare)) {}

template<class Key, class T, class Compare, class Allocator>
template<class InputIt>
map<Key, T, Compare, Allocator>::map(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc):
	_allocator(alloc),
	_compare(comp),
	_tree(map<Key, T, Compare, Allocator>::value_compare(_compare))
{
	for (InputIt it = first; it != last; it++)
		this->insert(*it);
}

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator>::map(const map &other):
	_tree(map<Key, T, Compare, Allocator>::value_compare(_compare))
{
	*this = other;
}

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator>::~map() {}

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator> &map<Key, T, Compare, Allocator>::operator=(const map &other)
{
	this->_allocator = other._allocator;
	this->_compare = other._compare;
	this->_tree.empty();
	for (map<Key, T, Compare, Allocator>::const_iterator it = other.begin(); it != other.end(); it++)
		this->insert(*it);
	return (*this);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::allocator_type map<Key, T, Compare, Allocator>::get_allocator() const
{
	return (this->_allocator);
}

template<class Key, class T, class Compare, class Allocator>
T &map<Key, T, Compare, Allocator>::at(const Key &key)
{
	typename RBTree<value_type, value_compare>::RBTreeNode	*node;
	value_type	junk(key, T());

	node = this->_tree._get(junk);
	if (!node)
		throw std::out_of_range("Out of range !");
	return (node->content.second);
}

template<class Key, class T, class Compare, class Allocator>
T const &map<Key, T, Compare, Allocator>::at(const Key &key) const
{
	typename RBTree<value_type, value_compare>::RBTreeNode	*node;
	value_type	junk(key, T());

	node = this->_tree._get(junk);
	if (!node)
		throw std::out_of_range("Out of range !");
	return (node->content.second);
}

template<class Key, class T, class Compare, class Allocator>
T &map<Key, T, Compare, Allocator>::operator[](const Key &key)
{
	return (insert(ft::make_pair(key, T())).first->second);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::begin()
{
	if (this->_tree._getSize() == 0)
		return (iterator());
	return (iterator(this->_tree._getRoot()->getMinNode(), false));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::begin() const
{
	if (this->_tree._getSize() == 0)
		return (const_iterator());
	return (const_iterator(this->_tree._getRoot()->getMinNode(), false));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::end()
{
	if (this->_tree._getSize() == 0)
		return (iterator());
	return (iterator(this->_tree._getRoot()->getMaxNode(), true));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::end() const
{
	if (this->_tree._getSize() == 0)
		return (const_iterator());
	return (const_iterator(this->_tree._getRoot()->getMaxNode(), true));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rbegin()
{
	return (reverse_iterator(this->end()));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rbegin() const
{
	return (const_reverse_iterator(this->end()));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::reverse_iterator map<Key, T, Compare, Allocator>::rend()
{
	return (reverse_iterator(iterator(this->begin())));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_reverse_iterator map<Key, T, Compare, Allocator>::rend() const
{
	return (const_reverse_iterator(const_iterator(this->begin())));
}

template<class Key, class T, class Compare, class Allocator>
bool map<Key, T, Compare, Allocator>::empty() const
{
	return (this->_tree._getSize() == 0);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::size() const
{
	return (this->_tree._getSize());
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::max_size() const
{
	return (this->_allocator.max_size());
}

template<class Key, class T, class Compare, class Allocator>
void map<Key, T, Compare, Allocator>::clear()
{
	this->_tree.empty();
}

template<class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool> map<Key, T, Compare, Allocator>::insert(const value_type &value)
{
	ft::pair<map<Key, T, Compare, Allocator>::iterator, bool> ret;
	
	ret.second = this->_tree._insert(value);
	ret.first = iterator(this->_tree._get(value), false);
	return (ret);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::insert(iterator pos, const value_type &value)
{
	(void) pos;
	this->_tree._insert(value);
}

template<class Key, class T, class Compare, class Allocator>
template<class InputIt>
void map<Key, T, Compare, Allocator>::insert(InputIt first, InputIt last)
{
	for (InputIt it = first; it != last; it++)
		this->insert(*it);
}

template<class Key, class T, class Compare, class Allocator>
void map<Key, T, Compare, Allocator>::erase(iterator pos)
{
	this->_tree._remove(*pos);
}

template<class Key, class T, class Compare, class Allocator>
void map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
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

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::erase(const Key &key)
{
	value_type	junk(key, T());

	return (this->_tree._remove(junk));
}	

template<class Key, class T, class Compare, class Allocator>
void map<Key, T, Compare, Allocator>::swap(map<Key, T, Compare, Allocator> &other)
{
	typename RBTree<ft::pair<Key, T>, value_compare>::RBTreeNode	*root_tmp;
	size_t		size_tmp;

	root_tmp = this->_root;
	size_tmp = this->_size;
	this->_root = other._root;
	this->_size = other._size;
	other._root = root_tmp;
	other._size = size_tmp;
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::size_type map<Key, T, Compare, Allocator>::count(const Key &key) const
{
	return (this->_contains(key));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::find(const Key &key)
{
	return (iterator(this->_get(key)));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::find(const Key &key) const
{
	return (iterator(this->_get(key)));
}

template<class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator> map<Key, T, Compare, Allocator>::equal_range(const Key &key)
{
	iterator	it;

	it = this->find(key);
	return (ft::pair<iterator, iterator>(it, it));
}

template<class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator> map<Key, T, Compare, Allocator>::equal_range(const Key &key) const
{
	iterator	it;

	it = this->find(key);
	return (ft::pair<const_iterator, const_iterator>(it, it));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::lower_bound(const Key &key)
{
	iterator	it;

	for (it = this->begin(); it != this->end(); it++)
	{
		if (this->_compare(key, *it) >= 0)
			break;
	}
	return (it);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::lower_bound(const Key &key) const
{
	const_iterator	it;

	for (it = this->begin(); it != this->end(); it++)
	{
		if (this->_compare(key, *it) >= 0)
			break;
	}
	return (it);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::iterator map<Key, T, Compare, Allocator>::upper_bound(const Key &key)
{
	const_iterator	it;

	for (it = this->rbegin(); it != this->rend(); it++)
	{
		if (this->_compare(key, *it) <= 0)
			break;
	}
	return (it);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::const_iterator map<Key, T, Compare, Allocator>::upper_bound(const Key &key) const
{
	const_iterator	it;

	for (it = this->rbegin(); it != this->rend(); it++)
	{
		if (this->_compare(key, *it) <= 0)
			break;
	}
	return (it);
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::key_compare map<Key, T, Compare, Allocator>::key_comp() const
{
	return (key_compare(this->_compare));
}

template<class Key, class T, class Compare, class Allocator>
typename map<Key, T, Compare, Allocator>::value_compare map<Key, T, Compare, Allocator>::value_comp() const
{
	return (value_compare(this->_compare));
}

template<class Key, class T, class Compare, class Allocator>
bool	map<Key, T, Compare, Allocator>::value_compare::operator()(const value_type& lhs, const value_type& rhs) const
{
	return (this->comp(lhs.first, rhs.first));
}

template<class Key, class T, class Compare, class Allocator>
map<Key, T, Compare, Allocator>::value_compare::value_compare(Compare c):
	comp(c) { }
