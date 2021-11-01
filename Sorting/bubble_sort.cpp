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

	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}