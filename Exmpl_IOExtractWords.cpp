#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isin(char x, char* v)
// searches for x in the string of characters v
{
	bool flag = 0;
	char* p = v;
	for (p; *p!='\0'; p++)
	{
		if (x == *p)
		{
			flag = 1;
			return flag;
		}
	}
	return flag;
}

void word(ofstream& out, vector<char> wd)
{
	int len = wd.size();
	char mot[len];
	vector<char>::iterator it = wd.begin();
	for (int i = 0; i < len; i++)
	 {
		mot[i] = *it; it++;
	 }
	mot[len] = '\0';
	out << mot << '\n';

}


int main()
{
	cout << "Enter the name of the file to be processed: " << endl;
	char file_name[100];
	cin >> file_name;
	
	vector<vector<char>> dict;
	// the vector of the extracted words
	
	vector<vector<char>>::iterator it;
	
	ifstream input(file_name);
	ofstream output("Words.txt");
	
	char x;
	vector<char> wd(1,'\0');
	// container for each extracted word

	if (input.fail())
	{
		cout << "Error opening file";
		exit(1);
	}
	if (output.fail())
	{
		cout << "Error opening file";
		exit(1);
	}
	char stopchar[] = { '\'',' ',',','.','\n',':',';','"','!','?','(',')','[',']','?','!','\t','-','\0','<','>' };
    // the string of the characters we want to purge; to be adjusted upon needs
	
	while (input.get(x))
	{
		if (isin(x, stopchar)==0)
		{
			wd.push_back(x); 
		}
		else
		{
			wd.push_back('\0'); 
			dict.push_back(wd);
			wd.clear();
		}
		
	}
	
	input.close();

	set<vector<char>> s; // container set eliminates duplicates
	unsigned size = dict.size();
	for (unsigned i = 0; i < size; ++i) 
		s.insert(dict[i]);
	dict.assign(s.begin(), s.end());

	for (auto w : dict)
		word(output, w);

    	output.close();
	cout <<"Words extracted in 'Words.txt'" << endl;

	//system("pause");
	return 0;
}
