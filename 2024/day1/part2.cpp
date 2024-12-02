#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day1/input.txt");

    int ans = 0;
    vector<int> a;
    map<int , int> mp;

    for(string line : input){
        istringstream ss(line);
        int x , z;
        ss >> x >> z;
        a.push_back(x);
        mp[z]++;
    }

    for(int i : a){
        ans += i * mp[i];
    }

    cout << ans << '\n';
    
    return 0;
}
