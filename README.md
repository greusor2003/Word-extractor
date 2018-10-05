# Word-extractor
Basic IO operations outputting the list of distinct words from a text file.

This is a very simple program that extracts the words from a text file and puts them listed in alphabetical order with no duplicates in another file. The code purges the input file of the punctuation marks and other unwanted characters enumerated in the vector char stopchar[] that can be customized upon needs.

To compile on Linux, type at the terminal 
g++ Exmpl_IOExtractWords.cpp -o executable
To run, type 
./executable 
