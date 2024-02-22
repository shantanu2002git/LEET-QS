class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    stack<int> st;
    int n = nums2.size();
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums2[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        res.push_back(-1);
      }
      else
      {
        res.push_back(st.top());
      }
      st.push(nums2[i]);
    }
    reverse(res.begin(), res.end());
    for (auto it : res)
    {
      // cout << it << " ";
    }
    map<int, int> mp;
    int k = 0;
    for (auto it : nums2)
    {
      mp[it] = res[k++];
    }
    vector<int> returnVec;
    for (auto it : nums1)
    {
      returnVec.push_back(mp[it]);
    }
    return returnVec;
  }
};