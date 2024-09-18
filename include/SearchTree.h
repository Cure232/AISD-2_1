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
			TreeNode* parent;
			int key;

			TreeNode(const int& _key, TreeNode* _left = nullptr, TreeNode* _right = nullptr, TreeNode* _parent = nullptr) {
				left = _left;
				right = _right;
				parent = _parent;
				key = _key;
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

		void erase_all(TreeNode* start_point) {
			if (start_point != nullptr) {
				while (start_point->left != nullptr) {
					erase(start_point->left->key);
				}
					
				while (start_point->right != nullptr) {
					erase(start_point->right->key);
				}

				erase(start_point->key);
			}
			else return;
		}

		void insert_all(const TreeNode* tn) {
			if (tn != nullptr) {
				this->insert(tn->key);
				insert_all(tn->left);
				insert_all(tn->right);
			}
			else return;
		}

	public:

		SearchTree() : size(0), root(nullptr) {};

		SearchTree(const SearchTree & st) {
			erase_all(root);
			insert_all(st.root);
		}

		~SearchTree() {
			erase_all(root);
			root = nullptr;
			size = 0;
		}
		
		SearchTree& operator=(const SearchTree & rhs) {
			if (this == &rhs) {
				return *this;
			}

			erase_all(root);
			insert_all(rhs.root);
			return *this;
		}
		
		int get_size() const {
			return size;
		}

		void print_all() const {
			print_all(this->root);
		}

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

			TreeNode* iter = nullptr;
			TreeNode* next_node = root;
			while (next_node != nullptr)
			{
				iter = next_node;
				if (key < iter->key) {
					next_node = iter->left;
				}
				else if (key > iter->key) {
					next_node = iter->right;
				}
				else if (key == iter->key) {
					return false;
				}
			}

			next_node = new TreeNode(key);
			if (root == nullptr) {
				root = next_node;
			}
			else {
				if (key > iter->key) {
					iter->right = next_node;
				}
				else iter->left = next_node;

				next_node->parent = iter;
			}
			size += 1;
			return true;
		}

		void insert_all(int* key_arr, int n) {
			for (int i = 0; i < n; i++) {
				this->insert(key_arr[i]);
			}
		}

		bool erase(const int& key) {
			TreeNode* iter = root;
			while (iter != nullptr)
			{
				if (key == iter->key) {
					//2 child nodes
					if (iter->left != nullptr && iter->right != nullptr) {
						TreeNode* to_delete = iter;

						//Finding the element that stands directly next in ascending order
						iter = iter->right;
						while (iter->left != nullptr)
						{
							iter = iter->left;
						}

						//Inserting successor in old one`s place
						int new_key = iter->key;
						erase(iter->key);
						to_delete->key = new_key;
						return true;
					}
					//Only 1 child node
					else if (iter->left != nullptr || iter->right != nullptr) {
						TreeNode* child;
						if (iter->left != nullptr) {
							child = iter->left;
						}
						else child = iter->right;

						child->parent = iter->parent;

						if (iter->parent->key < key) {
							iter->parent->right = child;
							
						}
						else iter->parent->left = child;

						delete(iter);
					}
					//It is a leaf, no "child" nodes
					else {
						if (iter == root)
						{
							root = nullptr;
						}
						else if (iter->parent->key < key) {
							iter->parent->right = nullptr;
						} 
						else iter->parent->left = nullptr;

						delete(iter);
					}

					size -= 1;
					return true;
				}
				else {
					if (key < iter->key) {
						iter = iter->left;
					}
					else {
						iter = iter->right;
					}
				}
			}
			return false;
		}


	};

}
