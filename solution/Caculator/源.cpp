#include<stack>
#include<vector>
#include<string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int calculate(string s) {
    stack<int> ops;
    int ret = 0;
    int op = 1;
    ops.push(op);
    int i = 0;
    int n = s.length();
    while (i < n) {
        char c = s.at(i);
        if (c >= '0' && c <= '9') {
            int num = c - '0';
            i++;
            while (i < n && s.at(i) >= '0' && s.at(i) <= '9') {
                num = num * 10 + s.at(i) - '0';
                i++;
            }
            ret = ret + op * num;
        }
        else if (c == ' ')
            i++;
        else if (c == '+') {
            op = ops.top();
            i++;
        }
        else if (c == '-') {
            op = ops.top() * -1;
            i++;
        }
        else if (c == '(') {
            ops.push(op);
            i++;
        }
        else if (c == ')') {
            ops.pop();
            i++;
        }
    }
    return ret;
}
int calculate2(string s) {
    deque<char> ops;
    deque<int> nums;
    int i = 0;
    int n = s.length();
    while (i < n) {
        char c = s.at(i);
        if (c == ' ') {
            i++;
        }
        else if (c >= '0' && c <= '9') {
            int num = c - '0';
            i++;
            while (i < n && s.at(i) >= '0' && s.at(i) <= '9') {
                num += (s.at(i) - '0');
                i++;
            }
            if (!ops.empty())
                if (ops.back() == '/') {
                    num = nums.back() / num;
                    nums.pop_back();
                    ops.pop_back();
                }
                else if (ops.back() == '*') {
                    num = nums.back() * num;
                    nums.pop_back();
                    ops.pop_back();
                }
            nums.push_back(num);
        }
        else {
            ops.push_back(c);
            i++;
        }
    }
    int res = nums.front();
    nums.pop_front();
    while (!ops.empty()) {
        if (ops.front() == '+') {
            res += nums.front();
            nums.pop_front();
            ops.pop_front();
        }
        else {
            res -= nums.front();
            nums.pop_front();
            ops.pop_front();
        }
    }
    return res;
}
int main() {
    string s = "42";
    calculate2(s);
    unordered_map<int, int> m;
    m.emplace(3, 4);
    auto s2=m.find(3);
    auto c =s2 == m.end();
    queue<int>q;
    q.
}