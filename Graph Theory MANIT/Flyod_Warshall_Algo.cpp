#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

void shortest_distance(vector<vector<int>>& grid){
        int n = grid.size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == -1)
                    grid[i][j] = 100000;
            }
        }
        for(int via = 0; via < n; via++) {
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                   grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 100000)
                    grid[i][j] = -1;
            }
        }
	}


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    shortest_distance(grid);
    cout << "The shortest distance matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -1)
                cout << "INF ";
            else
                cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;


    
    

}