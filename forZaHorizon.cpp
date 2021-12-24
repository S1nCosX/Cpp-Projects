#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

vector <pair <char, int>> lines;

string inp = "";

int main()
{
	getline(cin, inp);
	cout << inp << "\n";
    for (int i = 0; i < inp.length(); i++)
    {
        int len = 0;
        
        pair<char, int> a;
        a.first = inp[i];
        
		while(inp[i]!= ' ' && i++ < inp.length())len++;
        	
        a.second = len;
        
		lines.push_back(a);
    }
    
	cout << "input letter\n";
    char inp2;
    cin >> inp2;
    
	int ans = 0;

	for (int i = 0; i < lines.size(); i++)
	{
		while (lines[i].first != inp2) i++;
		
		while ((i - 1 >= 0 && lines[i].second + 1 > lines[i - 1].second) || (i+1 < lines.size() && lines[i].second + 1 > lines[i + 1].second))
		{
			if (i - 1 >= 0 && lines[i].second + 1 > lines[i - 1].second)
			{
				lines[i].second += 1 + lines[i - 1].second;
				lines.erase(lines.begin() + i - 1);
			}
			
			if (i+1 < lines.size() && lines[i].second + 1 > lines[i + 1].second)
			{
				lines[i].second += 1 + lines[i + 1].second;
				lines.erase(lines.begin() + i + 1);
			}
		}
	}
	for (auto i : lines)
		if (i.first == inp2)
			ans += i.second;
    cout << ans;
    return 0;
}