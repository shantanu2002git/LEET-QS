class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
  

        int st=0,en=letters.size()-1,mid;
        char c='@';
        while(st<=en){
          mid=(st+en)/2;
          if(letters[mid]>target){
          c=letters[mid];
          en=mid-1;
          }else{
            st=mid+1;
          }
        }
        return (c!='@') ? c : letters[0];
    }
};