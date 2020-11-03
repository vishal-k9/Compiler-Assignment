#include<bits/stdc++.h>
#include<stdio.h>
#include <iterator>

// Non-recurrsive predictive parsing
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll inf=numeric_limits<ll>::max();

map<string, map<string, vector<string> > > m;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// cout<<""

	string T2[]={"id","+","*","(",")","$"};
	// string NT2[]={"E","E`","T","T`","F"};

	vector<string> T(T2, T2+6);

	vector<vector<string> > CFG;
	vector<string> temp;

	temp.push_back("T");
	temp.push_back("E`");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("+");
	temp.push_back("T");
	temp.push_back("E`");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("eps");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("F");
	temp.push_back("T`");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("*");
	temp.push_back("F");
	temp.push_back("T`");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("eps");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("(");
	temp.push_back("E");
	temp.push_back(")");
	CFG.push_back(temp);
	temp.clear();

	temp.push_back("id");
	CFG.push_back(temp);
	temp.clear();

	m["E"]["id"]=CFG[0];
	m["E"]["+"]=temp;
	m["E"]["*"]=temp;
	m["E"]["("]=CFG[0];
	m["E"][")"]=temp;
	m["E"]["$"]=temp;
	m["E`"]["id"]=temp;
	m["E`"]["+"]=CFG[1];
	m["E`"]["*"]=temp;
	m["E`"]["("]=temp;
	m["E`"][")"]=CFG[2];
	m["E`"]["$"]=CFG[2];
	m["T"]["id"]=CFG[3];
	m["T"]["+"]=temp;
	m["T"]["*"]=temp;
	m["T"]["("]=CFG[3];
	m["T"][")"]=temp;
	m["T"]["$"]=temp;
	m["T`"]["id"]=temp;
	m["T`"]["+"]=CFG[5];
	m["T`"]["*"]=CFG[4];
	m["T`"]["("]=temp;
	m["T`"][")"]=CFG[5];
	m["T`"]["$"]=CFG[5];
	m["F"]["id"]=CFG[7];
	m["F"]["+"]=temp;
	m["F"]["*"]=temp;
	m["F"]["("]=CFG[6];
	m["F"][")"]=temp;
	m["F"]["$"]=temp;

	int l;
	cout<<"Enter the length of input string:"<<endl;
	cin>>l;
	cout<<"Enter the input:"<<endl;
	vector<string> s;
	vector<string> ans;

	int i;
	for(i=0;i<l;i++)
	{
		string temp;
		cin>>temp;
		s.push_back(temp);
	}
	s.push_back("$");
	
	// adding $ at the start of the string
	// string s2="$";
	// s.insert(l,s2);

	stack<string> st;
	st.push("$");
	st.push("E");
	int ptr=0;
	l=s.size();
	// l++;
	while(!st.empty())
	{
		if(ptr==l)
		{
			cout<<"Invalid Input"<<endl;;
			return 0;
		}
		string x=st.top();
		string tempstr=(s[ptr]);
		if(find(T.begin(), T.end(), x)!=T.end())
		{
			
			if(x==tempstr)
			{
				st.pop();
				ptr++;
			}
			else
			{
				cout<<"Invalid Input"<<endl;;
				return 0;
			}
		}
		else
		{
			if(m[x][tempstr].size()!=0)
			{
				string tstr=x;
				tstr.append("->");

				st.pop();
				int i;
				for(i=0;i<m[x][tempstr].size();i++)
				{
					
					tstr.append(m[x][tempstr][i]);
				}
				ans.push_back(tstr);
				for(i=m[x][tempstr].size()-1;i>=0;i--)
				{

					if(m[x][tempstr][i]!="eps")
					{
						st.push(m[x][tempstr][i]);
					}
				}
			}
			else
			{
				cout<<"Invalid Input"<<endl;
				return 0;
			}
		}
	}

	cout<<"Correct Input"<<endl;
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}	

	return 0;
}
