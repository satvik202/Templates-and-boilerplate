#include <bits/stdc++.h>
using namespace std;

class segmentTree{
    public :
    vector<int>segTree;
    segmentTree(int n){
        segTree.resize(4*n + 1);
    }

    void build(vector<int>&arr, int low, int high, int indx){
        if(low==high){
            segTree[indx] = arr[low];
            return;
        }
        int mid = (low+high)>>1;
        build(arr, low, mid, 2*indx+1);
        build(arr, mid+1, high, 2*indx+2);

        segTree[indx] = min(segTree[2*indx+1], segTree[2*indx+2]);
    }

    int query(int l, int r, int low , int high, int indx){
        if(l>high or r<low) return INT_MAX; // no overlap
        
        if(l<=low && r>=high) return segTree[indx]; // complete overlap
        int mid = (low+high)>>1;
        int left = query(l,r,low, mid, indx*2+1);
        int right = query(l,r,mid+1, high, indx*2+2);

        return min(left, right);
    }

    void update(int i, int val, int low, int high, int indx){
        
        if(low==high){
            segTree[indx] = val;
            return;
        }

        int mid = (low+ high) >>1;
        if(i<=mid) update(i, val, low, mid, 2*indx+1);
        else update(i, val, mid+1, high, 2*indx+2);
        segTree[indx] = min(segTree[2*indx+1], segTree[2*indx+2]);

    }
};


void print(auto &arr){
    for(auto &it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){


   int n; cin>>n;
   vector<int>v(n);
   for(int i=0; i<n; i++) cin>>v[i];

   segmentTree seg(n);

   seg.build(v,0,n-1, 0);

   cout<<seg.query(1,4,0,n-1,0)<<endl;
   seg.update(1,1,0,n-1,0);
   v[1]=1;
   cout<<seg.query(1,4,0,n-1,0)<<endl;
   cout<<seg.query(4,5,0,n-1,0)<<endl;

   print(v);

   
    
    return 0;
}
