class Solution {
public:

	// time : O(nlogn)
	// space: O(n) due to multiset<>

	vector<int> findOriginalArray(vector<int>& changed) {
		multiset<int> ms(changed.begin(), changed.end());
		vector<int> org;

		while (!ms.empty()) {
			int x = *ms.begin();
			ms.erase(ms.begin());

			// when you erase in a ms<> by value, it deletes all
			// ocurrences but when you erase in a ms<> by addr
			// it deletes only the element at that addr

			if (ms.find(2 * x) == ms.end()) {
				// 2x was not present in the ms<> so answer doesn't exist
				return {};
			}

			auto it = ms.find(2 * x);
			ms.erase(it);

			org.push_back(x);
		}

		return org;
	}
};