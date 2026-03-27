/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	// build a multiset using the default constructor

	multiset<int> ms;

	cout << ms.size() << endl;

	// inserting into a multiset

	// using multiset::insert

	ms.insert(1);
	ms.insert(4);
	ms.insert(1);
	ms.insert(3);
	ms.insert(1);

	cout << ms.size() << endl;

	// iterating over the multiset

	// using a range-based for loop

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	// erasing from a multiset

	ms.erase(1);

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.insert(4);

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.erase(ms.find(4));

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.insert(2);
	ms.insert(6);
	ms.insert(2);
	ms.insert(2);

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	cout << *ms.begin() << endl;
	cout << *ms.rbegin() << endl;

	ms.erase(ms.begin());

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.erase(ms.find(*ms.rbegin()));

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	ms.insert(3);
	ms.insert(3);

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	auto it = ms.find(3);
	it++;
	ms.erase(it);

	ms.erase(ms.find(3));

	for (int x : ms) {
		cout << x << " ";
	}

	cout << endl;

	it = ms.find(3);
	it++;
	cout << *it << endl;

	return 0;
}