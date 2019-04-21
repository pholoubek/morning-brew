public class Solution {

    // Complete the maximumToys function below.
    static int maximumToys(int[] prices, int k) {
        long start = System.nanoTime();
        Arrays.sort(prices); // ascending
        int count = 0;
        for(int price : prices) {
            if (k - price >= 0) {
                count += 1;
                k -= price;
            } else {
                break;
            }
        }
        System.out.println("it took " + (System.nanoTime() - start));
        return count;
    }
    
}
