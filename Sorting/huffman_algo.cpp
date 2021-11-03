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
	char data;
	int freq;
	node* left , *right;
	node(char data , int freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare{
	bool operator()(node* l, node* r){
		return l->freq > r->freq;
	}
};

void print_Coders(struct node* root , string str){
	if(!root)return ;
	if(root -> data != '$'){
		cout<<root->data<<": "<<str<<endl;
	}
	print_Coders(root->left , str+"0");
	print_Coders(root->right , str+"1");
}

void HuffmanCode(string s){
	struct node *left , *right,*top;
	priority_queue<node* , vector<node*>,compare>pq;
	map<char, int>vis;
	int size = s.size();
	for(int i=0;i<size;i++){
		vis[s[i]]++;
	}
	for(auto i : vis){
		pq.push(new node(i.first , i.second));
	}
	while(pq.size() != 1){
		left = pq.top();
		pq.pop();
		right = pq.top();
		pq.pop();
		top = new node('$' , left->freq +right->freq);
		top->left = left;
		top->right = right;
		pq.push(top);
	}
	print_Coders(pq.top() , "");
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	

	string s;
	//cin>>s;
	s = "aaaaaaaaaabbbbbccccccccccccccddddddddddddddeeeeeeefffffffff";
	HuffmanCode(s);

	return 0;
}