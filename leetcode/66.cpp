#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        //on utilise la même technique que l'addition classique, en allant de la fin au début
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1; 
                return digits;  
            }
            digits[i] = 0;  
        }
        
        //si on n'a toujours pas réussi à placer la retenue c'est qu'il faut ajouter un '1' au début
        digits.insert(digits.begin(), 1); 
        return digits;
    }
};


void printVect(std::vector<int> vect){
    for(int i:vect){
        std::cout<<i;
    }
    std::cout<<std::endl;
}

int main(){
    Solution solution;

    std::vector<int> vect1;
    std::vector<int> vect2;

    vect1 = {
        9,8,7,6,5,4,3,2,1,0
    };
    
    vect2 = {
        9,9,9
    };


    std::vector<int> res = solution.plusOne(vect1);
    std::vector<int> re2 = solution.plusOne(vect2);

    printVect(res);
    printVect(re2);
}