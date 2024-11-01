#include <iostream>

class Solution {
public:
    std::string makeFancyString(std::string s) {
        //string res qui va être renvoyé
        std::string res;
        int count=0;
        for(int i=0;i<s.size();i++){
            //si res n'est pas nul et si le dernier élément est la même que l'élément courrant
            if(!res.empty() && res[res.size()-1] == s[i]){
                //on augmente le compteur de même éléménet
                count++;
            }
            else{
                //sinon on le réinitialise
                count = 0;
            }
            //si l'élément est répété moins de 2x, on l'ajoute à res
            if(count<2){
                res+=s[i];
            }
        }
        return res;
    }
};

int main(){
    Solution solution;

    std::string test1 = "leeetcode";
    std::string test2 = "aaaabaaaa";
    std::string test3 = "aab";

    std::cout<<solution.makeFancyString(test1)<<std::endl;

}