// This is the max segment tree implementation. 

class SegTree {
public:
    vector<int> seg;

    SegTree(int n){
        seg.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int> &a){
        //base case
        if(low == high){
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high)/2;

        build(2*ind+1, low, mid, a);
        build(2*ind+2, mid+1, high, a);

        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int start, int end){
        // no overlap case : s e l h or l h s e
        if((end < low) || (high < start))
            return INT_MIN;

        // complete overlap case [s l h e]
        if((start <= low) && (high <= end))
            return seg[ind];

        // partial overlap case
        else{
            int mid = (low + high)/2;

            int l = query(2*ind+1, low, mid, start, end);
            int r = query(2*ind+2, mid+1, high, start, end);

            return max(l, r);
        }
    }

    void update(int ind, int low, int high, vector<int> &a, int i){
        //base case
        if(low == high){
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high)/2;

        if(i <= mid){
            update(2*ind+1, low, mid, a, i);
        }
        else{
            update(2*ind+2, mid+1, high, a, i);
        }

        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }
};


/*
Query Type	Combine	    No Overlap Return
Maximum	    max(l, r)	INT_MIN
Minimum	    min(l, r)	INT_MAX
Sum	        l + r	    0
XOR	        l ^ r	    0
*/