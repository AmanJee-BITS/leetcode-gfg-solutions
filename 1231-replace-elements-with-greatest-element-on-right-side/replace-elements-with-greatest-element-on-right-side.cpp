class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_so_far = -1;

        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i] > max_so_far){
                int temp = arr[i];
                arr[i] = max_so_far;
                max_so_far = temp;
            } else{
                arr[i] = max_so_far;
            }
        }

        return arr;
    }
};