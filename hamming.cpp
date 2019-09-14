//Quinton Negron
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <climits>
using namespace std;

//The main bulk of this program is based on task 2b
//This program is specifically about taking 2 pairs of strings
//and noting the differecnes between the 2
//For the most part if the stirngs are the same
//then the program moves on to the next pair
//however if the program sees any difference
//then it will move on to a seperate process
//where it counts the differecnes in each string array
//That part works and on its on will produce a sufficent result
//However another half of the project is to work with codons
//So it uses the stuff from 2b, allowing it check if the strands will change
//Ultimately, there's 2 parts: one checks the changes in a pair
//and the other checks if there's codons that will result in actaul changes

string DNA_to_mRNA(string base)
{
    for(int i = 0; i < base.length(); i++)
    {
        if (base[i] == 'A')
        {
            base[i] = 'U';
        }
        else if (base[i] == 'T')
        {
            base[i] = 'A';
        }
        else if (base[i] == 'C')
        {
            base[i] = 'G';
        }
        else if (base[i] == 'G')
        {
            base[i] = 'C';
        }
        else if (base[i] == 'a')
        {
            base[i] = 'U';
        }
        else if (base[i] == 't')
        {
            base[i] = 'A';
        }
        else if (base[i] == 'c')
        {
            base[i] = 'G';
        }
        else if (base[i] == 'g')
        {
            base[i] = 'C';
        }
    }
    return base;
}

string tissue(string z, ifstream & dictionary)
{
    string gene, codon;
    dictionary.seekg(0);
    while (dictionary >> codon >> gene)
    {
        //cout << z << " " << codon;
        if (z == codon)
        {
            return gene;
        }
    }
    //cout << " Hi "<< gene << endl;
    return gene;
}

string change(string r, ifstream & dictionary)
{
    //cout << r;
    string transfer;
    bool transferag;
    transferag = false;
    for (int i = 0; i < r.length(); i+=3)
    {
        string gene = tissue(r.substr(i,3), dictionary);
        //cout << gene;
        if (gene == "Met")
        {
            transferag = true;
            transfer = "Met";
        }
        if (gene == "Stop")
        {
            transferag = false;
        }
        if (transferag == true) //&& gene != "Met")
        {
            //cout << transfer << endl;
    
            transfer = transfer + '-' + gene;
        }
    }
    //cout << transfer;
    return transfer;
}

string check(string cod1, string cod2)
{
    //cout << cod1 << " " << cod2;
    if (cod1 == cod2)
    {
        return " no";
    }
    return " yes";
}

int occur (string num1, string num2)
{
    int count = 0;
    for (int i = 0; i < num2.length(); i++)
    {
        if (num1[i] != num2[i])
        {
            count++;
        }
    }
    return count;
}

int main ()
{
    ifstream fin;
    fin.open("mutations.txt");
    if(fin.fail())
    {
        cerr << "File cannot be read, opened, or does exist.\n";
        exit(1);
    }
    ifstream find;
    find.open("codons.tsv");
    if (find.fail())
    {
        cerr << "File cannot be read, opened, or does exist.\n";
        exit(1);
    }
    string st1, st2;
    while(getline (fin, st1))
    {
        getline(fin, st2);
        st1 = DNA_to_mRNA(st1);
        st2 = DNA_to_mRNA(st2);
        string dna1 = change(st1, find);
        string dna2 = change(st2, find);
        int count = occur(st1, st2);
        cout << count << check(dna1, dna2) << endl;
    }
    fin.close();
    return 0;
}
