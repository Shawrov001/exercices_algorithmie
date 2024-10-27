#include <iostream>
#include <vector>
#include <algorithm> 

class Solution {
public:

    int threeSumClosest(std::vector<int>& nums, int target) {
        // Étape 1: Trier le tableau
        std::sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialiser la somme la plus proche

        // Étape 2: Parcourir le tableau
        for (size_t i = 0; i < nums.size(); ++i) {
            size_t left = i + 1; // Pointeur gauche
            size_t right = nums.size() - 1; // Pointeur droit
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Vérifier si la somme actuelle est plus proche du target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Déplacer les pointeurs en fonction de la somme actuelle
                if (currentSum < target) {
                    ++left; // Augmenter la somme
                } else if (currentSum > target) {
                    --right; // Diminuer la somme
                } else {
                    // Si la somme actuelle est égale au target, nous avons trouvé la meilleure réponse
                    return currentSum;
                }
            }
        }

        return closestSum; // Retourner la somme la plus proche trouvée
    }
};



int main(){
    std::vector<int> testTab = {1,1,1,1};
    Solution solution;


    int test = solution.threeSumClosest(testTab,-100);
    std::cout<<test<<std::endl;
}