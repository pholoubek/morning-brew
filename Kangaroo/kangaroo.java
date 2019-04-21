public class Solution {
    /*
        Kangaroo solution
        Given starting position of two kangaroos at x1 x2 and their respective speed of v1 and v2
        calculate whether they'll meet with the same number of discrete steps

        Complexity: O(1) 
    */
    static String kangaroo(int x1, int v1, int x2, int v2) {
        double n = (double)(x1 - x2) / (v2 - v1);
        if(n <= 0) { 
            return "NO"; 
        } else { 
            return (n == (int)n ? "YES" : "NO"); 
        }
    }
}