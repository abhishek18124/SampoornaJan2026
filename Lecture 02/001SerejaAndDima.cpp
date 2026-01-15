#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	int i = 0;
	int j = n - 1;
	bool serejasTurn = true;

	while (i <= j) {

		if (serejasTurn) {

			// it is sereja's turn

			if (v[i] > v[j]) {

				serejaScore += v[i];
				i++;

			} else {

				serejaScore += v[j];
				j--;

			}

			serejasTurn = false;

		} else {

			// it is dima's turn

			if (v[i] > v[j]) {

				dimaScore += v[i];
				i++;

			} else {

				dimaScore += v[j];
				j--;

			}

			serejasTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}