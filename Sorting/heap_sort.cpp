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

void heapify(vector<int>& a, int n, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l < n and a[l] > a[largest]){
		largest = l;
	}

	if(r < n and a[r] > a[largest]){
		largest = r;
	}

	if(largest != i){
		swap(a[i] , a[largest]);
		heapify(a,n,largest);
	}
}

void heap_sort(vector<int>& a){
	int n = a.size();
	for(int i = n/2-1;i>=0;i--){
		heapify(a,n,i);
	}

	for(int i=n-1;i>=0;i--){
		swap(a[0] , a[i]);
		heapify(a,i,0);
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	vector<int>a(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	heap_sort(a);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}