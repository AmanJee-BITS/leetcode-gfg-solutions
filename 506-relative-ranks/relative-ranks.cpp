class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> output(score.size()); //to be returned from the method
        priority_queue<pair<int,int>> maxH; //to store <score, corresponding index>
        
        for(int i=0;i<score.size();i++) maxH.push({score[i], i});
        
        int position = 1;
        while(!maxH.empty()){
            pair<int,int> p = maxH.top();
            maxH.pop();
            if(position<=3){
                string medal = (position==1)?"Gold Medal" : 
                               ((position==2)?"Silver Medal":"Bronze Medal");
                output[p.second]  = medal;
                position++;
            }else{
                int ranked = position++;
                output[p.second] = to_string(ranked);
            }
        }
        return output;
    }
};