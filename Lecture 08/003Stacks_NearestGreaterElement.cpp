#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};
	int n = A.size();

	vector<int> ans(n, -1);

	stack<int> s; // monotonic stack

	for (int i = 0; i < n; i++) {

		// find out for which elements that we've seen so far
		// A[i] can be the ans i.e. nearest
		// greater element to their right

		while (!s.empty() and A[i] > A[s.top()]) {
			ans[s.top()] = A[i];
			s.pop();
		}

		s.push(i);

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}