//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        if(str[n-1] == '0') return str;
        if (n< 2){
            if(str[0]-'0' >= 5){
                return "10";
            }
            return "0";
            
        }
        if(str[n-1]-'0'>5){
            int k = n-2;
            while(k>=0 && str[k]=='9'){
                str[k] = '0';
                k--;
            }
            if(k== -1) str = "1" + str;
            else str[k]+=1;
        }
        n = str.size();
        str[n-1] = '0';
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends