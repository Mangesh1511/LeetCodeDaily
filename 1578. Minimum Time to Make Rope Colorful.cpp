// 1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int prev = 0;
        int minColorCost = 0;
        for(int i=1;i<colors.size();i++){

                if(colors[i] == colors[prev]){
                    int k = i-1;
                    int maxof = neededTime[k];
                    while(colors[k] == colors[prev]){
                        maxof = max(neededTime[k],maxof);
                        minColorCost += neededTime[k];
                        k++;
                    }
                    minColorCost -= maxof;
                    i = k-1;
                }
                else{
                    prev = i;
                }
        }   
        return minColorCost;

    }
};