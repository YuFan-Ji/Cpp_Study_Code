#pragma once
#include<iostream>

using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V> 
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 树为空，直接插入然后返回
		if (_root == nullptr)
		{
			_root = new Node(kv);
			// 根节点必须是黑色
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			// 小于往左走
			if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)   // 大于往右走
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		// 其他结点初始颜色为红色
		cur->_col = RED;

		// 链接
		if (cur->_kv.first < parent->_kv.first)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		cur->_parent = parent;

		// 如果我们parent是黑色，不用处理，就结束了

		// 情况一：cur为红，parent为红，grandfather为黑，uncle不确定
		// 用while循环是因为我们要不断的向上调整
		while (parent && parent->_col == RED)
		{
			// 首先我们要找到grandfather
			Node* grandfather = parent->_parent;
			
			// 接下来通过grandfather找到uncle

			//如果parent是grandfather->_left
			if (parent == grandfather->_left)
			{
				// 说明uncle在右边
				Node* uncle = grandfather->_right;

				// uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 满足上述情况，开始调整颜色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;

					// 但是走到这里有一个问题，如果当前parent就是根，
					// 并且parent是红色，我们要把它变为黑色，
					// 处理方式是：出循环后，暴力将_root->_col变为黑色
				}
				else    // uncle不存在 或 uncle存在且为黑色
				{
					// 判断要怎样旋转

					// 右单旋
					if (cur == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandfather);
						// 调整颜色
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // 左右双旋
					{
						//     g
						//   p
						//		c
						RotateL(parent);
						RotateR(grandfather);
						// 调整颜色
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					// 旋转变色完就结束了，这里不加这个也可以，条件判断就会退出
					break;
				}
			}
			else //(parent == grandfather->_right)  // 如果parent是grandfather->_right
			{
				// 说明uncle在左边
				Node* uncle = grandfather->_left;

				// uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 满足上述情况，开始调整颜色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上调整
					cur = grandfather;
					parent = cur->_parent;
				}
				else    // uncle不存在 或 uncle存在且为黑色
				{
					// 判断要怎样旋转

					// 左单旋
					if (cur == parent->_right)
					{
						// g
						//	  p
						//       c
						RotateL(grandfather);
						// 调整颜色
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else // 右左双旋
					{
						// g
						//	  p
						// c
						RotateR(parent);
						RotateL(grandfather);
						// 调整颜色
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}

		// 这里保证根为黑色
		_root->_col = BLACK;

		return true;
	}

	// 左单旋
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		// 重新链接
		parent->_right = curleft;
		if (curleft) // 如果curleft存在
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}
	}

	// 右单旋
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;

		if (curright)
		{
			curright->_parent = parent;
		}

		cur->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = cur;
		if (ppnode == nullptr)
		{
			cur->_parent = nullptr;
			_root = cur;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}
			cur->_parent = ppnode;
		}
	}

	// 检查是否构建正确
	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != BLACK)
		{
			return false;
		}

		// 基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;

			cur = cur->_left;
		}

		return CheckColour(root, 0, benchmark);
	}

private:
	Node* _root = nullptr;
};