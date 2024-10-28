#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        // Utilisation d'un unordered_set pour des recherches rapides
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        int res = -1;

        // Pour chaque nombre dans le tableau
        for(int num : nums) {
            int tempRes = 0;

            //on vérifie si l'élément ne dépase pas 317 car 317^2 > 100000 et 100000 ne se trouve pas dans la liste
            if(num>317){
                continue; 
            }

            int current = num;

            // Vérification des carrés successifs
            while (numSet.find(current) != numSet.end()) {
                // On a trouvé un nombre dans la suite des carrés
                tempRes++;  
                
                //on fait la même vérification pour éviter l'overflow
                if(current>317){
                    break;; 
                }  
                current*=current; // Calcul du carré suivant
            }

            // Mettre à jour le résultat final si la séquence trouvée est plus longue
            if (tempRes > 1 && tempRes > res) {
                res = tempRes;
            }
        }

        return res;
    }
};


int main(){
    std::vector<int> tab = {
        4,3,6,16,8,2
    };

    Solution solution;

    int res = solution.longestSquareStreak(tab);

    std::cout<<"\n"<<res<<std::endl;

}