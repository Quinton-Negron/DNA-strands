#include <iostream>
#include <string>

using namespace std;

void codon (string);
void codon (string start)
{
 int position = 0, len = start.length();
 char x = 'A';
 for (int i = 0; i < len; i++)
 {
	if(start[i] == 'A' && start[i+1] == 'A' && start[i+2] == 'A')
	{
		
	}
 }
if(position > 0)
  cout << "The coding region starts at position " << position << endl;
else
  cout << "Could not find the codon region..." << endl;
};

int main()
{
 char Adenine = 'A';
 char Guanine = 'G';
 char Cytosine = 'C';
 char Thymine = 'T';
 string strand;

 cout << "Please input your DNA:" << endl;
 cin >> strand;
 cout << "This is the RNA sequence your entered: " <<strand << endl;
 codon(strand);

 system ("PAUSE");
 return 1;
}