class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int> arr(n+1);
       //arr[i] = ith ugly number
       //arr[n] = nth ugly number
       //return arr[n]
       int i2;
       int i3;
       int i5;

       //1st ugly number
       i2 = i3 = i5 = 1;

       //1st ugly number is 1
       arr[1]=1;

       for(int i=2;i<=n;i++){
       int i2UglyNum = arr[i2]*2;

       int i3UglyNum = arr[i3]*3;

       int i5UglyNum = arr[i5]*5;

       int minUglyNum = min({i2UglyNum, i3UglyNum, i5UglyNum});

       arr[i] = minUglyNum;

       //jiska minimum hain uske pointer ko badhate hain 

       if(minUglyNum == i2UglyNum) i2++;

       if(minUglyNum == i3UglyNum) i3++; //else if nhi lagaya kyunki kai cases main 
                                         //i3 wala aur i2 ya koi bhi do same ho rhe the
       if(minUglyNum == i5UglyNum) i5++; //jab dono min ko point krte hn toh dono ke pointers ko badha denge
       }  
       return arr[n];
    }
};
