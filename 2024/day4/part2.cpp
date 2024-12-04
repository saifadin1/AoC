#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> grid = readInput("../2024/day4/input.txt");

    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    const string MAS = "MAS";
    const string SAM = "SAM"; 

    auto valid = [&](const int r , const int c){
        return r < n && c < m && r >= 0 && c >= 0; 
    };

    auto checkDiag = [&](const int r , const int c , const int mul){
        if(valid(r , c) &&
           valid(r + 1 , c + 1 * mul) &&
           valid(r + 2 , c + 2 * mul)){
            string word;
            word.push_back(grid[r][c]);
            word.push_back(grid[r + 1][c + 1 * mul]);
            word.push_back(grid[r + 2][c + 2 * mul]);
            if(word == MAS || word == SAM){
                return true;
            }
        }

        return false;
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] ^ '.'){
                ans += (checkDiag(i , j , 1) & checkDiag(i , j + 2 , -1));
            }
        }
    }

    cout << ans << '\n';  

    return 0;
}