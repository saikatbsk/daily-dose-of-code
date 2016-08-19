#include <iostream>
#include <unordered_map>
#include <map>

using std::string;
using std::unordered_map;
using std::map;
using std::cout;
using std::endl;

int main() {
    map<int, string> map;

    map[20] = "abc";
    map[10] = "xyz";

    for(auto element : map) {
        cout << element.first << " "
             << element.second << endl;
    }

    cout << endl;

    unordered_map<int, string> map2;

    map2[20] = "abc";
    map2[10] = "xyz";

    for(auto element : map2) {
        cout << element.first << " "
             << element.second << endl;
    }

    cout << endl;

    if(map2.find(10) != map2.end())
        cout << "Found!";
}
