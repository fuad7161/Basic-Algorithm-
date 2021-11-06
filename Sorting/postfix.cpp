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
int main()
{
    char ss[] = "231*+9-";
    stack<float> s;
    for (int i = 0; i < 7; i++)
    {
        if (isdigit(ss[i]))
        {
            s.push((float)ss[i]);
        }
        else
        {
            float nu, nuu;
            nuu = s.top();
            s.pop();
            nu = s.top();
            s.pop();
            int sum;
            switch (ss[i])
            {
            case '+':
                sum = nu + nuu;
                s.push(sum);
                break;
            case '-':
                sum = nu - nuu;
                s.push(sum);
                break;
            case '*':
                sum = nu * nuu;
                s.push(sum);
                break;
            case '/':
                sum = nu / nuu;
                s.push(sum);
                break;

            }
        }
    }
    cout<<s.top();
}
