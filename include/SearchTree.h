#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

namespace mysearchtree {

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
		int size = 0;
		TreeNode* root = nullptr;

		void print_all(const TreeNode* tn) const {
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
				delete_all(tn->right);
				delete(tn);
			}
			else return;
		}

		void insert_all(const TreeNode* tn) {
			if (tn != nullptr) {
				insert_all(tn->left);
				insert(tn->key);
				insert_all(tn->right);
			}
			else return;
		}

	public:

		bool contains(const int& key) const {
			TreeNode* iter = root;

			while (iter != nullptr) {
				if (key < iter->key) {
					iter = iter->left;
				}
				else if (key > iter->key) {
					iter = iter->right;
				}
				else if (key == iter->key) {
					return true;
				}
			}
			return false;
		}

		bool insert(const int& key) {
			TreeNode* iter = root;

			while (iter != nullptr)
			{
				if (key < iter->key) {
					iter = iter->left;
				}
				else if (key > iter->key) {
					iter = iter->right;
				}
				else if (key == iter->key) {
					return false;
				}
			}

			size += 1;
			iter = new TreeNode(key);
			return true;
		}

		void insert_all(int* arr, int n) {
			for (int i = 0; i < n; i++) {
				this->insert(arr[i]);
			}
		}

		bool erase(const int& key) {
			TreeNode* iter = root;
			TreeNode* parent = root;
			while (iter != nullptr)
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

						if (parent->key < key) {
							parent->right = child;
						}
						else parent->left = child;

						delete(iter);
						return true;
					}
					//It is a leaf, no "child" nodes
					else {
						if (key > parent->key) {
							parent->right = nullptr;
						}
						else parent->left = nullptr;
						delete(iter);
					}
					size -= 1;
					return true;
				}
				else {
					if (key < iter->key) {
						parent = iter;
						iter = iter->left;
					}
					else {
						parent = iter;
						iter = iter->right;
					}
				}
			}
			return false;
		}

		SearchTree() = default;

		SearchTree(const SearchTree& st) {
			size = st.size;
			insert_all(st.root);
		}

		~SearchTree() {
			delete_all(root);
			root = nullptr;
		}

		SearchTree& operator=(const SearchTree& rhs) {
			if (this == &rhs) {
				return *this;
			}

			this->~SearchTree();
			*this = SearchTree(rhs);
			return *this;
		}

		int get_size() const {
			return size;
		}

		void print_all() const {
			print_all(this->root);
		}
	};

}
