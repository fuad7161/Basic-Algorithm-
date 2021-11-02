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

const int N = 1e5+5;
vector<int>g[N];
int vis[N];
vector<int>ans;

void dfs(int u){
	ans.push_back(u);
	vis[u] = 1;
	for(int i: g[u]){
		if(vis[i] == 0){
			dfs(i);
		}
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	
	int n,m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1);

	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}cout<<endl;

	return 0;
}