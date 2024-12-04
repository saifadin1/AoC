#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> grid = readInput("../2024/day4/input.txt");
    
    const int dirX[] = {1 , -1 , 0 , 0 , 1 , 1 , -1 , -1};
    const int dirY[] = {0 , 0 , 1 , -1 , 1 , -1 , -1 , 1};

    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    auto valid = [&](const int r , const int c){
        return r < n && c < m && r >= 0 && c >= 0; 
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'X'){
                for(int k=0; k<8; k++){
                    string word = "X";
                    for(int mul=1; mul<4; mul++){
                        int ni = i + dirX[k] * mul;
                        int nj = j + dirY[k] * mul;
                        if(valid(ni , nj)){
                            word.push_back(grid[ni][nj]);
                        }
                    }
                    ans += word == "XMAS";
                }
            }
        }
    }

    cout << ans << '\n';  

    return 0;
}


// X:  1  -1  0  0  1  1 -1 -1         ( * 1) .. ( * 4) 
// Y:  0  0  1  -1  1 -1 -1  1