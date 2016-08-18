#include <iostream>
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
    string hash = "";
    int i = 0;

    for(char ch : str) {
        if(map.find(ch) == map.end())
            map[ch] = i++;

        hash += to_string(map[ch]);
    }

    return hash;
}

void findMatches(unordered_set<string> dict, string pattern) {
    int length = pattern.length();

    string hash = encodeStr(pattern);

    //-- For each word in dictionary
    for(string word : dict) {
        if(word.length() == length && encodeStr(word) == hash) {
            cout << word << " ";
        }
    }
}

int main() {
    unordered_set<string> dict = { "abb", "abc", "xyz", "xyy" };
    string pattern = "foo";

    findMatches(dict, pattern);

    cout << endl;

    return 0;
}
