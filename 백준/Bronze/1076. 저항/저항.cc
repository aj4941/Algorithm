#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(void)
{
	map<string, char> m1;
	map<string, string> m2;
	string str;
	int i;
	int flag = 0;
	m1["black"] = '0'; m1["brown"] = '1'; m1["red"] = '2';
	m1["orange"] = '3'; m1["yellow"] = '4'; m1["green"] = '5';
	m1["blue"] = '6'; m1["violet"] = '7'; m1["grey"] = '8'; m1["white"] = '9';
	m2["black"] = ""; m2["brown"] = "0"; m2["red"] = "00"; m2["orange"] = "000";
	m2["yellow"] = "0000"; m2["green"] = "00000"; m2["blue"] = "000000";
	m2["violet"] = "0000000"; m2["grey"] = "00000000"; m2["white"] = "000000000";
	for(i = 0; i < 2; i++)
	{
		cin >> str;
		if(flag == 1 && str == "black")
			cout << m1[str];
		else if(str != "black")
		{
			cout << m1[str];
			flag = 1;
		}
	}
	cin >> str;
	if(flag)
		cout << m2[str];
	else
		cout << "0";
}