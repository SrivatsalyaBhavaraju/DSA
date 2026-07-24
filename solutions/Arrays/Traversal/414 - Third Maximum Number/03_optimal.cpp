class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long f_max=LLONG_MIN;
        long long s_max=LLONG_MIN;
        long long t_max=LLONG_MIN;
        for(int x: nums){
            if(x==f_max || x==s_max || x==t_max){
                continue;
            }
            if(x>f_max){
                t_max=s_max;
                s_max=f_max;
                f_max=x;
            
            }else if(f_max>x && x>=s_max){
                t_max=s_max;
                s_max=x;
            }else if(x<s_max && x>=t_max){
                t_max=x;
            }
            else{
                cout << "invalid Number";
            }
        }
     if(t_max == LLONG_MIN){
            return f_max;
        }
        return t_max;
}
       
    
};