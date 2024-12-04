    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n = 1000; // Maximum number of sequences to process
        int answer = 0;

        while (n--) {
            string line;
            if (!getline(cin, line) || line.empty()) break; // Read a line and exit if input ends or empty line

            stringstream ss(line);
            vector<int> a;
            int x;
            while (ss >> x) {
                a.push_back(x);
            }

            int k = a.size();
            if (k < 2) continue; // A valid sequence requires at least two numbers

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

            if (ok && (only_inc || only_dec)) {
                answer++;
            }
        }

        cout << answer << endl;
        return 0;
    }
