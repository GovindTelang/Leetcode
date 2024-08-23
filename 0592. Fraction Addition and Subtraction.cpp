class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        int i=0;
        int num = 0;
        int den = 1;
        while(i<n){
            int new_num=0;
            int new_den=0;
            bool isNeg = (expression[i]=='-');
            if(expression[i]=='+' || expression[i]=='-') i++;
            while(i<n && isdigit(expression[i])){
                new_num = new_num*10 + (expression[i]-'0');
                i++;
            }

            if(isNeg==1) new_num *= -1;
            i++; //to get ahead of '/'

            while(i<n && isdigit(expression[i])){
                new_den = new_den*10 + (expression[i]-'0');
                i++;
            }
            num = num*new_den + new_num*den;
            den = den*new_den;
        }

        int gcd = __gcd(num,den);
        num /= abs(gcd);
        den /= abs(gcd);
        return to_string(num)+'/'+to_string(den); //abs isliye as example num=-1 && den=3 gcd will be -1 and result will be 1/3 which is wrong 
    }
};
