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
	node *next;
};

node *create_node(int val , node *next){
	node *n1 = new node();
	n1->data = val;
	n1->next = next;
	return n1;
}

void make(node *n1, node *n2){
	n1->next = n2;
}

node *insert_first(node *head,int val){
	node *n1 = create_node(val,NULL);
	if(head == NULL) {
		return n1;
	}
	else{
		make(n1 , head);
		return n1;
	}
}



void insert_kth_position(node *head , int pos, int val){
	node *cur = head;
	pos-=2;
	while(pos--){
		cur = cur->next;
	}
	node *n1 = create_node(val, NULL);
	node *cur2 = cur->next;
	if(cur->next == NULL){
		make(cur , n1);
	}else{
		make(cur , n1);
		make(n1,cur2);
	}
}

node delete_first1(node *head){
	node *cur = head;
	node *n1 = NULL;
	if(cur -> next == NULL){
		return *n1;
	}
	return *cur->next;
}


void delete_by_key(node *head , int pos){
	pos -= 2;
	node *cur = head;
	while(pos--){
		cur = cur->next;
	}
	//cout<<cur -> data<<endl;
	if(cur->next->next != NULL){
		cur->next = cur->next->next;
	}else{
		cur->next = NULL;
	}
}

void print_list(node *head){
	node *cur = head;
	while(cur!=NULL){
		cout<<cur->data<<" ";
		cur = cur->next;
	}
	cout<<endl;
	return;
}

int ck(node* head , int val){
	node* tem = head;
	int cnt = 1;
	while(tem!=NULL){
		if(tem->data == val){
			return cnt;
		}
		cnt++;
		tem = tem->next;
	}
	return 0;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);

	node *head = NULL;
	int pos,val;

	while(1){
		cout<<"1. Insert a value in a positont"<<endl;
		cout<<"2. Delete a value in a position"<<endl;
		cout<<"3. Searching in a value"<<endl;
		int t;cin>>t;
		if(t == 1){
			int val , pos;
			cin>>pos >> val;
			if(pos == 1){
				head = insert_first(head,val);
			}else{
				insert_kth_position(head , pos ,val);
			}
		}else if(t == 2){
			int pos;
			cout<<"give the position to delete."<<endl;
			cin>>pos;
			if(pos == 1){
				*head = delete_first1(head);
			}else {
				delete_by_key(head , pos);
			}
		}else{
			int pos = 0, val;
			cin>>val;
			pos = ck(head, val);
			if(pos != 0){
				cout<<val<<" "<<"is founded in the position "<<pos<<endl;
			}else{
				cout<<"value dosen't exist."<<endl;
			}
		}
		print_list(head);

	}

	return 0;
}