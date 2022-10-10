/*
Sherlock and Moving Tiles

https://www.hackerrank.com/challenges/sherlock-and-moving-tiles/problem

Difficulty: easy 

Personal comments on the problem:
The analytical solution can be derived by realizing the following:

We care about the relative velocity between both squares. By writing down the formulas and solving for time, t,
we are left with plug-in formula where we have relative distance over relative velocity (this is constant) equals time, t.
Since both squares move in diagonal x/y fashion, we can use the fact and find the relative distance by subs diagonal of the 
fast moving square minus provided square root of Q area (aka overlapping tiles of the slow moving square vs. fast moving). 
**/


#include <bits/stdc++.h>

using namespace std;

vector<double> movingTiles(int l, int s1, int s2, vector<long> queries) {
    const double sqrt2 = sqrt(2);
    const double p1 = sqrt2 * l;
    const double dv = abs(s2 - s1);
    
    cout << sqrt2 << endl;
    
    vector<double> results;
    for (size_t i = 0; i < queries.size(); i++) {
        double p2 = sqrt2 * sqrt(queries[i]);
        double res = (p1 - p2) / dv;
        results.push_back(res);
    }
    return results;
}

