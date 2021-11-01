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

int getMax(vector<int>& a){
	int n = a.size();
	int max = a[0];
	for(int i=1;i<n;i++){
		if(a[i] > max){
			max = a[i];
		}
	}
	return max;
}

void countingSort(vector<int>&a , int place){
	int max = 10;
	int n = a.size();
	int output[n];
	int count[max];
	for(int i=0;i<max;i++){
		count[i] = 0;
	}

	for(int i=0;i<n;i++){
		count[(a[i]/place)%10]++;
	}

	for(int i=1;i<max;i++){
		count[i] += count[i-1];
	}

	for(int i = n-1;i>=0;i--){
		output[count[(a[i] / place)%10] - 1] = a[i];
		count[(a[i] / place)%10]--;
	}

	for(int i=0;i<n;i++){
		a[i] = output[i];
	}

}

void radix_sort(vector<int>& a){
	int n = a.size();
	int max = getMax(a);
	for(int place = 1;max / place > 0; place *= 10){
		countingSort(a,place);
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

	radix_sort(a);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;

	return 0;
}