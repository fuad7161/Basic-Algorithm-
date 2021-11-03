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

class Stack{
	public:
		int top;
		unsigned capacity;
		int* array;
};

Stack* createStack(unsigned capacity){
	Stack* stack = new Stack();
	if(!stack)return NULL;
	stack -> top = -1;
	stack->capacity = capacity;
	stack->array = new int[(stack->capacity * sizeof(int))];

	if(!stack->array)return NULL;
	return stack;
}

int isEmpty(Stack* stack){
	return stack->top == -1;
}

int peek(Stack *stack){
	return stack->array[stack->top];
}

int pop(Stack *stack){
	if(!isEmpty(stack)){
		return stack->array[stack->top--];
	}
	return '$';
}

void push(Stack *stack, int op){
	stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp){
	Stack *stack = createStack(strlen(exp));
	int i;
	for(i = 0;exp[i];i++){
		if(exp[i] == ' ')continue;
		else if(isdigit(exp[i])){
			int num = 0;
			while(isdigit(exp[i])){
				num = num*10 + (int)(exp[i] - '0');
				i++;
			}
			i--;
			push(stack,num);
		}else{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i]){
				case '+':push(stack , val2+val1);break;
				case '-':push(stack , val2-val1);break;
				case '*':push(stack , val2*val1);break;
				case '/':push(stack , val2/val1);break;
			}
		}
	}
	return pop(stack);
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	char exp[] = "100 200 + 2 / 5 * 7 +";
	cout<<evaluatePostfix(exp)<<endl;
	return 0;
}