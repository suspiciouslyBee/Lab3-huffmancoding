// HuffmanCoding.cpp: unit test for HuffmanTree
// Programmer :June

// WARNING: WILL TAKE SEVERAL MINUTES TO COMPRESS


#include <string>
#include <fstream>
#include <streambuf>
#include <queue>
#include <functional>

#include "HuffmanTree.h"

using namespace std;

int main() {



	// SUGGESTION: write and test the functions in the order called below
	//         (some of the functions may need to call other private functions)
       
	cout << "\n\ntest 1\n";
	cout << "\n\nbuilding the tree from: hhhheellllllloo wooooorrlllllldp\n";
	HuffmanTree tree("hhhheellllllloo wooooorrlllllldp");
	
	cout << "\n\nprinttree: \n";
	tree.printTree();
	
	cout << "\n\nprintCodes:\n";
	tree.printCodes();
	cout << endl << endl; 

	cout << "Code L :" <<tree.getCode('L') << endl;
	cout << "Code D :" << tree.getCode('D') << endl;


	//Test 2
	cout << "\n\nTest 2\n";
	vector<char> encoded = tree.encode("help"); 
	tree.printCodes();
	//  don't call for lab:  tree.printBinary(encoded);  // for lab, instead output chars inside encoded
	cout << endl;
	//
	cout << tree.decode(encoded) << ":" << endl;



	system("pause");  // LAB 3: Should run up to here with the above functions working with chars '1' and '0' 
						//			instead of making the changes at the binary level




	//Test 3
	//cout << "\n\nTest 3\n";
	std::ifstream frequencyStream("Bigo.txt");
	HuffmanTree tree2(frequencyStream);
	tree2.printTree();
	tree2.printCodes();

	tree2.compressFile("BigO.bin", "Bigo.txt");
	cout << endl << endl;
	tree2.printCodes();
	tree2.uncompressFile("BigO.bin", "BigORebuilt.txt");
	tree2.printTree();
	tree2.printCodes();

	////Test 4
	cout << "\n\nTest 4\n";
	std::ifstream frequencyStream2("20000leagues.txt");
	HuffmanTree tree3(frequencyStream2);
	tree3.printTree();
	tree3.printCodes();
	cout << "Code L :" << tree3.getCode('L') << endl;
	tree3.compressFile("20000leaguesComp.bin" ,"20000leagues.txt",true);
	tree3.uncompressFile("20000leaguesComp.bin", "20000leaguesRebuilt.txt");
	tree3.printTree();
	tree3.printCodes();

	// Try Other Files

	//// read in text file create string - might be useful
	std::ifstream bigtext("20000leagues.txt");
	std::string big((std::istreambuf_iterator<char>(bigtext)), 
				   std::istreambuf_iterator<char>());



	cout << "\n\nTest 5\n";
	std::ifstream frequencyStream3("Guliver's Travels.txt");
	HuffmanTree tree4(frequencyStream2);
	tree4.printTree();
	tree4.printCodes();
	cout << "Code L :" << tree4.getCode('L') << endl;
	tree4.compressFile("Guliver's TravelsComp.bin", "Guliver's Travels.txt", true);
	tree4.uncompressFile("Guliver's TravelsComp.bin", "Guliver's TravelsRebuilt.txt");
	tree4.printTree();
	tree4.printCodes();

	cout << "\n\nTest 6\n";
	std::ifstream frequencyStream4("HG Wells TimeMachine.txt");
	HuffmanTree tree5(frequencyStream2);
	tree5.printTree();
	tree5.printCodes();
	cout << "Code L :" << tree5.getCode('L') << endl;
	tree5.compressFile("HG Wells TimeMachineComp.bin", "HG Wells TimeMachine.txt", true);
	tree5.uncompressFile("HG Wells TimeMachineComp.bin", "HG Wells TimeMachineRebuilt.txt");
	tree5.printTree();
	tree5.printCodes();


	cout << endl;
	system("pause");
	return 0;
}

/*Output

test 1


building the tree from: hhhheellllllloo wooooorrlllllldp
'l' has code 0
'r' has code 1000
'e' has code 1001
'h' has code 101
'd' has code 11000
'p' has code 11001
' ' has code 11010
'w' has code 11011
'o' has code 111


printtree: 
'l' with frequency: 13
'r' with frequency: 2
'e' with frequency: 2
'h' with frequency: 4
'd' with frequency: 1
'p' with frequency: 1
' ' with frequency: 1
'w' with frequency: 1
'o' with frequency: 7


printCodes:
'l' has code 0
'r' has code 1000
'e' has code 1001
'h' has code 101
'd' has code 11000
'p' has code 11001
' ' has code 11010
'w' has code 11011
'o' has code 111


Code L :0
Code D :11000


Test 2
'l' has code 0
'r' has code 1000
'e' has code 1001
'h' has code 101
'd' has code 11000
'p' has code 11001
' ' has code 11010
'w' has code 11011
'o' has code 111

help:
sh: line 1: pause: command not found

sh: line 1: pause: command not found*/