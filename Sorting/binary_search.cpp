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


int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	
	int n,val;
	cin>>n>>val;
	
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l = 0;
	int r = n-1;
	int pos = -1;
	int loop = 100;
	while(loop--){
		int mid = (l+r)/2;
		if(a[mid] < val){
			l = mid+1;
		}else{
			r = mid;
			pos = r;
		}
	}

	if(a[pos] == val){
		cout<<val<<" is found"<<endl;
	}else{
		cout<<val<<" val not found"<<endl;
	}
	

	return 0;
}