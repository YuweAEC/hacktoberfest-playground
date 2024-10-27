// This programme implements the Dyanamic Programming
class Solution {
  public:
    int countNumberswith4(int n) {
    // Intialise the count
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        std::string numStr = std::to_string(i);
        if (numStr.find('4') != std::string::npos) {
            count++;
        }
    }
    return count;
        
    }
};