
class Solution {
public:
    long long smallestNumber(long long num) {
        
       string si = to_string(abs(num));
        if(num>=0){
           sort(si.begin(),si.end());
        }else{
            sort(si.begin(),si.end(),greater<char>());
        }
        if(num>0){
            int sw_idx;
        //    sw_idx=si.find_first_not_of('0');
        for(int i=0; i<si.size(); i++){
            if(si[i]!='0'){
                  sw_idx=i;
                  break;
            }
        }
            swap(si[0],si[sw_idx]);
        }
        long long res=stoll(si);
        if(num<0){
           res=res*-1;
        }
        return res;
    }
};
