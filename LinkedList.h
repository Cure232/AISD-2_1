#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

class SearchTree {
protected:
	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int key;

		TreeNode(const int& _key, TreeNode* _left = nullptr, TreeNode* _right = nullptr) {
			key = _key;
			left = _left;
			right = _right;
		}
	};

private:
	int length = 0;
	TreeNode* root = nullptr;
	
	void print_all(const TreeNode* tn) const{
		if (tn != nullptr) {
			print_all(tn->left);
			cout << tn->key << " ";
			print_all(tn->right);
		}
		else return;
	}

	void delete_all(TreeNode* tn) {
		if (tn != nullptr) {
			delete_all(tn->left);
			this->delete_all(tn->right);
			delete(tn);
		}
		else return;
	}

	void insert_all(const TreeNode* tn) {
		if (tn != nullptr) {
			insert_all(tn->left);
			this->insert(tn->key);
			insert_all(tn->right);
		}
		else return;
	}

public:
	bool contains(const int& key) const {
		if (root == nullptr) {
			return false;
		}

		TreeNode* iter = root;
		while (true) {
			if (key < iter->key) {
				iter = iter->left;
				continue;
			}
			else if (key > iter->key) {
				iter = iter->right;
				continue;
			}
			else if (key == iter->key) {
				return true;
			}
			else return false;
		}
	}

	bool insert(const int& key) {
		if (this->contains(key)) {
			return false;
		}

		length += 1;
		if (root == nullptr) {
			root = new TreeNode(key);
			return true;
		}

		TreeNode* iter = root;
		while (true)
		{
			if (key < iter->key) {
				if (iter->left == nullptr)
				{
					TreeNode* new_tree_node = new TreeNode(key);
					iter->left = new_tree_node;
					return true;
				}
				else {
					iter = iter->left;
				}
			}
			else {
				if (key > iter->key) {
					if (iter->right == nullptr)
					{
						TreeNode* new_tree_node = new TreeNode(key);
						iter->right = new_tree_node;
						return true;
					}
					else {
						iter = iter->right;
					}
				}
			}
		}
	}

	void insert_all(int* arr, int n) {
		for (int i = 0; i < n; i++) {
			this->insert(arr[i]);
		}
	}

	bool erase(const int& key) {
		if (this->contains(key) == false) {
			return false;
		}

		TreeNode* iter = root;
		TreeNode* parent = nullptr;
		while (true)
		{
			if (key == iter->key) {
				//2 child nodes
				if (iter->left != nullptr && iter->right != nullptr) {
					TreeNode* to_delete = iter;

					TreeNode* leaf_parent = iter;
					iter = iter->right;
					//Finding the element that stands directly next in ascending order
					while (iter->left != nullptr)
					{
						leaf_parent = iter;
						iter = iter->left;
					}
					//Checking if iter has right child node and handling this
					if (iter->right != nullptr) {
						leaf_parent->left = iter->right;
						iter->right = nullptr;
					}
					//Inserting node in old one`s place
					if (to_delete->key < parent->key) {
						parent->right = iter;
					}
					else parent->left = iter;

					iter->left = to_delete->left;
					iter->right = to_delete->right;

					delete(to_delete);
					return true;
				}
				//Only 1 child node
				else if (iter->left != nullptr || iter->right != nullptr) {
					TreeNode* child;
					if (iter->left != nullptr) {
						child = iter->left;
					}
					else child = iter->right;

					if (key < parent->key) {
						parent->right = child;
					}
					else parent->left = child;

					delete(iter);
					return true;
				}
				//Это лист, нет "дочерних" узлов
				else {
					if (key > parent->key) {
						parent->right = nullptr;
					}
					else parent->left = nullptr;
					delete(iter);
				}
				length -= 1;
				return true;
			}
			else {
				if (key < iter->key) {
					iter = iter->left;
				}
				else iter = iter->right;
			}
		}
	}

	SearchTree() = default;

	SearchTree(const SearchTree& st) {
		length = st.length;
		insert_all(st.root);
	}

	~SearchTree() {
		if (length > 0) {
			TreeNode* iter_ptr = this->root;
			TreeNode* next_node;
		}
		root = nullptr;
		length = 0;
	}

	SearchTree& operator=(const SearchTree& rhs) {
		if (this == &rhs) {
			return *this;
		}

		this->~SearchTree();
		*this = SearchTree(rhs);
		return *this;
	}

	int get_length() const {
		return length;
	}

	void print_all() const {
		print_all(this->root);
	}
};