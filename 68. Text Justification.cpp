#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> temp;
        if (words.size() == 0){
            return temp;
        }

        vector<vector<string> > word_lines;
        word_lines.push_back(temp);
        int size = words[0].size();
        word_lines[0].push_back(words[0]);
        for (int i=1; i<words.size(); i++){
            if ( words[i].size() + 1 + size <= maxWidth ){
                word_lines[word_lines.size()-1].push_back(words[i]);
                size += words[i].size() + 1;
            } else {
                size = words[i].size();
                word_lines.push_back(temp);
                word_lines[word_lines.size()-1].push_back(words[i]);
            }
        }

        // for (int i=0; i<word_lines.size(); i++){
        //     for (int j=0; j<word_lines[i].size(); j++){
        //         cout<<word_lines[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        for (int i=0; i<word_lines.size(); i++){
            size = 0;
            for (int j=0; j<word_lines[i].size(); j++){
                size += word_lines[i][j].size();
            }
            int spaces = maxWidth - size;
            int index = 0;
            while (spaces > 0){
                word_lines[i][index] += " ";
                index = (index + 1) % (word_lines[i].size()-1);
                spaces--;
            }
        }

        vector<string> result;
        for (int i=0; i<word_lines.size(); i++){
            result.push_back("");
            for (int j=0; j<word_lines[i].size(); j++){
                result[result.size()-1] += word_lines[i][j];
            }
        }

        return result;
    }
};

int main(void) {
    Solution s;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = s.fullJustify(words, maxWidth);
    for (int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}