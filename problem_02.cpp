#include<bits/stdc++.h>
using namespace std;

// ddl -> deadline

// Function to compare jobs based on deadline
bool sid(const int& p_timeA, const int& ddlA, const int& p_timeB, const int& ddlB) {
    return ddlA > ddlB;
}

void f(vector<int>& p_time, vector<int>& dll) {
    int n = p_time.size();

    // Insertion sort
    for (int i = 1; i < n; ++i) {
        int keyTime = p_time[i];
        int keyDdl = dll[i];
        int j = i - 1;

        while (j >= 0 && sid(p_time[j], dll[j], keyTime, keyDdl)) {
            p_time[j + 1] = p_time[j];
            dll[j + 1] = dll[j];
            --j;
        }

        p_time[j + 1] = keyTime;
        dll[j + 1] = keyDdl;
    }

    // Deadline slot
    vector<bool> slot(n, false);

    // Assign the latest possible slot
    for (int jobId = 0; jobId < n; ++jobId) {
        for (int i = min(dll[jobId] - 1, n - 1); i >= 0; --i) {
            if (!slot[i]) {
                slot[i] = true;
                cout << "Job " << jobId + 1 << ", Processing Time " << p_time[jobId] << endl;
                break;
            }
        }
    }
}

int main() {
    vector<int> p_time = {2, 1, 3};
    vector<int> dll = {1, 2, 3};

    cout << "Output :" << endl;
    f(p_time, dll);

    return 0;
}
