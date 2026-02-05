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

	// build a set using the default constructor

	set<int> s;

	// inserting into a set

	// using set::insert

	s.insert(2);
	s.insert(3);
	s.insert(1);
	s.insert(2); // duplicates are ignored

	// iterating over the set

	// using for-each loop

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}