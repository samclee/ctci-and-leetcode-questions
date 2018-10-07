#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        
        int maxArea = 0;
        
        while (l < r) {
            int hgtL = height[l], hgtR = height[r];
            
            maxArea = max(maxArea, (r - l) * min(hgtL, hgtR));
            
            if (hgtL <= hgtR)
                l++;
            if (hgtL >= hgtR)
                r--;
        }
        
        return maxArea;
}

int main() {
	
	vector<int> testVec{1,8,6,2,5,4,8,3,7};

	int area = maxArea(test);

	cout << area << '\n';


	return 0;
}