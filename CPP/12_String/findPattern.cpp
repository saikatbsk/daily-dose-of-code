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
    int i = 0;
    string hash = "";

    for(char ch : str) {
        if(map.find(ch) == map.end())
            map[ch] = i++;

        hash += to_string(map[ch]);
    }

    return hash;
}

void findMatches(unordered_set<string> dict, string pattern) {
    int len = pattern.length();
    string hash = encodeStr(pattern);

    //-- For every string in dictionary
    for(string word : dict) {
        if(hash == encodeStr(word) && len == word.length())
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
