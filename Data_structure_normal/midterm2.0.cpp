#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include<sstream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    cin.ignore();
    vector<queue<string>> queues(n);
    vector<string> departs;

    for (int i = 0; i < n; ++i)
	{
		string line;
		getline(cin,line);
		istringstream iss(line);
	    string name;
	    if (line == "\n" || line == " ") 
		{
            cin.ignore();
            continue;
//	        queues[i].push(" ");

	    }
        else
        {
            while (iss >> name && name != "LEAVES" && name != "ENTERS") 
            {
	        queues[i].push(name);
	        }
        }
    } 


    string event, name;
    int queueNum;
    while (cin >> event) 
    {
        if (event == "LEAVES") 
        {
            cin>>queueNum;
            if (!queues[queueNum - 1].empty()) 
            {
                departs.push_back(queues[queueNum - 1].front());
                queues[queueNum - 1].pop();
            }
        } 

        else if (event == "ENTERS") 
        {
            cin>>name>>queueNum;
            queues[queueNum - 1].push(name);
        }
    }
    cout << "DEPARTS" << endl;
    for(vector<string>::iterator it= departs.begin();it!=departs.end();it++)
    {
        
        cout<<*it<<endl;
    }
    cout<<endl;
    
    cout << "FINAL CONTENTS" << endl;
    for (int i = 0; i < (int)queues.size(); ++i) 
    {
        cout << "queue " << i+1 << ": ";
        if (queues[i].empty()) 
        {
            cout << endl;
        } 
        else 
        {
            queue<string> temp = queues[i];
            while (!temp.empty()) 
            {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
    return 0;
}

