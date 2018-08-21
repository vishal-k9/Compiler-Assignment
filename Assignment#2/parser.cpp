#include<bits/stdc++.h>
#include<stdio.h>
#include <string>
#include <fstream>
#include <streambuf>



#define PIE 3.14159265358979323846
#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ll inf=numeric_limits<ll>::max();


map<string, set<string> > symbol_table;

bool isNum(string s)
{
	int n=s.size();
	if(n==0)
		return false;
	int i;
	for(i=0;i<n;i++)
	{
		string temp(1,s[i]);
		if(symbol_table["number"].find(temp)==symbol_table["number"].end())
		{
			if(i!=0||s[i]!='-')
			{
				return false;
			}
		}
	}
	return true;
}

bool isIdf(string s)
{
	string temp(1,s[0]);
	if(symbol_table["number"].find(temp)!=symbol_table["number"].end() || symbol_table["delimiter"].find(temp)!=symbol_table["delimiter"].end())
	{
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	string arr[]={" ","+","-","*","/",",",";",">","<","=","(",")","{","}","[","]"};
	// int ds = sizeof(arr) / sizeof(arr[0]);
	int i;
	for(i=0;i<16;i++)
	{
		symbol_table["delimiter"].insert(arr[i]);
	}

	string arr2[]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
	for(i=0;i<32;i++)
	{
		symbol_table["keyword"].insert(arr2[i]);
	}
	// symbol_table["delimiter"](arr,arr+ds);
	// symbol_table["keyword"]

	string arr3[]={"0","1","2","3","4","5","6","7","8","9","."};
	for(i=0;i<11;i++)
	{
		symbol_table["number"].insert(arr3[i]);
	}
	// symbol_table["number"]


	std::ifstream t("sample.c");
	std::string s((std::istreambuf_iterator<char>(t)),
	                 std::istreambuf_iterator<char>());

	// string s="int main(){printf(\"Hello\");return 0;}";

	vector<string> num,idf,kw;

	int r=0,l=0;
	int n=s.size();
	while(r<=n && l<=r)
	{
		string temp(1,s[r]);
		if(symbol_table["delimiter"].find(temp)==symbol_table["delimiter"].end())
		{
			r++;
			// continue;
		}
		string temp2(1,s[r]);
		if(symbol_table["delimiter"].find(temp2)!=symbol_table["delimiter"].end() && l==r)
		{
			r++;
			l=r;
		}
		else if((symbol_table["delimiter"].find(temp2)!=symbol_table["delimiter"].end() && l!=r) || (r==n && l!=r) )
		{
			string token= s.substr(l,r-l);

			if(symbol_table["keyword"].find(token)!=symbol_table["keyword"].end())
			{
				// kw.push_back(token)
				cout<<"keyword ("<<token<<")"<<endl;
			}
			else if(isNum(token))
			{
				cout<<"Number ("<<token<<")"<<endl;
			}
			else if(isIdf(token))
			{
				cout<<"Identifier ("<<token<<")"<<endl;
			}
			l=r;
		}
	}
	

	return 0;
}