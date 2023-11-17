class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    int prv = -1, c = 0, winner = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      if (arr[i] > winner) {
        winner = arr[i];
        c = 1;
      } else {
        c++;
      }
      if (c >= k) {
        break;
      }
    }
    return winner;
  }
};
