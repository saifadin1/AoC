#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day3/input.txt");

    // "mul(" , "int" , "," , "int" , ")"

    auto isValid = [](const string& str){
        // valid if str in this form <int>,<int>
        
        
        auto isNum = [](const string&  num) {
            if(num.size() == 0) {
                return false;
            }
            for(auto& c : num) {
                if(isdigit(c) == false) {
                    return false;
                }   
            }
            return true;
        };
        
        string int1 , int2;
        for(int i=0; i<str.size(); i++) {
            if(str[i] == ',') {
                int1 = str.substr(0 , i);
                int2 = str.substr(i + 1);
                break;
            }
        }
        if(isNum(int1) && isNum(int2)) {
            return stoll(int1) * stoll(int2);
        }
        return -1LL;
    };

    int ans = 0;
    bool enabled = true;
    for(auto& line : input) {
        for(int i=0; i<line.size(); i++){
            if(i + 4 < line.size() && line.substr(i , 4) == "do()"){
                enabled = true;
            } else if(i + 7 < line.size() && line.substr(i , 7) == "don't()"){
                enabled = false;
            }
            if(enabled && i + 4 < line.size() && line.substr(i , 4) == "mul("){
                int end = line.find_first_of(')' , i + 4);   
                if(end != string::npos) {
                    string str = line.substr(i + 4 , end - i - 4);
                    // cout << str << '\n';
                    if(isValid(str) != -1) {
                        ans += isValid(str);
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}


// mul(32,32)