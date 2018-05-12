#include<list>
#include<vector>
#include<iostream>

using namespace std;

int times = 0;

int find_max(vector<pair<int, int>>& comp, vector<int>& nums, int begin, int end) {
	if ((end - begin) > 1) {
		int left_index = find_max(comp, nums, begin, (begin + end) / 2);
		int right_index = find_max(comp, nums, (begin + end) / 2, end);
		if (nums[left_index] < nums[right_index]) {
			times++;
			pair<int, int> comp_pair(left_index, right_index);
			comp.push_back(comp_pair);
			return right_index;
		}			
		else {
			times++;
			pair<int, int> comp_pair(right_index, left_index);
			return left_index;
			comp.push_back(comp_pair);
		}
			
	}
	else
		return begin;
}

int find_2rd_biggest(vector<pair<int, int>>& comp, vector<int>& nums) {
	int current_max = -1;
	int index = find_max(comp, nums, 0, nums.size());
	for (vector<pair<int, int>>::iterator iter = comp.begin(); iter < comp.end(); ++iter) {
		pair<int, int> comp_pair = *iter;
		if ((*iter).second == index) {
			times++;
			if (nums[(*iter).first]>current_max)
				current_max = nums[(*iter).first];
		}
	}
	return current_max;
}

int main() {
	vector<pair<int, int>> comp;
	vector<int> nums = {1, 2, 3, 4,5,6,7,8};
	int result = find_2rd_biggest(comp, nums);
	cout << "the 2rd biggest is:"<<result << endl;
	cout << "comparisons" << times -1 << endl;

	getchar();
	return 0;
}