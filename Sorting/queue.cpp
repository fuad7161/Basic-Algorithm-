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
	
	queue<int>q;
		
	int n = 10;
	for(int i=0;i<n;i++{
		q.push(i);
	}

	while(q.size()){
		cout<<q.front()<<endl;
		q.pop();
	}	

	return 0;
}