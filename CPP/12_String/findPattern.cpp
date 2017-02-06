#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using std::string;
using std::to_string;
using std::unordered_set;
using std::unordered_map;
using std::cout;
using std::endl;

string encodeStr(string str) {
    unordered_map<char, int> map;
    string hash;
    int i = 0;
    int len = str.length();

    for(int j=0 ; j<len ; j++) {
        char ch = str.at(j);

        if(map.find(ch) == map.end())
            map[ch] = i++;

        hash += to_string(map[ch]);
    }

    return hash;
}

void findMatches(unordered_set<string> dict, string pattern) {
    int len = pattern.length();
    string hash = encodeStr(pattern);

    for(auto iter=dict.begin() ; iter!=dict.end() ; iter++) {
        string word = *iter;

        if(word.length() == len && encodeStr(word) == hash)
            cout << word << " ";
    }

    cout << endl;
}

int main() {
    unordered_set<string> dict = {"xyy", "xyz", "kkk", "pyy"};
    string pattern = "abb";

    findMatches(dict, pattern);

    return 0;
}
