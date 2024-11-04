#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        // if only 1 element return 0 since cannot trap with this width
        if (height.size() == 1){
            return 0;
        }

        vector<int> c(height.size(), 0);
        int water = 0;
        int left = 0;
        int right = 0;
        int current_index = 0;
        int current = 0;
        int index = 0;

        // skip empty start to heights
        while (index < height.size() && height[index] == 0){
            index++;
        }

        // iterate starting positions of potential trapping sections
        while (index < height.size()){
            left = height[index];
            current_index = index + 1;
            current = 0;
            while (current_index < height.size()){
                if (height[current_index] < left){
                    current += left - height[current_index];
                    c[current_index] = left - height[current_index];
                } else { // if the right size is equal or higher, add capture space and set index to current_index
                    water += current;
                    index = current_index;
                    break;
                }
                current_index++;
            }

            if (current_index != index){
                index++;
            }
        }

        cout<<"catching sections -> ";
        for (int i=0; i<c.size(); i++){
            cout<<c[i];
        }
        return water;
    }
};

int main(void){

    // set up testing environment
    Solution s;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = s.trap(input);
    cout<<"\nResult: "<<result<<"\n";
    
}