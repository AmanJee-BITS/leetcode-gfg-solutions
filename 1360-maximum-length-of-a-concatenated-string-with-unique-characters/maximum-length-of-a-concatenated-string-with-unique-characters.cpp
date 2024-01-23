class Solution {
  int ans = 0;

 public:
  int maxLength(vector<string>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
      dfs(arr, i, {});
    }

    return ans;
  }

  void dfs(vector<string>& arr, int idx, unordered_set<char> seen) {
    for (auto c : arr[idx]) {
      if (seen.count(c)) {
        return;
      } else {
        seen.insert(c);
      }
    }

    ans = max(ans, (int)seen.size());

    for (int i = idx + 1; i < arr.size(); ++i) {
      dfs(arr, i, seen);
    }
  }
};