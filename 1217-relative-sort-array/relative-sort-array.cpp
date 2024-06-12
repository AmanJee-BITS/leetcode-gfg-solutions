class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> b;
        vector<int> c;
        
        for(int i=0; i<arr1.size(); i++){
            int count = 0;
            for(int j=0; j<arr2.size(); j++){
                if(arr1[i] == arr2[j])
                    count++;
            }
            if(count == 0){
                c.push_back(arr1[i]);
            }
        }
        
        for(int i = 0; i<arr2.size(); i++){
            //int count = 0;
            for(int j =0; j<arr1.size(); j++){
                if(arr2[i] == arr1[j]){
                    b.push_back(arr1[j]);
                    //count++;
                }
            }
            
        }
        sort(c.begin(), c.end());
        for(int i =0; i<c.size(); i++){
            b.push_back(c[i]);
        }
        return b;
    }
};