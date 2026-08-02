
class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() {

    }

    int next(int price) {
        prices.push_back(price);

        int span = 1;
        int i = prices.size() - 2;

        while (i >= 0 && prices[i] <= price) {
            span++;
            i--;
        }

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */