class Cashier {
public:
    int n, discount, i=1;
    vector<int> products, prices;
    unordered_map<int,int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->discount=discount;
        this->products=products;
        this->prices=prices;
        for(int i=0;i<products.size();i++){
            mp[products[i]]=i;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double res=0.0;
        for(int i=0;i<product.size();i++){
            res+=(prices[mp[product[i]]]*amount[i]);
        }
        if(i%n==0){
            res=((100.0-discount)*res)/100.0;
        }
        i++;
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */