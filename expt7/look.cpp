#include <bits/stdc++.h>

using namespace std;

void SCAN(vector<int> &q, int current_head, int dir)
{
    int midPos = 0, distance = 0, head = current_head, limit;

    if (dir == 1)
    {
        cout << "enter the limit value of the disk(should be greater than the highest address)" << endl;
        cin >> limit;
    }
    sort(q.begin(), q.end());
    vector<int> seq;
    auto it = lower_bound(q.begin(), q.end(), head);
    if (dir == 0)
        midPos = it - q.begin() - 1;
    else
        midPos = it - q.begin();

    // if the direction is  left than service the right to left than left to rigth
    if (dir == 0)
    {
        for (int i = midPos; i >= 0; i--){
            distance += abs(q[i] - current_head);
            current_head = q[i];
            seq.push_back(q[i]);
        }

        for (int i = midPos + 1; i < q.size(); i++)
        {
            distance += abs(current_head - q[i]);
            current_head = q[i];
            seq.push_back(q[i]);
        }
    }
    else
    {
        // if the direction was right

        for (int i = midPos; i < q.size(); i++){
            distance += abs(current_head - q[i]);
            current_head = q[i];
            seq.push_back(q[i]);
        }

        for (int i = midPos - 1; i >= 0; i--)
        {
            distance += abs(current_head - q[i]);
            seq.push_back(q[i]);
            current_head = q[i];
        }
    }

    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++)
    {
        if (i == seq.size() - 1)
        {
            cout << seq[i];
        }
        else
        {
            cout << seq[i] << "-->";
        }
    }

    cout<<endl<<"the seek distance is:"<<distance;
}

int main()
{
    int n, head, dir;
    cout << "enter head address:";
    cin >> head;
    cout << endl
         << "enter number of requests in the queue" << endl;
    cin >> n;

    vector<int> q(n);

    cout << "enter the refrence string" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    cout << "enter the direction(0 for left and 1 for rigth)" << endl;
    cin >> dir;

    SCAN(q,head,dir);
}