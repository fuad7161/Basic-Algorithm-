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
	st[si] = (st[2*si]+st[2*si+1]);
}

int query(int si,int ss,int se,int qs,int qe){
	if(se < qs or qe < ss) return 0;;
	if(ss >= qs and se <= qe) return st[si];
	int mid = (ss+se)/2;
	int l = query(2*si, ss,mid,qs,qe);
	int r = query(2*si+1,mid+1,se,qs,qe);

	return (l+r);
}

void update(int si,int ss,int se,int qi){
	if(ss == se){
		st[si] = ar[ss];
		return ;
	}
	int mid = (ss+se)/2;
	if(qi <= mid){
		update(2*si,ss,mid,qi);
	}else{
		update(2*si+1,mid+1,se,qi);
	}
	st[si] = (st[2*si]+st[2*si+1]);
}

bool isPrime(int x){
	if(x < 2)return false;
	for(int i=2;i*i<=x;i++){
		if(x%i == 0)return false;
	}return true;
}

signed main(){
	
	int n;
	cin>>n;
	int x;
	for(int i =1;i<=n;i++){
		cin>>x;
		if(isPrime(x)){
			ar[i] = 1;
		}else{
			ar[i] = 0;
		}
	}

	buildTree(1,1,n);

	
	int q;
	cin>>q;

	while(q--){
		int x;
		cin>>x;
		if(x == 1){
			int l,r;
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}else{
			int z,k;cin>>z>>k;
			if(isPrime(k)){
				ar[z] = 1;
			}else{
				ar[z] = 0;
			}
			update(1,1,n,z);
		}

	}

	return 0;
}
