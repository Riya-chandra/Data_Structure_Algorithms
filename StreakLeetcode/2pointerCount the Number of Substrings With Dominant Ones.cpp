// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n=s.length();
//         vector<int> cumCountOne(n,0);
//         cumCountOne[0]=(s[0]=='1')?1:0;
//         for(int i=1;i<n;i++){
//             cumCountOne[i]=cumCountOne[i-1]+((s[0]=='1')?1: 0);
//         }
//         int result=0;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 //we have to knwo ki number of zeros kitne hai so simpy ij k index p chle jyege
//                 int oneCount=cumCountOne[j]-(i-1>=0?cumCountOne[i-1]:0);
//                 int zeroCount=(j-i+1)-oneCount;
//                 if((zeroCount*zeroCount) > oneCount){
//                     //skip j to avoid waste indices
//                     int wasteIndex=(zeroCount*zeroCount)-oneCount;
//                     j+=wasteIndex-1;//for loop k j++ ko avoid krne k liye 
//                 }
//                 else if((zeroCount*zeroCount) == oneCount){
//                   result+=1;
//                 }
//                 else{
//                     //valid 
//                     result+=1; //shift right j ko 
//                     int k=sqrt(oneCount)-zeroCount;
//                     int next=j+k;
//                     if(next>=n){ //out of bound
//                         result+=(n-j-1);
//                         break; //early break
//                     }
//                     else{
//                         result+=k;
//                     }
//                     j=next;
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        vector<int> cumCountOne(n, 0);
        cumCountOne[0] = (s[0] == '1') ? 1 : 0;

        for(int i = 1; i < n; i++) {
            cumCountOne[i] = cumCountOne[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        //[i...j] = cumCountOne[j] - cumCountOne[i-1];

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                int oneCount  = cumCountOne[j] - (i - 1 >= 0 ? cumCountOne[i-1] : 0);
                int zeroCount = (j - i + 1) - oneCount;

                if((zeroCount * zeroCount) > oneCount) {
                    //skip j to avoid waste indices
                    int wasteIndices = (zeroCount * zeroCount) - oneCount;
                    j += wasteIndices - 1;
                } else if((zeroCount * zeroCount) == oneCount) {
                    result += 1;
                } else { //(zeroCount * zeroCount) < oneCount
                    //[i....j] is a valid substring
                    result += 1;

                    //try to see how much j can shift to right until substring remains dominant
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;

                    if(next >= n) { //out of bound, means all indices are valid
                        result += (n - j - 1);
                        break; //early break
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;

    }
};
