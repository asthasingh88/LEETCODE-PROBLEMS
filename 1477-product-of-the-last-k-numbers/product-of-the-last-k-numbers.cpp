class ProductOfNumbers {
public:
    vector<int> pprod;

    ProductOfNumbers() { pprod.push_back(1); }

    void add(int num) {
        if (num == 0) {
            pprod.clear();
            pprod.push_back(1);
            return; // don't push the 0 itself
        }
        pprod.push_back(pprod.back() * num);
    }

    int getProduct(int k) {
        int size = pprod.size();
        if (size <= k) { // a zero lies within the last k numbers
            return 0;
        }
        return pprod[size - 1] / pprod[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */