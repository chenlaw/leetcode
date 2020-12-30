#include<vector>
#include<stack>
#include <algorithm>
using namespace std;
//struct Node {
//	int val;
//	Node* next;
//public:
//	Node(int v) {
//		this->val = v;
//		this->next = NULL;
//	}
//};
//int maxProfit(int k, vector<int>& prices) {
//	stack<int> profils;
//	for (int i = 0; i < prices.size()-1; i++) {
//		profils.push(prices[i + 1] - prices[i]);
//	}
//	stack<int> res1;
//	res1.push(0);
//	while (!profils.empty()) {
//		int i = profils.top();
//		profils.pop();
//		int j = res1.top();
//		int k = res1.top() + i;
//		if (abs(j) <= abs(k) ){
//			res1.pop();
//			res1.push(k);
//		}
//		else
//			res1.push(i);
//	}
//	vector<int> dis;
//	Node *head=new Node(0);
//	Node* h = head;
//	int posit=0;
//	if (res1.top() < 0)
//		res1.pop();
//	while (!res1.empty()) {
//		Node* node = new Node(res1.top());
//		res1.pop();
//		h->next = node;
//		h = node;
//		if (h->val < 0)
//			dis.push_back(h->val);
//		else
//			posit++;
//	}
//	sort(dis.begin(), dis.end());
//	bool flag = false;
//	while (posit > k) {
//		int i = dis[0];
//		dis.erase(dis.begin());
//		h = head;
//		while (h->next->next != NULL) {
//			if (h->next->next->val == i) {
//				h->next->next->val = i + h->next->val + h->next->next->next->val;
//				if (h->next->next->val < 0) {
//					h->next->next->val = i;
//					continue;
//				}
//				h->next = h->next->next;
//				h->next->next = h->next->next->next;
//				posit --;
//				flag = true;
//				break;
//			}
//			h = h->next->next;
//		}
//		if (flag) {
//			flag = false;
//
//		}
//		else {
//			break;
//		}
//	}
//	h = head->next;
//	vector<int> v;
//	while (h != NULL) {
//		if (h->val > 0)
//			v.push_back(h->val);
//		h = h->next;
//	}
//	sort(v.begin(), v.end());
//	int res = 0;
//	for (int i = 0; i < k; i++) {
//		res += v[v.size() - i - 1];
//	}
//	return res+k*prices[0];
//}
//int main(){
//	int i = 2;
//	vector<int> v =
//	{ 2, 4, 1 };
//	int r = maxProfit(i, v);
//	i = 0;
//}
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

// O(n^2)
void function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }

}
// O(nlogn)
void function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j * 2) { // 注意这里j=1
            k++;
        }
    }
}
int main() {
    long long n; // 数据规模
    while (1) {
        cout << "输入n：";
        cin >> n;
        milliseconds start_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
            );
        function1(n);
        //        function2(n);
        //        function3(n);
        milliseconds end_time = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()
            );
        cout << "耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count()
            << " ms" << endl;
    }
}