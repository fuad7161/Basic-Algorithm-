//problem link: https://www.spoj.com/problems/RMQSQ/
//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb  push_back
#define vi  vector<int>
#define all(n) n.begin(),n.end()
const int Inf           = (int)2e9 + 5;
#define vout(v) for (auto z: v) cout << z << " "; cout << endl;

const int N   = 4e5 + 5;

int st[N];
int ar[N];

void buildTree(int si,int ss,int se){
	if(ss == se){
		st[si] = ar[ss];
	 	return;
	}
	int mid = (ss+se)/2;
	buildTree(2*si,ss,mid);
	buildTree(2*si+1,mid+1,se);
	st[si] = min(st[2*si],st[2*si+1]);
}

int query(int si,int ss,int se,int qs,int qe){
	if(se < qs or qe < ss) return INT_MAX;
	if(ss >= qs and se <= qe) return st[si];
	int mid = (ss+se)/2;
	int l = query(2*si, ss,mid,qs,qe);
	int r = query(2*si+1,mid+1,se,qs,qe);

	return min(l,r);
}

signed main(){
	
	int n;
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>ar[i];
	}

	buildTree(1,1,n);
	int q;
	cin>>q;

	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(1,1,n,l+1,r+1)<<endl;

	}

	return 0;
}
