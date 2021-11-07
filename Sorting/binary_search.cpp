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
    cin>>n;

    cin>>val;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int l = 0;
    int r = n-1;

    int pos = 0;
    int lp = 20;
    while(l<r){
        int mid = (l+r)/2;
        if(a[mid] == val){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(a[mid] <= val){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    
    if(a[l] == val){
        cout<<"yes"<<endl;
    }else{
        cout<<-1<<endl;
    }


    

    return 0;
}
