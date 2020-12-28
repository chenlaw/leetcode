#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
priority_queue<int> maxStack;
priority_queue<int, vector<int>, greater<int>> minStack;
void Insert(int num)
{
	minStack.push(num);
	int a = minStack.top();
	minStack.pop();
	maxStack.push(a);
	if (maxStack.size() - minStack.size() >= 2) {
		a = maxStack.top(); 
		maxStack.pop();
		minStack.push(a);
	}
}

double GetMedian(){
	if (minStack.size() != maxStack.size())
		return maxStack.top();
	else
		return (double(minStack.top()) + double(maxStack.top())) / 2;

}
int main() {
	vector<int> v = { 5, 2, 3, 4, 1, 6, 7, 0, 8 };
	for (int i = 0; i < v.size(); i++) {
		Insert(v[i]);
		cout << GetMedian();
	}
}