#include <iostream>
#include <vector>
using namespace std;

int subSort(vector<int> &nums, int low, int height){
	int key = nums[low];
	while(low < height){
		while(low < height && nums[height] >= key) height--;
		nums[low++] = nums[height];
		while(low < height && nums[low] <= key) low++;
		nums[height--] = nums[low];
	}
	nums[low] = key;
	return low;
}

void quickSort(vector<int> &nums, int low, int height){
	int index;
	if(low < height){
		index = subSort(nums, low, height);
		quickSort(nums, low, index-1);
		quickSort(nums,index+1, height);
	}
}

int main(){
	int num[5]= {10,1,9,3,11};
	vector<int> nums(num, num+sizeof(num)/sizeof(num[0]));
	int i;
	quickSort(nums, 0, nums.size()-1);
	for(vector<int>::iterator i = nums.begin(); i!=nums.end(); i++){
		cout<<*i<<" ";
	}
	cout << endl;
} 