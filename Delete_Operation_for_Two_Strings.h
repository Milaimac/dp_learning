#include"head.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int count = 0;
        unordered_map<int, int> re_index;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word1[i] == word2[j]){
                    pair<int, int> tmp{i,j};
                    re_index.insert(tmp);
                }
            }
        }
        int size = re_index.size();
        cout << size << endl;
        for(auto bg = re_index.begin();bg != re_index.end();bg++){
            for(auto it = bg;it!=re_index.end();it++){
                //seaaa
                //eat
                // cout <<it->first << " " << it->second <<endl;
                if(bg->first == it->first && bg->second != it->second){
                    size--;
                    cout << "first del " << size << endl;
                    
                }
                if(bg->second == it->second && it->first != bg->first){
                    size--;
                    cout << "second del " << size << endl;
                    cout <<it->first << " " << it->second <<endl;
                    cout << bg->first << " " << bg->second << endl;
                }
            }
        }
        count += n-size;
        count += m-size;
        return count;
    }
};