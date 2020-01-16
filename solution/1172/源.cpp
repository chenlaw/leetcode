#include<stdlib.h>
#include<vector>
using namespace std;
class DinnerPlates {
public:
	vector<vector<int>*> dinner;
	int capacity;
	int not_full;
	int not_null;
	DinnerPlates(int capacity) {
		this->capacity = capacity;
	}

	void push(int val) {
		int tag = 0;
		for (vector<int>* v : dinner) {
			int s = v->size();
			if (s < capacity) {
				v->push_back(val);
				return;
			}
		}
		dinner.push_back(new vector<int>());
		dinner[dinner.size() - 1]->push_back(val);
	}

	int pop() {
		int s = dinner.size();
		for (int i = s - 1; i >= 0; i--) {
			vector<int> *v = dinner[i];
			int ss = v->size();
			if (ss > 0) {
				int s = v->at(ss - 1);
				v->pop_back();
				return s;
			}
		}
		return -1;
	}

	int popAtStack(int index) {

		if (index >= dinner.size())
			return -1;
		vector<int>* v = dinner.at(index);
		int ss = v->size();
		if (ss > 0) {
			int s = v->at(ss - 1);
			v->pop_back();
			return s;
		}
		return -1;
	}
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */