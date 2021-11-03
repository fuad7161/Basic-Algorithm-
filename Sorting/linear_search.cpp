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
	

	int n, val;
	cin>>n>>val;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int pos = -1;
	for(int i=0;i<n;i++){
		if(a[i] == val){
			pos = i;
			break;
		}
	}
	
	if(pos != -1){
		cout<<val <<" is in the position in :"<<pos+1<<endl;
	}else{
		cout<<val<<" is not in this array"<<endl;
	}

	return 0;
}