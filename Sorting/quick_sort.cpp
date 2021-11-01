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

int partition(vector<int>&a,int low, int high){
	int pivot = a[high];
	int i = (low - 1);

	for(int j=low ; j<= high-1;j++){
		if(a[j] < pivot){
			i++;
			swap(a[i] , a[j]);
		}
	}
	swap(a[i+1] , a[high]);
	return i+1;
}

void quick_sort(vector<int>& a,int low, int high){
	if(low < high){
		int pi = partition(a,low, high);
		quick_sort(a,low , pi-1);
		quick_sort(a,pi+1 ,high);
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

	quick_sort(a,0,n-1);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}