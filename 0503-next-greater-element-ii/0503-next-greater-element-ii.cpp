vector<int> nextGreaterElement(vector<int> &nums2)
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
  res.erase(res.begin()+n/2, res.end());
  return res;
}
class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    vector<int> nw = nums;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      nw.push_back(nums[i]);
    }

    return nextGreaterElement(nw);
  }
};