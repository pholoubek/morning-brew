// This solution takes O(n) time complexity

// Even though it asks for at least two common substrings
// We can go with the focus recursively and realize
// that common substring of substring in the end is 
// just a letter!

// this solution simply iterates through both words and 
// checks the other words against letters from the first
// word


public class Solution {

    static String twoStrings(String s1, String s2) {

        Map<Character, Boolean> dict = new HashMap<>();

        for(int i = 0; i < s1.length(); i++) {
            dict.put(s1.charAt(i), true);
        }

        for(int i = 0; i < s2.length(); i++) {

            if (dict.containsKey(s2.charAt(i))) {
                return "YES";
            }
        }

       
        return "NO";
    }
}
