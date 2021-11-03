#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <random>
#include<iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <complex>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct node{
	int data;
	struct node *left , *right;
	node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void perorderTraversal(struct node* node){
	if(node == NULL) return ;
	cout<<node->data<<"->";
	perorderTraversal(node->left);
	perorderTraversal(node->right);
}

void postorderTraversal(struct node* node){
	if(node == NULL) return ;
	postorderTraversal(node->left);
	postorderTraversal(node->right);
	cout<<node->data<<"->";
}

void inorderTraversal(struct node* node){
	if(node == NULL)return ;
	inorderTraversal(node->left);
	cout<<node->data<<"->";

	inorderTraversal(node->right);
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	

	struct node* root = new node(1);

	root->left = new node(12);
	root->right = new node(9);

	root->left->left = new node(5);
	root->left->right = new node(6);
	
	cout << "Inorder traversal ";
	inorderTraversal(root);

	cout << "\nPreorder traversal ";
	perorderTraversal(root);

	cout << "\nPostorder traversal ";
	postorderTraversal(root);

	return 0;
}