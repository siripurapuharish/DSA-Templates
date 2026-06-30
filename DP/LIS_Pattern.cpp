/*
=========================================
LIS PATTERN (DP + Hashing)
========================================= */

vector<int> printLIS(vector<int>& nums) {

    int n = nums.size();

    vector<int> dp(n,1);
    vector<int> parent(n);

    int maxi = 1;
    int lastIndex = 0;

    for(int i=0;i<n;i++){

        parent[i]=i;

        for(int j=0;j<i;j++){

            if(nums[j]<nums[i] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                parent[i]=j;
            }
        }

        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }

    vector<int> ans;

    while(parent[lastIndex]!=lastIndex){
        ans.push_back(nums[lastIndex]);
        lastIndex=parent[lastIndex];
    }

    ans.push_back(nums[lastIndex]);

    reverse(ans.begin(),ans.end());

    return ans;
}

/*
=========================================
Binary Search (Length)
========================================= */
// Strictly Increasing

int lengthOfLIS(vector<int>& a){

    vector<int> vec;

    for(int x : a){

        ind ind=lower_bound(vec.begin(),vec.end(),x) - vec.begin();

        if(ind==vec.size())
            vec.push_back(x);
        else
            vec[ind] = x;
    }

    return vec.size();
}


/*
PATTERN RECOGNITION...

Need Length?                  → Binary Search
Need Actual Sequence?         → DP + Parent(Hashing)
Need Count?                   → DP + Count[]
Need Maximum Sum?             → DP storing Sum
Need Bitonic?                 → LIS + LDS
Need 2D/3D Objects?           → Sort + LIS
Need Different Relation?      → Change LIS Transition
Need Duplicates Allowed?      → upper_bound()
Need Strictly Increasing?     → lower_bound()
Need Mapping Problem?         → Convert Values → Indices → LIS
Need Reconstruction?          → Parent Array
Need Only Triplet/Small K?    → Greedy
Need Subarray?                → Sliding Window / Linear Scan (Not LIS)


FOLLOW UP PROBLEMS...

1. LIS (LC-300)
   → Need Length → Binary Search (lower_bound)

2. Print LIS
   → Need Actual Sequence → DP + Parent(Hashing)

3. Number of LIS
   → Need Count → DP + Count[]

4. Longest Continuous Increasing Subsequence
   → Subarray → Linear Scan (No LIS)

5. Russian Doll Envelopes
   → Need 2D Objects → Sort + LIS

6. Maximum Length of Pair Chain
   → Need 2D Objects → Sort + LIS (Greedy also works)

7. Largest Divisible Subset
   → Need Actual Sequence + Different Relation
   → DP + Parent + Change Transition

8. Longest String Chain
   → Need Different Relation
   → DP + Change Transition

9. Longest Bitonic Subsequence
   → Need Bitonic → LIS + LDS

10. Minimum Removals to Make Mountain Array
    → Need Bitonic → LIS + LDS

11. Maximum Sum Increasing Subsequence
    → Need Maximum Sum → DP storing Sum

12. Best Team With No Conflicts
    → Need 2D Objects → Sort + LIS DP

13. Longest Obstacle Course
    → Need Duplicates Allowed → upper_bound()

14. Non-Decreasing LIS
    → Need Duplicates Allowed → upper_bound()

15. Increasing Triplet Subsequence
    → Need Only Length = 3 → Greedy (Not LIS)

16. Minimum Operations to Make a Subsequence
    → Mapping → Indices → Binary Search LIS

17. Box Stacking
    → Need 2D/3D Objects → Rotate + Sort + LIS DP

18. Count Increasing Quadruplets
    → Need Count → Advanced DP Counting
*/