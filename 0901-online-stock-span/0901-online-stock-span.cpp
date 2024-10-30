#include <vector>

class StockSpanner {
public:
    StockSpanner() {
        // Initialize the member variables to store prices and spans.
        stock.clear();
        ans.clear();
    }
    
    int next(int price) {
        stock.push_back(price);
        int span = 1;  // Start with a span of 1 for the current price itself.

        // Calculate the span by checking previous prices in the stock vector.
        int i = stock.size() - 2;
        while (i >= 0 && stock[i] <= price) {
            span++;
            i--;
        }
        
        ans.push_back(span);  // Store the calculated span in ans.
        return span;  // Return the span for the current price.
    }

private:
    std::vector<int> stock; // Vector to store the list of prices.
    std::vector<int> ans;   // Vector to store the list of spans.
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

