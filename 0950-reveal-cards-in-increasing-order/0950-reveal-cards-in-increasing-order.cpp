class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>res(n);
        sort(deck.begin(), deck.end());

        queue<int>q;
        for(int i=0; i<n; i++){
            q.push(i);
        }

        for(int j=0; j<n; j++){
            int idx=q.front(); q.pop(); //0
              res[idx]=deck[j];
              if(!q.empty()){
                int nxt=q.front(); 
                q.pop();
                q.push(nxt);
               
              }
        }

        return res;
    }
};