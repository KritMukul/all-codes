#include<bits/stdc++.h>
using namespace std;

class Process {
    public:
        int id, at, bt, wt, tat, rt;

};

void fcfsnp(vector<Process> & v) {
    sort(v.begin(), v.end(), [](Process a, Process b) {
        return a.at < b.at;
    });
    int curr_time = 0;

    for(auto & it : v) {
        if(curr_time < it.at) {
            curr_time = it.at;
        }
        it.wt = curr_time - it.at;
        curr_time += it.bt;
    }

    cout<<"Exectution Sequence : ";
    for(auto &it : v) {
        cout<< "P"<< it.id<<" ";
    }
        float total_wait = 0;
    for (auto &i : v)
    {
        total_wait += i.wt;
    }
    cout<<"Average waiting time : "<<(float)total_wait / v.size();
     
}

void sjf(vector<Process> v) {
    int curr_time = 0;
    vector<int> exe_order;

    sort(v.begin(), v.end(), [] (Process *a, Process *b) {
        return a->rt < b->rt;
    })
    
}

int main() {
    vector<Process> v;

    cout<<"Enter number of processes : ";
    int n;
    cin>>n;
    vector<Process> processes(n);
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout<<"Enter arrival time and burst time : ";
        cin>> processes[i].at >> processes[i].bt;
        processes[i].rt = processes[i].bt;
    }
    fcfsnp(processes);

    return 0;
}