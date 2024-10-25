class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int k=height.size()-1;
        std::vector<int> solution ={0};


        while(i!=k){
            solution.push_back(min(height[k],height[i])*(k-i));
            if(height[i]<height[k]){
                i++;
            }
            else{
                k--;
            }
        }
        return *max_element(solution.begin(), solution.end());
    }
};