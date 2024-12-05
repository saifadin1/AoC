#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day5/input.txt");

    vector<vector<int>> matrix(100 , vector<int>(100));
    int ans = 0;

    int i=0;
    for(;; i++){
        if(input[i].size() > 5 || input[i].size() < 2) {
            break;
        }
        string x1 = input[i].substr(0 , 2);
        string x2 = input[i].substr(3 , 2);
        int u = stoi(x1);
        int v = stoi(x2);
        matrix[u][v] = 1;
    }

    for(;i<input.size(); i++){
        vector<int> temp;
        for(int j=0; j+1<input[i].size(); j++){
            string str = input[i].substr(j , 2);
            int x = stoi(str);
            temp.push_back(x);
            j+=2;
        }
        bool ok = true;
        int mid = 0;
        for(int j=0; j+1<temp.size(); j++){
            if(matrix[temp[j]][temp[j + 1]] == 0){
                ok = false;
                break;
            }
            if(j == temp.size() / 2){
                mid = temp[j];
            }
        }
        if(ok){
            ans += mid;
        }
    }

    cout << ans <<'\n';
    return 0;
    
}
