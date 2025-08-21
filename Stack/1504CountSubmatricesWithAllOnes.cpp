#include <bits/stdc++.h>
using namespace std;

// 1504. Count Submatrices With All Ones

int st[150], top=-1;
int cnt[150]={0};
class Solution {
public:
    static int numSubmat(vector<vector<int>>& mat) {
        const int r=mat.size(), c=mat[0].size();
 
        int ans=0;
        for (int i=0; i<r; i++){
            auto& h=mat[i];
            top=-1;
            fill(cnt, cnt+c, 0);
            for(int j=0; j<c; j++){
                if (i>0 && h[j]>0) 
                    h[j]+=mat[i-1][j];
                
                while(top>-1 && h[st[top]]> h[j]) 
                    top--;
                int left=(top==-1)?-1:st[top];
                cnt[j]=(top>-1?cnt[left]:0)+h[j]*(j-left);
                ans+=cnt[j];
                st[++top]=j;
            }
        }
        return ans;
    }
};

int main() {
    int r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));
    cout << "Enter matrix elements (0/1):\n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> mat[i][j];
        }
    }

    int result = Solution::numSubmat(mat);
    cout << "Number of submatrices with all ones: " << result << "\n";

    return 0;
}