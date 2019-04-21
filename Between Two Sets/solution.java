import java.util.*;
import java.math.*;


public class Solution {
 
    static int getTotalX(int[] a, int[] b) {
        /*
         * Write your code here.
         */

        Arrays.sort(b);
        int sentinel = b[0];
        int x = 1;
        int ans = 0;
        boolean check = true;

        while(x <= sentinel) {
            for(int i = 0; i < a.length; i++) {
                if(x % a[i] != 0) { 
                    check = false;
                    break; }
            }
            if(check) {
                for(int j = 0; j < b.length; j++) {
                    if(b[j] % x != 0) { 
                        check = false;
                        break; }
                }
                if(check) {
                    ans += 1;
                }
            }
            check = true;
            x += 1;
        } 
        return ans;
    }
}