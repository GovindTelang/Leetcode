class Solution {
public:
//my approach 
    int findComplement(int num) {
      int num_bits = 1+(int)log2(num);  
      for(int i=0;i<num_bits;i++){
        num^=(1<<i);
      }
      return num;
    }
};
//2 more mik approaches
//approach 2
/*int num_bits = 1+(int)log2(num);  
unsigned int mask = (1U << num_bits)-1; 
return num^mask;
//1000 - 1 = 111/*

//approach 3
/*int i=0;
int compliment=0;
while(num){
    if(!(num&1)) //if it is a 0 then we need to flip it
    {compliment |= (1<<i);}
    num>>=1; right shifting num
    i++;
}
return compliment;
*/
