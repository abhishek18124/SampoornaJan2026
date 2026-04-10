#include<iostream>
#include<deque>

using namespace std;

int main() {

	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);

	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}

	cout << endl;

	for (auto& x : d) {
		cout << x << " ";
	}

	cout << endl;

	d.push_front(-10);
	d.push_front(-20);
	d.push_front(-30);

	cout << d.size() << endl;

	for (auto& x : d) {
		cout << x << " ";
	}

	cout << endl;

	d.pop_back();
	d.pop_front();

	for (auto& x : d) {
		cout << x << " ";
	}

	cout << endl;

	cout << d.size() << endl;

	return 0;
}