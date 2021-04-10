#pragma once
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
    int val;
    Node* next;

};
class MyHashSet
{
private:
       vector<Node*> v;
       int c = 0;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v.resize(4);
        c = 2;
    }

    void add(int key) {
        int hash = key>>c;
        auto c = v.begin();
      
    }

    void remove(int key) {

    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {

    }
};

