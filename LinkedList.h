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

public:
	SearchTree() = default;

	SearchTree(const SearchTree& st) {
		length = st.length;
		//push_tail(st);
	}

	SearchTree& operator=(const SearchTree& rhs) {
		if (this == &rhs) {
			return *this;
		}

		this->~SearchTree();

		//this->push_tail(rhs);
		return *this;
	}

	~SearchTree() {
		if (length > 0) {
			TreeNode* iter_ptr = this->root;
			TreeNode* next_node;
		}
		root = nullptr;
		length = 0;
	}

	int get_length() const {
		return length;
	}

	void print_all() const {
		print_all(this->root);
	}

	bool contains(const int& key) const{
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
		if (root == nullptr) {
			root = new TreeNode(key);
			return true;
		}

		if (this->contains(key)) {
			return false;
		}

		TreeNode* iter = root;
		while (true)
		{
			if (key < iter->key){
				if (iter->left == nullptr)
				{
					TreeNode* new_tree_node = new TreeNode(key);
					iter->left = new_tree_node;
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
					}
					else {
						iter = iter->right;
					}
				}
			}
		}
	}



	bool erase(const int& key) {
		
	}
};