class Solution {
public:
    int minSwaps(string s) {
     /* int stacksize = 0;
      int n = s.size();
      for(int i=0;i<n;i++){
        char ch = s[i];
        if(ch=='[') stacksize++;
        else if(stacksize>0) stacksize--;
      }
      return (stacksize+1)/2;  */
    int n = s.size();
	int balance = 0, swaps = 0, j=n-1;
	for(int i=0; i<n; i++)
	{
		if(s[i] == '[') balance++;
		else balance--;

		if(balance < 0)
		{
			while(i<j && s[j] != '[') j--;
			swap(s[i], s[j]);
			swaps++;
			balance = 1;
		}
	}
	return swaps;
    }
};
