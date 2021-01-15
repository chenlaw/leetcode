#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
int count(int i) {
    int next = 0;
    while (i != 0) {
        next += (i % 10)*(i % 10);
        i /= 10;
    }
    return next;
}
bool isHappy(int n) {
    unordered_set<int> log;
    while (n != 1) {
        if (log.count(n) == 1)
            return false;
        log.insert(n);
        n = count(n);
    }
    return true;
}
int main() {
    int r = isHappy(7);
}