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
vector<int>dis , vis;

void shortest_path(int n, int x){
	dis.resize(n+1, n*2);
	vis.resize(n+1, 0);
	queue<int>q;
	q.push(x);
	dis[x] = 0;
	while(q.size()){
		int u = q.front();
		vis[u] = 1;
		q.pop();
		for(int v : g[u]){
			if(vis[v] == 0){
				q.push(v);
				dis[v] = min(dis[v],dis[u]+1);
			}
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

	shortest_path(n,1);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}cout<<endl;
	/*while(query--){
		int x,y;
		cin>>x>>y;
		shortest_path(n,x,y);
		cout<<dis[y]<<endl;
	}*/

	return 0;
}