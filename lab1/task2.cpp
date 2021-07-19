#include<iostream>
#include<regex>
#include <string>
using namespace std;

void extractEmail (string fileName)
{
	
	regex reg("(\\w+)(\\.)?(\\w+)@[\\w+]+(\\.(\\w+))+");
	string myText;

ifstream MyReadFile(fileName.c_str());
int i=0;
while (getline (MyReadFile, myText)) {
	sregex_iterator current(myText.begin(), myText.end(), reg);
	sregex_iterator last;
	 while (current != last) {
                smatch match = *current;
                cout << match.str() << ",\n";
                current++;
            }
        }
  
}

MyReadFile.close();
}

int main() {
	extractEmail("sample2_emails.txt");
}

