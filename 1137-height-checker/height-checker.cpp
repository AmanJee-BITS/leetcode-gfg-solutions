class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> SortedHeights(heights);
        sort(SortedHeights.begin(),SortedHeights.end());
        
        int ans=0;
        
        for(int i=0;i<heights.size();++i){
            ans+=heights[i]!=SortedHeights[i];
        }
        
        return ans;
    }
};