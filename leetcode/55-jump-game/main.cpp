#include <iostream>
#include <vector>
using std::cout;
using std::vector;

bool canJump(vector<int>& nums) {
	for (int i = nums.size()-1; i >= 0; i--) {
		if (nums[i] == 0) {
			int scan = i-1;
			while (scan >= 0) {
				if (nums[i] > i - scan) {
					i = scan;
					break;
				}
				scan--;
			}
		}
	}       
}

int main() {

	

	return 0;
}