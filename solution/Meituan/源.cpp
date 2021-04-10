#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool findMinCould(unordered_map<int, int>& Acount, unordered_map<int, int>& Bcount, int m, int i) {
    for (auto& a : Acount) {
        if (Bcount[(a.first+i)%m] != a.second)return false;
    }
    return true;
}
int main() {
    int m, n;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    unordered_map<int, int> Bcount;
    for (int& i : B) {
        Bcount[i]++;
    }
    unordered_map<int, int> Acount;
    for (int& i : A) {
        Acount[i % m]++;
    }
    bool find = false;
    int a1 = A[0]%m;
    int a2 = Acount[a1];
    for (auto& b : Bcount) {
        if (a2 == b.second) {
            if (findMinCould(Acount, Bcount, m, b.first + m - a1)) {
                cout << b.first + m - a1;
                break;
            }
        }

    }
   

}
//int main() {
//    int m, n;
//    while (cin >> m >> n) {
//        double res = 0;
//        for (int i = 0; i < n; i++) {
//            res += sqrt(m);
//        }
//        cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
//    }
//}