// 40 points out of 40 points. 

// Problem could be easily solved by Bubble Sort which is
// O(n*n) time complexity and O(1) space complexity.

// There's optimization quirk which can be used.. If we haven't
// sorted for the outer loop, we recognized all bribes and there's
// nothing much to count

// Special case follows from the natural order of index and arr[index]
// If those 2 elements are off by more than 2 then we have chaos.

public class Solution {
    static void minimumBribes(int[] q) {
        int[] arr = q;
        int bribes = 0;
        boolean sentinel = false;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] - j - 1 > 2) {
                    System.out.println("Too chaotic");
                    return;
                }

                if (arr[j] > arr[j + 1]) {
                    bribes += 1;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    sentinel = true;
                }
            }

            if (sentinel) {
                sentinel = false;
            } else {
                break;
            }

        }
        System.out.println(bribes);

    }
}
