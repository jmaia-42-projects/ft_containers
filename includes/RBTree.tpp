/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:14:36 by jmaia             #+#    #+#             */
/*   Updated: 2022/12/09 18:12:58 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
RBTree<T>::RBTreeNode::iterator::iterator():
	ptr(NULL) { }

template<typename T>
RBTree<T>::RBTreeNode::iterator::iterator(RBTreeNode *node):
	ptr(node) {}

template<typename T>
RBTree<T>::RBTreeNode::iterator::iterator(iterator const &obj)
{
	*this = obj;
}

template<typename T>
RBTree<T>::RBTreeNode::iterator::~iterator() {}

template<typename T>
typename RBTree<T>::RBTreeNode::iterator &RBTree<T>::RBTreeNode::iterator::operator=(iterator const &obj)
{
	this->ptr = obj.ptr;
}

template<typename T>
typename RBTree<T>::RBTreeNode::iterator::reference RBTree<T>::RBTreeNode::iterator::operator*()
{
	return (*this->ptr);
}

template<typename T>
typename RBTree<T>::RBTreeNode::iterator::pointer RBTree<T>::RBTreeNode::iterator::operator->()
{
	return (this->ptr);
}

template<typename T>
typename RBTree<T>::RBTreeNode::iterator &RBTree<T>::RBTreeNode::iterator::operator++()
{
	RBTree<T>::RBTreeNode	*curNode;
	RBTree<T>::RBTreeNode	*oldVisitedNode;

	oldVisitedNode = NULL;
	curNode = this->ptr;
	while (curNode && (!curNode->right || curNode->right == oldVisitedNode))
	{
		oldVisitedNode = curNode;
		curNode = curNode->parent;
	}
	if (curNode == this->ptr)
		this->ptr = curNode->right->getMinNode();
	else
		this->ptr = curNode;
	return (*this);
}

template <typename T>
typename RBTree<T>::RBTreeNode::iterator	RBTree<T>::RBTreeNode::iterator::operator++(int)
{
	iterator tmp;

	tmp = *this;
	++*this;
	return (tmp);
}

template <typename T>
typename RBTree<T>::RBTreeNode::iterator	&RBTree<T>::RBTreeNode::iterator::operator--()
{
	RBTree<T>::RBTreeNode	*curNode;
	RBTree<T>::RBTreeNode	*oldVisitedNode;

	oldVisitedNode = NULL;
	curNode = this->ptr;
	while (curNode && (!curNode->left || curNode->left == oldVisitedNode))
	{
		oldVisitedNode = curNode;
		curNode = curNode->parent;
	}
	if (curNode == this->ptr)
		this->ptr = curNode->left->getMaxNode();
	else
		this->ptr = curNode;
	return (*this);
}

template <typename T>
typename RBTree<T>::RBTreeNode::iterator	RBTree<T>::RBTreeNode::iterator::operator--(int)
{
	iterator tmp;

	tmp = *this;
	--*this;
	return (tmp);
}

template <typename T>
bool		RBTree<T>::RBTreeNode::iterator::operator==(iterator const &it)
{
	return (this->ptr = it.ptr);
}

template <typename T>
bool		RBTree<T>::RBTreeNode::iterator::operator!=(iterator const &it)
{
	return (!(*this == it));
}

template<typename T>
RBTree<T>::RBTreeNode::RBTreeNode():
	left(NULL),
	right(NULL),
	parent(NULL),
	color(RBTreeNode::BLACK) { }

template<typename T>
RBTree<T>::RBTreeNode::RBTreeNode(T value, enum color color):
	content(value),
	left(NULL),
	right(NULL),
	parent(NULL),
	color(color) { }

template<typename T>
RBTree<T>::RBTreeNode::RBTreeNode(RBTreeNode const &obj)
{
	*this = obj;
}

template<typename T>
RBTree<T>::RBTreeNode::~RBTreeNode(void) { }

template<typename T>
bool	RBTree<T>::RBTreeNode::operator=(RBTreeNode const &obj)
{
	this->content = obj.content;
	this->left = obj.left;
	this->right = obj.right;
	this->parent = obj.parent;
	this->color = obj.color;
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator==(RBTreeNode const &obj)
{
	return (this->content == obj.content);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator<(RBTreeNode const &obj)
{
	return (this->content < obj.content);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator<=(RBTreeNode const &obj)
{
	return (*this == obj || *this < obj);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator>(RBTreeNode const &obj)
{
	return (!(*this < obj) && !(*this == obj));
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator>=(RBTreeNode const &obj)
{
	return (*this > obj || *this == obj);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::operator!=(RBTreeNode const &obj)
{
	return (!(*this == obj));
}

template<typename T>
typename RBTree<T>::RBTreeNode *RBTree<T>::RBTreeNode::getUncle(void)
{
	if (!this->parent || !this->parent->parent)
		return (NULL);
	if (this->parent->isLeftChild())
		return (this->parent->parent->right);
	else
		return (this->parent->parent->left);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::isLeftChild(void)
{
	return (this->parent && this == this->parent->left);
}

template<typename T>
bool	RBTree<T>::RBTreeNode::isRightChild(void)
{
	return (this->parent && this == this->parent->right);
}

template<typename T>
void	RBTree<T>::RBTreeNode::switchColor(void)
{
	this->color = this->color == BLACK ? RED : BLACK;
}

template<typename T>
void	RBTree<T>::RBTreeNode::leftRotate(void)
{
	RBTree<T>::RBTreeNode	*oldRight;

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

template<typename T>
void	RBTree<T>::RBTreeNode::rightRotate(void)
{
	RBTree<T>::RBTreeNode	*oldLeft;

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

template<typename T>
typename RBTree<T>::RBTreeNode	*RBTree<T>::RBTreeNode::getMinNode()
{
	RBTree<T>::RBTreeNode	*current;

	current = this;
	while (current->left)
		current = current->left;
	return (current);
}

template<typename T>
typename RBTree<T>::RBTreeNode	*RBTree<T>::RBTreeNode::getMaxNode()
{
	RBTree<T>::RBTreeNode	*current;

	current = this;
	while (current->right)
		current = current->right;
	return (current);
}

template<typename T>
RBTree<T>::RBTree(void):
	_size(0),
	_root(NULL) { }

template<typename T>
RBTree<T>::~RBTree(void)
{
	delete this->_root;
}

template<typename T>
RBTree<T>::RBTree(RBTree const &obj)
{
	*this = obj;
}

template<typename T>
RBTree<T>	&RBTree<T>::operator=(RBTree const &obj)
{
	this->_size = obj._size;
	this->_root = new RBTreeNode(this->_root);
}

template<typename T>
size_t	RBTree<T>::getSize(void) const
{
	return (this->_size);
}

template<typename T>
bool	RBTree<T>::insert(T elem)
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

template<typename T>
typename RBTree<T>::RBTreeNode	*RBTree<T>::put(T elem)
{
	RBTree<T>::RBTreeNode	*node;
	RBTree<T>::RBTreeNode	*curParent;
	bool					parentFound;

	node = new RBTree<T>::RBTreeNode(elem, RBTreeNode::RED);
	curParent = this->_root;
	parentFound = false;
	while (!parentFound)
	{
		if (*node == *curParent)
		{
			delete node;
			return (NULL);
		}
		if (*node < *curParent && curParent->left)
			curParent = curParent->left;
		else if (*node > *curParent && curParent->right)
			curParent = curParent->right;
		else
			parentFound = true;
	}
	node->parent = curParent;
	if (*node < *curParent)
		curParent->left = node;
	else
		curParent->right = node;
	this->_size++;
	return (node);
}

template<typename T>
void	RBTree<T>::fixRBTree(RBTree<T>::RBTreeNode *node)
{
	RBTree<T>::RBTreeNode	*uncle;

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

template<typename T>
void	RBTree<T>::fixRoot(void)
{
	RBTree<T>::RBTreeNode	*newRoot;

	newRoot = this->_root;
	while (newRoot->parent)
		newRoot = newRoot->parent;
	this->_root = newRoot;
}

template<typename T>
bool	RBTree<T>::remove(T elem)
{
	RBTree<T>::RBTreeNode	*node;
	RBTreeNode				sentinel;

	if (!this->_root)
		return (false);
	node = this->get(elem);
	if (!node)
		return (false);

	RBTree<T>::RBTreeNode			*replacingNode;
	enum RBTree<T>::RBTreeNode::color impactingColor = node->color;
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

template<typename T>
void	RBTree<T>::applyDeleteFix(RBTree<T>::RBTreeNode *node)
{
	RBTree<T>::RBTreeNode *sibling;

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

template<typename T>
void	RBTree<T>::transplant(RBTree<T>::RBTreeNode *oldNode, RBTree<T>::RBTreeNode *newNode)
{
	if (!oldNode->parent)
		this->_root = newNode;
	else if (oldNode == oldNode->parent->left)
		oldNode->parent->left = newNode;
	else
		oldNode->parent->right = newNode;
	newNode->parent = oldNode->parent;
}

template<typename T>
template<typename K>
typename RBTree<T>::RBTreeNode	*RBTree<T>::get(K key)
{
	RBTree<T>::RBTreeNode	*current;
	bool					isFound;
	bool					areLeavesReached;

	if (!this->_root)
		return (NULL);
	current = this->_root;
	isFound = false;
	areLeavesReached = false;
	while (!isFound && !areLeavesReached)
	{
		if (key == current->content)
			isFound = true;
		else if (key < current->content && current->left)
			current = current->left;
		else if (key > current->content && current->right)
			current = current->right;
		else
			areLeavesReached = true;
	}
	if (areLeavesReached)
		return (NULL);
	return (current);
}

template<typename T>
template<typename K>
bool	RBTree<T>::contains(K key)
{
	return (this->get(key) != NULL);
}
