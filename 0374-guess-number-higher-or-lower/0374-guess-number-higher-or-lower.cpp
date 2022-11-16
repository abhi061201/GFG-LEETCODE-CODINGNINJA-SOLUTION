/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans, l=1, h= n;
        while(1)
       {
           ans= (h-l)/2 +l;
            int temp= guess(ans);
            if(temp== 0)return ans;
            
            if(temp ==1)
            {
                l= ans+1;
            }
            else h= ans-1;
       }
        return l;
    }
};