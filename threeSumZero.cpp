#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSumZero(vector<int> nums){
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	int n = nums.size();
	for(int i = 0; i < n; i++){
		if(i && nums[i] == nums[i-1]) continue;
		int low = i + 1;
		int height = n - 1;
		while(low < height){
			if(low !=low+1 && nums[low] == nums[low-1]) low++;
			else if(height != height-1 && nums[height] == nums[height+1]) height--;
			else if(nums[i] + nums[low] + nums[height] > 0) height--;
			else if(nums[i] + nums[low] + nums[height] < 0) low++;
			else{
				int m[] = {nums[i],nums[low],nums[height]};
                res.push_back(vector<int>(m, m+3));
				low++;
				height--;
			}
		}
	}
	return res;
}
int main(){
	int num[] = {1, 2, 9, 5, -6, 2, 3, -5};
	vector<int> nums(num, num+8);
	vector<vector<int> > res = threeSumZero(nums);
	cout << res.size() <<endl;
}