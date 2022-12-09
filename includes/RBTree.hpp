#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <cstdlib>

template<typename T>
class	RBTree
{
	public:
		struct RBTreeNode
		{
			enum color {RED, BLACK};

			private:
				RBTreeNode(void);
			public:
				T			content;
				RBTreeNode	*left;
				RBTreeNode	*right;
				RBTreeNode	*parent;
				enum color	color;

				RBTreeNode(T value, enum color color);
				RBTreeNode(RBTreeNode const &obj);
				~RBTreeNode(void);

				bool	operator=(RBTreeNode const &obj);

				bool	operator==(RBTreeNode const &obj);
				bool	operator<(RBTreeNode const &obj);
				bool	operator<=(RBTreeNode const &obj);
				bool	operator>(RBTreeNode const &obj);
				bool	operator>=(RBTreeNode const &obj);
				bool	operator!=(RBTreeNode const &obj);

				RBTreeNode	*getUncle(void);
				bool		isLeftChild(void);
				bool		isRightChild(void);
				void		switchColor(void);
				void		leftRotate(void);
				void		rightRotate(void);
				RBTreeNode	*getMinNode();
			friend class RBTree<T>;
		};
	private:
		size_t		_size;
		RBTreeNode	*_root;

		RBTreeNode	*put(T elem);
		void		fixRBTree(RBTreeNode *node);
		void		fixRoot(void);
		void		transplant(RBTreeNode *oldNode, RBTreeNode *newNode);
		void		applyDeleteFix(RBTreeNode *node);
	protected:
		RBTree(void);
		~RBTree(void);
		RBTree(RBTree const &obj);

		RBTree	&operator=(RBTree const &obj);

		size_t		getSize(void) const;
		bool		insert(T elem);
		bool		remove(T elem);
		T			contains(void);
		template<typename K>
		RBTreeNode	*get(K key);
		template<typename K>
		bool		contains(K key);

};

# include "RBTree.tpp"

#endif
