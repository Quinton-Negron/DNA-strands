//Quinton Negron
//This program reads a DNA strand
//and returns it's mRNA complement
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

//We are going to need 3 functions to manipulate the letters
//One to take the strands from a seperate file
//another to determine the position of the letters
//lastly, a third one that changes the letter of the strand
char DNAbase_to_mRNAbase(char base)
{
	if (base == 'A')
	{
		return 'U';
	}
	else if (base == 'T')
	{
		return 'A';
	}
	else if (base == 'C')
	{
		return 'G';
	}
	else if (base == 'G')
	{
		return 'C';
	}
	else if (base == 'a')
	{
		return 'U';
	}
	else if (base == 't')
	{
		return 'A';
	}
	else if (base == 'c')
	{
		return 'G';
	}
	else if (base == 'g')
	{
		return 'C';
	}
}

string DNA_to_mRNA(string dna)
{
    int i;
    string x = "";
    //becuase each line varies in length we can not accurately predict what end of strand
    //so for our lop, our "stop" uses the length of dna to stop at each letter.
	for (i = 0; i < dna.length(); i++)
	{
		char base = dna[i];
		x += DNAbase_to_mRNAbase(base);
	}
	return x;
}

int main ()
{
	ifstream fin;
	fin.open("dna2b.txt");
	if(fin.fail())
	{
		cerr << "File cannot be read, opened, or does exist.\n";
		exit(1);
	}
    ifstream find;
    find.open("codons.tsv");
    if (find.fail())
    {
        cer << "File cannot be read, opened, or does exist.\n";
        exit(1);
    }
	string strand;
	while(getline (fin, strand))
	{
        //takes the string within the file and places it within a function
        //this allows us to take the contents of the file
        //and manipulate them with our function
		cout << DNA_to_mRNA(strand) << endl;
	}
	fin.close();
	return 0;
    //
}
