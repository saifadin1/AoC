#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day1/input.txt");

    int ans = 0;
    vector<int> a , b;
    for(string line : input){
        istringstream ss(line);
        int x , z;
        ss >> x >> z;
        a.push_back(x);
        b.push_back(z);
    }

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    for(int i = 0 ; i < a.size() ; i++){
        ans += abs(a[i] - b[i]);
    }
    cout << ans << '\n';

    return 0;
}
