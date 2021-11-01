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
		
	int n;
	cin>>n;

	vector<int>a(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		int min_idx = i;	
		for(int j=i+1;j<n;j++){
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		swap(a[i] , a[min_idx]);
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;


	

	return 0;
}