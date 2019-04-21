// This algo is still O(n*n) time complexity but has a little optimization quirk
// Due to hackerrank assumptions we know that 1<= N <= 10^5
// Also we know that 1<=arr[i]<=N. Then we have implicit 
// number line composed of indexes against we can compare
// the given array. 

// if(arr[i] != i+1) simply compares whether given arr[i] element
// is in a proper place in O(1) time and if yes it goes to another element
// else scan through n - i elements



public class Solution {.
    static int minimumSwaps(int[] arr) {
        int count = 0;

        for(int i = 0; i < arr.length - 1; i++) {
            if(arr[i] != i+1) {
                for(int j = i + 1; j < arr.length; j++) {
                    if(arr[j] == (i+1)) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                        count++;
                        break;
                    }
                }
            }

        }
        return count;
    }
}
