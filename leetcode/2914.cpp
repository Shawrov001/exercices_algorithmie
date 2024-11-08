#include <iostream>

class Solution {
public:
    int minChanges(std::string s) {
        int size = s.size();
        char first = s[0];
        int res = 0;

        for(int i =1;i<size;i+=2){
            char second = s[i];
            if(first != second){
                res++;
            }
            first = s[i+1];
        }
        return res;
    }
};

int main(){
    Solution solution;
    int res;


    std::string test1 = "1001";
    std::string test2 = "0000";
    std::string test3 = "00110011";


    res = solution.minChanges(test1);
    std::cout<<res<<" ";
    
    res = solution.minChanges(test2);
    std::cout<<res<<" ";

    res = solution.minChanges(test3);
    std::cout<<res<<" ";

    std::cout<<std::endl;

}