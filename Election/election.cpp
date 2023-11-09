#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unistd.h>
using namespace std;
class Candidate
{
    public:
    int id;
    bool act;
    Candidate()
    {
        id = 0;
        act = true;
    }
    void addCandidate()
    {
        cout<<"Enter ID of new Candidate:"<<endl;
        cin>>id;
    }
};
class Election
{
    public:
    vector<Candidate> v;
    int currindex;
    void getCandidate()
    {
        Candidate c;
        c.addCandidate();
        v.push_back(c);
    }
    void addFailure()
    {
        int max = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].id > max && v[i].act)
            {
                max = v[i].id;
                currindex = i;
            }
        }
        cout<<"Current Coordinator is: "<<v[currindex].id<<endl;
        sleep(3);
        cout<<"Current Coordinator Fails"<<endl;
        cout<<"Detected By: "<<v[(currindex - 1)].id<<endl;
        v[currindex].act = false;
        sleep(3);
        cout<<"Election Initialized"<<endl;
    }
    void RingElection()
    {
        int old = currindex;
        int new1 = (old - 1);
        int cnt = 0;
        while(new1 != old)
        {
            int n = (new1 + 1) % v.size();
            if(new1 == old - 1 && cnt == 0)
            {
                n = (new1 + 2) % v.size();
                sleep(2);
                cout<<"Message passed from "<<v[new1].id<<" to "<<v[n].id<<endl;
                new1 = n;
                cnt++;
                continue;
            }
            if(v[n].act)
            {
                sleep(2);
                cout<<"Message passed from "<<v[new1].id<<" to "<<v[n].id<<endl;
                new1 = n;
            }
            else
            {
                new1 = n;
            }
        }
        int max = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].id > max && v[i].act)
            {
                max = v[i].id;
                currindex = i;
            }
        }
        cout<<"Election Coordinator is: "<<v[currindex].id<<endl;
    }
    void BullyFailure()
    {
        int max=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].id>max && v[i].act)
            {
                max=v[i].id;
                currindex=i;
            }
        }
        cout<<"Current Coordinator is: "<<v[currindex].id<<endl;
        sleep(1);
        cout<<"Current Coordinator Fails"<<endl;
    }
   void BullyElection()
    {
        int old = currindex;             // Store the current coordinator's index
        int a = rand() % (v.size() - 1);  // Select a random value a for the election
        int new1 = currindex - a;        // Calculate the index of the new coordinator candidate
        cout << "Detected By: " << v[currindex - a].id << endl;  // Print the process that detected the failure
        v[currindex].act = false;        // Mark the current coordinator as inactive
        sleep(1);
        cout << "Election Initialized" << endl;  // Print that the election process has started
    
        while (true)
        {
            for (int i = new1; i < v.size() - 1; i++)
            {
                if (v[i].act)
                    cout << "Election message from " << v[new1].id << " to " << v[i + 1].id << endl;
                sleep(1);
            }
    
            for (int i = v.size() - 1; i > new1; i--)
            {
                if (v[i].act)
                    cout << "OK message from " << v[i].id << " to " << v[new1].id << endl;
                sleep(1);
            }
    
            if (new1 < v.size() - 1 && v[new1].act)
            {
                new1 = new1 + 1;
            }
            else
            {
                break;
            }
        }
    
        cout << "Elected Coordinator is: " << v[new1 - 1].id << endl;  // Announce the elected coordinator
    }
};
int main()
{
    while(true)
    {
    Election e;
    cout<<"Enter Number of  Nodes: "<<endl;
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        e.getCandidate();
    }
    cout<<"ALGORITHM FOR ELECTION: "<<endl;
    cout<<"1. RING ALGORITHM\n2. BULLY ALGORITHM\n3. EXIT"<<endl;
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
        e.addFailure();
        e.RingElection();
        break;
        case 2:
        e.BullyFailure();
        e.BullyElection();
        break;
        case 3:
        break;
        default:
        cout<<"Error"<<endl;
        break;
    }
    if(n==3)
    {
        break;
    }
    }

    return 0;
}
