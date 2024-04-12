class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        if (!n) 
            return 0;
        
        int left_max[n], right_max[n];
        
        left_max[0] = a[0];
        right_max[n-1] = a[n-1];
        
        for (int i = 1; i < n; i++)
            left_max[i] = max(left_max[i-1],a[i]);
        
        for (int i = n-2; i >= 0; i--)
            right_max[i] = max(right_max[i+1],a[i]);
        
        int sum = 0;
        
        for(int i = 1; i < n - 1; i++) {
            if (min(left_max[i-1],right_max[i+1]) - a[i] > 0)
                sum += min(left_max[i-1],right_max[i+1]) - a[i];
        }
        return sum;
        
    }
};