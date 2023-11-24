class Solution
{
public:
  vector<int>ans;
  void call(int num, int n, int p)
  {
    if (0 == n)
    {
      if (ans.empty() || ans.back() != num)
       {  //To avoid duplicate answers when lastDigit-k == lastDigit+k
        ans.push_back(num);
       }
      return;
    }

    int lstd = num % 10;
    if (lstd + p <= 9)
    {
      call(num * 10 + (lstd + p), n - 1, p);
    }

    if (lstd - p >= 0) // changed to if statement
    {
      call(num * 10 + (lstd - p), n - 1, p); // changed (lstd + p) to (lstd - p)
    }

    return;
  }
  vector<int> numsSameConsecDiff(int n, int k)
  {

    for (int i = 1; i <= 9; i++)
    {
      call(i, n-1, k);
    }
    return ans;
  }
};
