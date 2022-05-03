#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter Number of Processes: ";
    cin >> n;
    cout << "Enter Number of Resources: ";
    cin >> m;
    int Allocation[n][m];
    int Available[m];
    int Request[n][m];
    bool Finish[n]={false};
    int Work[m];
    for (int i = 0; i < m; i++)
    {
        cout <« "Enter Available Resources for Resource" << i + 1 << " : ";
        cin >> Available[i];
        Work[i] = Available[i];
    }
                
   for (int i = 0; i < n; i++)
{
    cout << "Enter Allocation Matrix for Process" << i + 1 << " : ";
    for (int j = 0; j < m; j++)
    {
        cin >> Allocation[i][j];
    }
}
for (int i = 0; i < n; i++)
{
    cout << "Enter Request Matrix for Process"<< i + 1 << " : ";
    for (int j = 0; j < m; j++)
    {
        cin >> Request[i][j];
}
int i = 0;
bool DeadLock = false;
while (1)
{
    bool flag = false;
for (int z = 0; z < n; z++)
{
    if (Finish[z] == false)        
    {
        flag = true;
        bool Greater = false;
        for (int o = 0; o < m; o++)
        {
             if (Request[z][o] > Work[o])
             {
                 Greater = true;
             }
        }
         if (!Greater)
        {
             for (int o = 0; o < m; o++)
             {
                 Work[o] += Allocation[z][o];
             }
             Finish[z] = true;
        }
    }
        }
    if (!flag)
    {
    for (int o = 0; o < n; 0++)
    {
         if (Finish[o] == false)
         {
              DeadLock = true; 
              break;
        }
        }
    break;
}
}
if (DeadLock)
{
cout << "DeadLock is present!";
}
else
{
cout << "No DeadLock present!";
}
}