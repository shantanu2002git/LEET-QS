class ProductOfNumbers {
public:
set<int>st; //track the zero index
int index=0, mul=1;
map<int,int>mpmul;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0){
            num=1;
            st.insert(index);
        }
      mpmul[index]=mpmul*num;
      mpmul=mpmul*num;

    }
    
    int getProduct(int k) {
        int n=mp.size();
        return (mpmul[n-1])/mpmul[n-1-k];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */