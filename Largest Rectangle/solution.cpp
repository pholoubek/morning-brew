#include <bits/stdc++.h>

using namespace std;

long largestRectangle(vector<int> h)
{
    /**
     * given arr of height, h, find the maximum RECTANGLE s.t. distance * min(h[i], h[i+1], ...)
     * Difficulty: medium
     * Comment: Not much other than focus first on simpler solutions.. overall easy
     */
    long temp = 0, area = 0;
    for (int i = 0; i < h.size(); i++)
    {
        int j = i, k = i - 1, count = 0;
        if (h[i] <= h[j])
        {
            while (h[j] >= h[i] && j < h.size())
            {
                count++;
                j++;
            }
        }

        if (h[i] <= h[k])
        {
            while (h[k] >= h[i] && k >= 0)
            {
                count++;
                k--;
            }
        }
        area = (count)*h[i];
        if (area > temp)
            temp = area;
    }
    return temp;
}
