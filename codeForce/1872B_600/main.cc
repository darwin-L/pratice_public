        #include <bits/stdc++.h>
        #pragma GCC optimize("Ofast")
        #pragma GCC optimize("unroll-loops")
        #define all(x) (x).begin(), (x).end()
        #define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
        using namespace std;
         
        inline int nxt() {
          int x;
          cin >> x;
          return x;
        }
         
         
        void solve() {
         
          int n = nxt();
         
          
          long long min = 5000000000;
          while(n--) {
            int id = nxt();
            int is =nxt();
            // int current = 1;
            // if(id <= (is/2) + 1 || id == is){
            //     current -=1;
            // } 
            int current = id + (is/2);
            if(is%2 == 0) {
              current--;
            }
            
            
            if(current < min) min = current;
          }
          cout<<min<<'\n';
         
         
        }
        int main() {
          ios_base::sync_with_stdio(false);
          cin.tie(nullptr);
         
        // cout<< 9/2;
          int t = nxt();
          while (t--) {
            solve();
          }
         
          return 0;
        }