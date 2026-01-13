// Pages: [12, 34, 67, 90]
// Students: 3
// Output: 113
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxPages) {

    int students=1;
    page=0;
    for(int i=0;i<n;i++){
 if(arr[i]>maxPages) return false;
 if(pages+arr[i]>maxPages){
    students++;
    pages=arr[i];
 }else{
    pages+=arr[i];
 }
    }
   return students<=m;

}
int allocateBooks(vector<int>& arr, int n, int m) {
    if(m>n) return -1;  //m=student n=books number
   int low=*max_element(arr.begin(),arr.end()); //max ele
   int high=accumulate(arr.begin(),arr.end()); //sum of all
   int ans=-1;

   while(low<=high){
    int mid=(low+high)/2;
    if(isPossible(arr,n,m,mid)){
        ans=mid;
        high=mid-1;
    } else{
        low=mid+1;
    }
   }
   return ans;
}


int main() {
    vector<int> arr = {12, 34, 67, 90};
    int students = 2;
    cout << allocateBooks(arr, arr.size(), students);
    return 0;
}