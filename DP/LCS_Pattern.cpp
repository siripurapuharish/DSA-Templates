/*
=========================================
LCS PATTERN
========================================= */

class Solution {
public:
    // Recursion Code 
    int fun(int i,int j, string &s1, string &s2){

        if(i<0 || j<0)
            return 0;

        if(s1[i] == s2[j])
            return 1 + fun(i-1,j-1, s1, s2);

        return max(fun(i-1,j, s1, s2), fun(i,j-1, s1, s2));
    }

    int LCS(string s1, string s2){

        int n = s1.size();
        int m = s2.size();

        // Tabulation Code with shifting index

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};

/*

PATTERN RECOGNITION:

1. Two Strings
2. Common Part
3. Keep/Delete Characters
4. Convert One String To Another
5. Palindrome After Insert/Delete
6. Subsequence Questions

=> THINK LCS

State:

dp[i][j] = LCS length of
s1[0...i-1] and s2[0...j-1]

Transition:

if(s1[i] == s2[j])
    1 + f(i-1,j-1)

else
    max(f(i-1,j), f(i,j-1))

-----------------------------------------
FOLLOW UPS
-----------------------------------------

1. Longest Common Subsequence
   -> dp[n][m]

2. Print LCS
   -> Backtrack from dp[n][m]
      
    If characters match:
        include character
        move diagonal

    Else:
        move towards larger value.

    Reverse answer.

3. Longest Common Substring
   -> Difference:

    Substring must be continuous.

    If mismatch:
    dp[i][j] = 0, instead of max(...)

    Keep track of maximum length.

4. Longest Palindromic Subsequence
   -> LCS(s, reverse(s))

5. Minimum Insertions to Palindrome
   -> n - LPS

   Characters already in LPS
   don't need insertion.

6. Minimum Deletions to Palindrome
   -> n - LPS

7. Convert A -> B
   -> delete = n-LCS
   -> insert = m-LCS

8. Delete Operation for Two Strings
   -> n+m-2*LCS

   delete everything except LCS.

9. Shortest Common Supersequence Length
   -> n+m-LCS

   Common characters counted once.

10) PRINT SHORTEST COMMON SUPERSEQUENCE

    Build LCS table.

    Backtrack:

    Match:
        take once

    Else:
        move towards larger dp value
        and include skipped char

    Reverse answer.

11) LONGEST REPEATING SUBSEQUENCE

    Run LCS on same string.

    Extra condition:

    i != j

    because same index
    cannot match itself.


12) MAX UNCROSSED LINES

Exactly LCS.

Just arrays instead of strings.

*/

