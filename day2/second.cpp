//     #include <bits/stdc++.h>
// #include <vector>
//     using namespace std;

//     bool isOk(vector<int>a)
//     {
//         int k = a.size();

//         bool ok = true;
//         bool only_inc = true;
//         bool only_dec = true;

//         for (int j = 0; j < k - 1; j++) {
//             int diff = a[j + 1] - a[j];
//             if (diff > 0) only_dec = false;
//             if (diff < 0) only_inc = false;
//             if (!(1 <= abs(diff) && abs(diff) <= 3)) {
//                 ok = false;
//                 break;
//             }
//         }

//        return (ok && (only_inc || only_dec))



//     }





//     int main() {
//         int n = 1000; // Maximum number of sequences to process
//         int answer = 0;

//         while (n--) {
//             string line;
//             if (!getline(cin, line) || line.empty()) break; // Read a line and exit if input ends or empty line

//             stringstream ss(line);
//             vector<int> a;
//             int x;
//             while (ss >> x) {
//                 a.push_back(x);
//             }

//             bool anyok = false;
//             auto consider = [&] ( int i  ){
//                 vector<int> b = a;
//                 b.erase(b.begin() + i);
//                 if(isOk(b))
//                 {
//                     anyok = true;
//                 }
//             };

//             int k = a.size();
//             consider(0);
//             for(int i=0; i<k-1; i++)
//             {int diff = a[i+1] - a[i];
//                 if(abs(diff) <1 || abs(diff)> 3) {
//                    consider(i);
//                     consider(i+1);
//                     break;

//                 }
//                 if(i+2 < k){
//                     int diff2 = a[i+2] - a[i+2];
//                     if ((diff> 0) != (diff2 > 0)){
//                         consider(i);
//                         consider(i+1);
//                         consider(i+2);
//                         break;
//                     }
//                 }

//             }

//             if(anyok)
//             {
//                 answer++;
//             }


//         }

//         cout << answer << endl;
//         return 0;
//     }


#include <bits/stdc++.h>
using namespace std;

bool isOk(const vector<int>& a) {
    int k = a.size();
    if (k < 2) return true; // A sequence with 0 or 1 element is trivially valid

    bool ok = true;
    bool only_inc = true;
    bool only_dec = true;

    for (int j = 0; j < k - 1; j++) {
        int diff = a[j + 1] - a[j];
        if (diff > 0) only_dec = false;
        if (diff < 0) only_inc = false;
        if (!(1 <= abs(diff) && abs(diff) <= 3)) {
            ok = false;
            break;
        }
    }

    return (ok && (only_inc || only_dec));
}

int main() {
    int n = 1000; // Maximum number of sequences to process
    int answer = 0;

    while (n--) {
        string line;
        if (!getline(cin, line) || line.empty()) break; // Exit if input ends or empty line

        stringstream ss(line);
        vector<int> a;
        int x;
        while (ss >> x) {
            a.push_back(x);
        }

        bool anyok = false;
        auto consider = [&](int i) {
            vector<int> b = a;
            b.erase(b.begin() + i);
            if (isOk(b)) {
                anyok = true;
            }
        };

        int k = a.size();
        // Check by removing the first element
        consider(0);

        for (int i = 0; i < k - 1; i++) {
            int diff = a[i + 1] - a[i];
            if (abs(diff) < 1 || abs(diff) > 3) {
                consider(i);
                consider(i + 1);
                break;
            }
            if (i + 2 < k) {
                int diff2 = a[i + 2] - a[i+1];
                if ((diff > 0) != (diff2 > 0)) {
                    consider(i);
                    consider(i + 1);
                    consider(i + 2);
                    break;
                }
            }
        }

        if (anyok) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}
