#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; // Because Excel columns start from 1
            int rem = columnNumber % 26;
            char ch = 'A' + rem;
            result = ch + result;
            columnNumber /= 26;
        }

        return result;
    }
};
