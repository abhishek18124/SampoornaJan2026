/*

What are maps ?

Maps are associative containers that store elements formed by a combination of a key value
and a mapped value, following a specific order. Internally, the elements in a map are always
sorted by its key.

Maps are typically implemented as binary search trees, and therefore are generally slower
than unordered_map containers to access individual elements by their key.

How to create an map ?
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an map ?
	> use map::insert (C++11)
    > use []
How to update a (K, V) pair in an map ?
    > use []
How to lookup/search for the value corresponding to a key in an map ?
    > use map::find
    > use map::count
    > use []
How to delete a (K, V) pair from an map ?
	> use map::erase
	  > by key
	  > by position
	  > by range
    > use map::clear to remove all the elements from an map
How to check size of an map ?
	> use map::size to know number of (K, V) pairs present in an map
How to check if a map is empty ?
    > use map::empty or check if size of map is 0
How to iterate over elements in an map ?
    > use an iterator

*/

#include<iostream>
#include<map>

using namespace std;

int main() {

	// build an map using the default constructor

	map<string, double> cgpaMap;

	// inserting into a map

	// using map::insert

	// cgpaMap.insert({"Manish", 7.2});
	// cgpaMap.insert(make_pair("Manish", 7.2));

	// using []

	cgpaMap["Manish"] = 7.2;
	cgpaMap["Dev"] = 8.5;
	cgpaMap["Sukriti"] = 9.2;
	cgpaMap["Anshit"] = 7;

	// cgpaMap["Anshit"] = 7.5;

	// print map size using map::size

	// todo ...

	// iterating over the map

	// using for-each loop

	for (pair<string, double> p : cgpaMap) {
		cout << p.first << " " << p.second << endl;
	}
	cout << endl;

	for (pair<string, double> p : cgpaMap) {
		string name = p.first;
		double cgpa = p.second;
		cout << name << " " << cgpa << endl;
	}

	cout << endl;

	// using for-each loop and structured binding

	for (auto [name, cgpa] : cgpaMap) {
		cout << name << " " << cgpa << endl;
	}

	cout << endl;

	// updates using []

	// todo ...

	return 0;
}