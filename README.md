# DNA-strands
The start of a project that aims to look at DNA strands and see how they mutate 

When this project started it was dna.cpp, translatse.cpp, hamming.cpp, and then frameshift.cpp in that order. Of the 4, frameshift.cpp is the most definitive version, incorporating elements from the first 3. To use frameshift.cpp, make sure to include the frameshift_mutations.txt and codons.tsv file in your current directory when running the executable.

frameshift's job is to read the frameshift_mutations.txt, and look for triplets in the file that will mutate. The catch is that depending on how the strands mutate will result in a strand that ends the line premuturly (codons like UAA, UGA, and UAG causes this happen). This is done through a mixture of passing each character and checking what it forms in combination with the codons.tsv file to see what it becomes.
