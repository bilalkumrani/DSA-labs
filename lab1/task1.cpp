#include <iostream>
#include <fstream>
using namespace std;
string *wordTokenize (string fileName)
{
string myArr[1000];
string myText;

ifstream MyReadFile(fileName.c_str());
int i=0;
while (getline (MyReadFile, myText)) {
  cout << myText<<endl;
  myArr[i++] = myText;
  
}

MyReadFile.close();
return myArr;
}

int main() {
string *myArr = wordTokenize("sample1_words.txt");
}




















