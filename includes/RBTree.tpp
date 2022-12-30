/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:14:36 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/30 12:46:53 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::iterator::iterator(void):
	ptr(NULL),
	isEnd(true) {}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::iterator::iterator(RBTreeNode *node, bool isEnd):
	ptr(node),
	isEnd(isEnd) {}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::iterator::iterator(iterator const &obj)
{
	*this = obj;
}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::iterator::~iterator() {}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator &RBTree<T, TreeCompare>::RBTreeNode::iterator::operator=(iterator const &obj)
{
	this->ptr = obj.ptr;
	this->isEnd = obj.isEnd;
	return (*this);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator::reference RBTree<T, TreeCompare>::RBTreeNode::iterator::operator*()
{
	return (this->ptr->content);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator::pointer RBTree<T, TreeCompare>::RBTreeNode::iterator::operator->()
{
	return (&this->ptr->content);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator &RBTree<T, TreeCompare>::RBTreeNode::iterator::operator++()
{
	RBTree<T, TreeCompare>::RBTreeNode	*curNode;
	RBTree<T, TreeCompare>::RBTreeNode	*oldVisitedNode;

	if (this->isEnd)
		this->isEnd = false;
	else if (this->ptr->right)
		this->ptr = this->ptr->right->getMinNode();
	else
	{
		curNode = this->ptr;
		oldVisitedNode = NULL;
		while (curNode && (curNode->left != oldVisitedNode || !oldVisitedNode))
		{
			oldVisitedNode = curNode;
			curNode = curNode->parent;
		}
		if (curNode == NULL)
			this->isEnd = true;
		else
			this->ptr = curNode;
	}
	return (*this);
}

template <typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator	RBTree<T, TreeCompare>::RBTreeNode::iterator::operator++(int)
{
	iterator tmp;

	tmp = *this;
	++*this;
	return (tmp);
}

template <typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator	&RBTree<T, TreeCompare>::RBTreeNode::iterator::operator--()
{
	RBTree<T, TreeCompare>::RBTreeNode	*curNode;
	RBTree<T, TreeCompare>::RBTreeNode	*oldVisitedNode;

	if (this->isEnd)
		this->isEnd = false;
	else if (this->ptr->left)
		this->ptr = this->ptr->left->getMaxNode();
	else
	{
		curNode = this->ptr;
		oldVisitedNode = NULL;
		while (curNode && (curNode->right != oldVisitedNode || !oldVisitedNode))
	 	 {
			oldVisitedNode = curNode;
			curNode = curNode->parent;
		}
		if (curNode == NULL)
			this->isEnd = true;
		else
			this->ptr = curNode;
	}
	return (*this);
}

template <typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode::iterator	RBTree<T, TreeCompare>::RBTreeNode::iterator::operator--(int)
{
	iterator tmp;

	tmp = *this;
	--*this;
	return (tmp);
}

template <typename T, typename TreeCompare>
bool		RBTree<T, TreeCompare>::RBTreeNode::iterator::operator==(iterator const &it)
{
	return (this->ptr == it.ptr && this->isEnd == it.isEnd);
}

template <typename T, typename TreeCompare>
bool		RBTree<T, TreeCompare>::RBTreeNode::iterator::operator!=(iterator const &it)
{
	return (!(*this == it));
}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::RBTreeNode():
	left(NULL),
	right(NULL),
	parent(NULL),
	color(RBTreeNode::BLACK) { }

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::RBTreeNode(T value, enum color color):
	content(value),
	left(NULL),
	right(NULL),
	parent(NULL),
	color(color) { }

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::RBTreeNode(RBTreeNode const &obj):
	content(obj.content),
	left(obj.left),
	right(obj.right),
	parent(obj.parent),
	color(obj.color) { }

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTreeNode::~RBTreeNode(void)
{
	
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode	&RBTree<T, TreeCompare>::RBTreeNode::operator=(RBTreeNode const &obj)
{
	this->content = obj.content;
	this->left = obj.left;
	this->right = obj.right;
	this->parent = obj.parent;
	this->color = obj.color;
	return (*this);
}

//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator==(RBTreeNode const &obj)
//{
//	return (this->content == obj.content);
//}
//
//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator<(RBTreeNode const &obj)
//{
//	return (this->content < obj.content);
//}
//
//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator<=(RBTreeNode const &obj)
//{
//	return (*this == obj || *this < obj);
//}
//
//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator>(RBTreeNode const &obj)
//{
//	return (!(*this < obj) && !(*this == obj));
//}
//
//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator>=(RBTreeNode const &obj)
//{
//	return (*this > obj || *this == obj);
//}
//
//template<typename T, typename TreeCompare>
//bool	RBTree<T, TreeCompare>::RBTreeNode::operator!=(RBTreeNode const &obj)
//{
//	return (!(*this == obj));
//}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode *RBTree<T, TreeCompare>::RBTreeNode::getUncle(void)
{
	if (!this->parent || !this->parent->parent)
		return (NULL);
	if (this->parent->isLeftChild())
		return (this->parent->parent->right);
	else
		return (this->parent->parent->left);
}

template<typename T, typename TreeCompare>
bool	RBTree<T, TreeCompare>::RBTreeNode::isLeftChild(void)
{
	return (this->parent && this == this->parent->left);
}

template<typename T, typename TreeCompare>
bool	RBTree<T, TreeCompare>::RBTreeNode::isRightChild(void)
{
	return (this->parent && this == this->parent->right);
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::RBTreeNode::switchColor(void)
{
	this->color = this->color == BLACK ? RED : BLACK;
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::RBTreeNode::leftRotate(void)
{
	RBTree<T, TreeCompare>::RBTreeNode	*oldRight;

	if (!this->right)
		return ;
	oldRight = this->right;
	if (this->isLeftChild())
		this->parent->left = this->right;
	else if (this->isRightChild())
		this->parent->right = this->right;
	this->right->parent = this->parent;
	this->parent = this->right;
	if (this->right->left)
		this->right->left->parent = this;
	this->right = this->right->left;
	oldRight->left = this;
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::RBTreeNode::rightRotate(void)
{
	RBTree<T, TreeCompare>::RBTreeNode	*oldLeft;

	if (!this->left)
		return ;
	oldLeft = this->left;
	if (this->isLeftChild())
		this->parent->left = this->left;
	else if (this->isRightChild())
		this->parent->right = this->left;
	this->left->parent = this->parent;
	this->parent = this->left;
	if (this->left->right)
		this->left->right->parent = this;
	this->left = this->left->right;
	oldLeft->right = this;
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode	*RBTree<T, TreeCompare>::RBTreeNode::getMinNode()
{
	RBTree<T, TreeCompare>::RBTreeNode	*current;

	current = this;
	while (current->left)
		current = current->left;
	return (current);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode	*RBTree<T, TreeCompare>::RBTreeNode::getMaxNode()
{
	RBTree<T, TreeCompare>::RBTreeNode	*current;

	current = this;
	while (current->right)
		current = current->right;
	return (current);
}

template<typename T, typename TreeCompare>
void RBTree<T, TreeCompare>::RBTreeNode::deleteTree()
{
	if (this->left)
		this->left->deleteTree();
	if (this->right)
		this->right->deleteTree();
	delete this;
}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTree(TreeCompare _comp):
	_size(0),
	_root(NULL),
	_comp(_comp) { }

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::~RBTree(void)
{
	if (this->_root)
		this->_root->deleteTree();
}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>::RBTree(RBTree const &obj)
{
	*this = obj;
}

template<typename T, typename TreeCompare>
RBTree<T, TreeCompare>	&RBTree<T, TreeCompare>::operator=(RBTree const &obj)
{
	this->_size = obj._size;
	if (obj._root)
		this->_root = new RBTreeNode(*obj._root);
	else
		this->_root = NULL;
	return (*this);
}

template<typename T, typename TreeCompare>
size_t	RBTree<T, TreeCompare>::_getSize(void) const
{
	return (this->_size);
}

template<typename T, typename TreeCompare>
bool	RBTree<T, TreeCompare>::_insert(T elem)
{
	RBTreeNode	*node;

	if (!this->_root)
	{
		this->_root = new RBTreeNode(elem, RBTreeNode::BLACK);
		this->_size++;
		return (true);
	}
	node = this->put(elem);
	if (!node)
		return (false);
	fixRBTree(node);
	return (true);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode	*RBTree<T, TreeCompare>::put(T elem)
{
	RBTree<T, TreeCompare>::RBTreeNode	*node;
	RBTree<T, TreeCompare>::RBTreeNode	*curParent;
	bool								parentFound;
	int									order;

	node = new RBTree<T, TreeCompare>::RBTreeNode(elem, RBTreeNode::RED);
	curParent = this->_root;
	parentFound = false;
	while (!parentFound)
	{
		order = this->_comp(node->content, curParent->content) * -1
				+ this->_comp(curParent->content, node->content);
		if (order == 0)
		{
			delete node;
			return (NULL);
		}
		if (order < 0 && curParent->left)
			curParent = curParent->left;
		else if (order > 0 && curParent->right)
			curParent = curParent->right;
		else
			parentFound = true;
	}
	node->parent = curParent;
	if (order < 0)
		curParent->left = node;
	else
		curParent->right = node;
	this->_size++;
	return (node);
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::fixRBTree(RBTree<T, TreeCompare>::RBTreeNode *node)
{
	RBTree<T, TreeCompare>::RBTreeNode	*uncle;

	while (node->parent && node->parent->color == RBTreeNode::RED)
	{
		uncle = node->getUncle();
		if (uncle && uncle->color == RBTreeNode::RED)
		{
			node->parent->switchColor();
			node->parent->parent->switchColor();
			uncle->switchColor();
			node = node->parent->parent;
		}
		else
		{
			if (node->parent->isLeftChild())
			{
				if (node->isRightChild())
				{
					node = node->parent;
					node->leftRotate();
				}
				node->parent->switchColor();
				node->parent->parent->switchColor();
				node->parent->parent->rightRotate();
			}
			else
			{
				if (node->isLeftChild())
				{
					node = node->parent;
					node->rightRotate();
				}
				node->parent->switchColor();
				node->parent->parent->switchColor();
				node->parent->parent->leftRotate();
			}
		}
	}
	this->fixRoot();
	this->_root->color = RBTreeNode::BLACK;
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::fixRoot(void)
{
	RBTree<T, TreeCompare>::RBTreeNode	*newRoot;

	newRoot = this->_root;
	while (newRoot->parent)
		newRoot = newRoot->parent;
	this->_root = newRoot;
}

template<typename T, typename TreeCompare>
bool	RBTree<T, TreeCompare>::_remove(T elem)
{
	RBTree<T, TreeCompare>::RBTreeNode	*node;
	RBTreeNode				sentinel;

	if (!this->_root)
		return (false);
	node = this->_get(elem);
	if (!node)
		return (false);

	RBTree<T, TreeCompare>::RBTreeNode			*replacingNode;
	enum RBTree<T, TreeCompare>::RBTreeNode::color impactingColor = node->color;
	sentinel.parent = NULL;
	if (!node->left && !node->right)
	{
		replacingNode = &sentinel;
		transplant(node, replacingNode);
	}
	else if (!node->left || !node->right)
	{
		if (!node->left)
			replacingNode = node->right;
		else
			replacingNode = node->left;
		this->transplant(node, replacingNode);
	}
	else
	{
		replacingNode = node->right->getMinNode();
		impactingColor = replacingNode->color;
		if (!replacingNode->right)
			replacingNode->right = &sentinel;
		if (replacingNode != node->right)
		{
			this->transplant(replacingNode, replacingNode->right);
			replacingNode->right = node->right;
			replacingNode->right->parent = replacingNode;
		}
		else
			replacingNode->right->parent = replacingNode;
		this->transplant(node, replacingNode);
		replacingNode->left = node->left;
		replacingNode->left->parent = replacingNode;
		replacingNode->color = node->color;
	}
	this->fixRoot();
	if (impactingColor == RBTreeNode::BLACK)
	{
		if (!node->left || !node->right)
			this->applyDeleteFix(replacingNode);
		else
			this->applyDeleteFix(replacingNode->right);
	}
	if (&sentinel == this->_root)
		this->_root = NULL;
	else if (sentinel.isLeftChild())
		sentinel.parent->left = NULL;
	else if (sentinel.isRightChild())
		sentinel.parent->right = NULL;
	delete node;
	this->_size--;
	return (true);
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::applyDeleteFix(RBTree<T, TreeCompare>::RBTreeNode *node)
{
	RBTree<T, TreeCompare>::RBTreeNode *sibling;

	while (node != this->_root && node->color == RBTreeNode::BLACK)
	{
		if (node->isLeftChild())
		{
			sibling = node->parent->right;
			if (sibling && sibling->color == RBTreeNode::RED)
			{
				sibling->color = RBTreeNode::BLACK;
				node->parent->color = RBTreeNode::RED;
				node->parent->leftRotate();
				sibling = node->parent->right;
			}
			if ((!sibling->left || sibling->left->color == RBTreeNode::BLACK) && (!sibling->right || sibling->right->color == RBTreeNode::BLACK))
			{
				sibling->color = RBTreeNode::RED;
				node = node->parent;
			}
			else
			{
				if (!sibling->right || sibling->right->color == RBTreeNode::BLACK)
				{
					if (sibling->left)
						sibling->left->color = RBTreeNode::BLACK;
					sibling->color = RBTreeNode::RED;
					sibling->rightRotate();
					sibling = node->parent->right;
				}
				sibling->color = node->parent->color;
				node->parent->color = RBTreeNode::BLACK;
				sibling->right->color = RBTreeNode::BLACK;
				node->parent->leftRotate();
				this->fixRoot();
				node = this->_root;
			}
			this->fixRoot();
		}
		else
		{
			sibling = node->parent->left;
			if (sibling && sibling->color == RBTreeNode::RED)
			{
				sibling->color = RBTreeNode::BLACK;
				node->parent->color = RBTreeNode::RED;
				node->parent->rightRotate();
				sibling = node->parent->left;
			}
			if ((!sibling->right || sibling->right->color == RBTreeNode::BLACK) && (!sibling->left || sibling->left->color == RBTreeNode::BLACK))
			{
				sibling->color = RBTreeNode::RED;
				node = node->parent;
			}
			else
			{
				if (!sibling->left || sibling->left->color == RBTreeNode::BLACK)
				{
					if (sibling->right)
						sibling->right->color = RBTreeNode::BLACK;
					sibling->color = RBTreeNode::RED;
					sibling->leftRotate();
					sibling = node->parent->left;
				}
				sibling->color = node->parent->color;
				node->parent->color = RBTreeNode::BLACK;
				sibling->left->color = RBTreeNode::BLACK;
				node->parent->rightRotate();
				this->fixRoot();
				node = this->_root;
			}
			this->fixRoot();
		}
	}
	node->color = RBTreeNode::BLACK;
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::transplant(RBTree<T, TreeCompare>::RBTreeNode *oldNode, RBTree<T, TreeCompare>::RBTreeNode *newNode)
{
	if (!oldNode->parent)
		this->_root = newNode;
	else if (oldNode == oldNode->parent->left)
		oldNode->parent->left = newNode;
	else
		oldNode->parent->right = newNode;
	newNode->parent = oldNode->parent;
}

template<typename T, typename TreeCompare>
template<typename K>
typename RBTree<T, TreeCompare>::RBTreeNode	*RBTree<T, TreeCompare>::_get(K key) const
{
	RBTree<T, TreeCompare>::RBTreeNode	*current;
	bool					isFound;
	bool					areLeavesReached;
	int						order;

	if (!this->_root)
		return (NULL);
	current = this->_root;
	isFound = false;
	areLeavesReached = false;
	while (!isFound && !areLeavesReached)
	{
		order = this->_comp(key, current->content) * -1
				+ this->_comp(current->content, key);
		if (order == 0)
			isFound = true;
		else if (order < 0 && current->left)
			current = current->left;
		else if (order > 0 && current->right)
			current = current->right;
		else
			areLeavesReached = true;
	}
	if (areLeavesReached)
		return (NULL);
	return (current);
}

template<typename T, typename TreeCompare>
typename RBTree<T, TreeCompare>::RBTreeNode	*RBTree<T, TreeCompare>::_getRoot(void) const
{
	return (this->_root);
}

template<typename T, typename TreeCompare>
template<typename K>
bool	RBTree<T, TreeCompare>::_contains(K key)
{
	return (this->_get(key) != NULL);
}

template<typename T, typename TreeCompare>
void	RBTree<T, TreeCompare>::empty(void)
{
	if (this->_root)
	{
		this->_root->deleteTree();
		this->_root = NULL;
		this->_size = 0;
	}
}

template<typename T, typename TreeCompare>
bool operator==(const RBTree<T, TreeCompare> &lhs,
			 const RBTree<T, TreeCompare> &rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

template<typename T, typename TreeCompare>
bool operator!=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs )
{
	return !(lhs == rhs);
}

template<typename T, typename TreeCompare>
bool operator<( const RBTree<T, TreeCompare>& lhs,
			const RBTree<T, TreeCompare>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T, typename TreeCompare>
bool operator<=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs )
{
	return (lhs == rhs) || (lhs < rhs);
}

template<typename T, typename TreeCompare>
bool operator>( const RBTree<T, TreeCompare>& lhs,
			const RBTree<T, TreeCompare>& rhs )
{
	return !(lhs <= rhs);
}

template<typename T, typename TreeCompare>
bool operator>=( const RBTree<T, TreeCompare>& lhs,
			 const RBTree<T, TreeCompare>& rhs )
{
	return (lhs > rhs) || (lhs == rhs);
}

template<typename T, typename TreeCompare>
void swap(RBTree<T, TreeCompare>& lhs, RBTree<T, TreeCompare>& rhs )
{
	lhs.swap(rhs);
}
