#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};
	int n = A.size();

	vector<int> ans;

	stack<int> s; // monotonic stack

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have any nearest greater element
			// to its right
			ans.push_back(-1);
		} else {
			// whatever is at the top of the stack is the
			// nearest greater element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;
}