#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows > s.size()){
            return s;
        }

        vector<string> zigzag(numRows, "");
        int index = 0;
        while (index < s.size()){

            for (int i=0; i<numRows; i++){
                if (index != s.size()){
                    zigzag[i] += s[index];
                    index++;
                }
            }

            for (int i=0; i<numRows-2; i++){
                if (index == s.size()){
                    break;
                }
                for (int j=numRows-1; j>=0; j--){
                    if (j == numRows-2-i){
                        zigzag[j] += s[index];
                        index++;
                    } else {
                        zigzag[j] += ' ';
                    }
                }
            }
        }

        for (int i=0; i<zigzag.size(); i++){
            cout<<zigzag[i]<<'\n';
        }

        string result = "";
        for (int i=0; i<zigzag.size(); i++){
            result += zigzag[i];
        }
        return result;
    }
};

int main(void) {
    Solution s;
    string input = "PAYPALISHIRING";
    string result = s.convert(input, 3);
    cout<<"Result: "<<result;
    return 0;
}