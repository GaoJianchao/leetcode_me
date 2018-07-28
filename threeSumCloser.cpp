#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int threeSumCloser(vector<int> &nums, int target){
	sort(nums.begin(), nums.end());
	int res = nums[0] + nums[1] + nums[2];
	int n = nums.size();
	for(int i = 0; i < n && res != target; i++){
		if(i && nums[i] == nums[i-1])  continue;
		int low = i + 1;
		int height = n - 1;
		while(low < height){
			int temp = nums[i] + nums[low] + nums[height];
			if(abs(temp - target) < abs(res - target)){
				res = temp;
			}
			if(temp < target) low++;
			else if(temp > target) height--;
			else break;
		}
	}
	return res;
}

int main(){
	int num[] =  {1, 2, 9, 5, 6, 2, 3, 8};
	vector<int> nums(num, num+8);
	cout << threeSumCloser(nums, 30)<<endl;
}