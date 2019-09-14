//Quinton Negron
//This program reads a DNA strand
//and returns it's mRNA complement
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <climits>
using namespace std;


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
//
string tissue(string z, ifstream & dictionary)
{
    string gene, codon, anew;
    //cout << z << endl;
    dictionary.seekg(0);
    while (dictionary >> codon >> gene)
    {
        //cout << z << " " << codon << endl;
        if (z == codon)
        {
            //cout << "bird" << endl;
            return (anew = gene);
        }
        //cout << codon << endl;
    }
    return anew;
}

//instead of using the code provided online I went with this
//Using 2 functins to: read the second half of a codon and see what is inside
//and refer to the dictionary to see what we can do with that second part of the codon
string change(string r, ifstream & dictionary)
{
    string transfer;
    bool transferag;
    transferag = false;
    string gene;
    for (int i = 0; i <= r.length(); i+=3)
    {
        gene = tissue(r.substr(i,3), dictionary);
        
        if (gene == "Met")
        {
            transferag = true;
            transfer = "Met";
        }
        if (gene == "Stop")
        {
            transferag = false;
            return transfer;
        }
        if (transferag == true && gene != "Met" && !gene.empty())
        {
            transfer = transfer + '-' + gene;
        }
    }
    return transfer;
}

string DNA(string beta, ifstream & dictionary)
{
    for(int i=0; i < beta.length(); i++)
    {
        if(beta.substr(i,3) == "AUG")
        {
            return change(beta.substr(i), dictionary);
        }
    }
    return "";
}

int main ()
{
    ifstream fin;
    fin.open("frameshift_mutations.txt");
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
    string base;
    string base2;
    while(getline (fin, base) && getline(fin, base2))
    {
        string mutant = DNA_to_mRNA(base);
        string mutation = DNA_to_mRNA(base2);
        string protein = change(mutant,find);
        string protein2 = DNA(mutation, find);
        cout << protein << endl;
        cout << protein2 << endl;
        
    }
    fin.close();
    return 0;
    //
}
