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
struct Node{
public:
    int data;
    Node *lnext, *rnext;
    Node(int val){
        data = val;
        lnext = NULL;
        rnext = NULL;
    }
};
Node *creatBST(Node *head, int val){
    if (head == NULL){
        return new Node(val);
    }
    if (val < head->data){
        head->lnext=creatBST(head->lnext, val);
    }
    else{
       head->rnext=creatBST(head->rnext, val);
    }
    return head; 
}
void inorder(Node *head){
    if (head == NULL){
        return;
    }
    inorder(head->lnext);
    cout << head->data << " ";
    inorder(head->rnext);
}
int main(){
	
    Node *root = NULL;
    root = creatBST(root, 5);
    creatBST(root, 1);
    creatBST(root, 3);
    creatBST(root, 4);
    creatBST(root, 2);
    creatBST(root, 7);
    creatBST(root, 6);
    inorder(root);
}
