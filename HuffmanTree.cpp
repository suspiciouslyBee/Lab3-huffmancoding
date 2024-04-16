//#include "stdafx.h"

#include <string>
#include <vector>
#include <fstream> 
#include <iostream>
#include <queue>    
#include <algorithm>
#include <iomanip> 
#include <bitset>
#include <unordered_map>
#include <sstream>

#include "HuffmanTree.h"

using namespace std;

inline bool HuffmanTree::getBit(unsigned char byte, int position) const
{
	return (byte & BITMASK[position]);
}

// Usage
// mybyte = setBit(mybyte,4);
// This sets the bit in position 4
inline unsigned char HuffmanTree::setBit(unsigned char byte, int position) const
{
	return  byte | BITMASK[position];
}

void HuffmanTree::printBits(char binary, std::ostream& out) const
{
	for (size_t i = 0; i < sizeof(char) * 8; i++) {
		if (getBit(binary, i)) {
			out << 1;
		}
		else {
			out << 0;
		}
	}
}

void HuffmanTree::printBinary(vector<char> bytes, std::ostream& out) const
{
	for (char byte : bytes)
	{
		printBits(byte, out);
		out << "-";
	}

}

string HuffmanTree::getCode(char letter) const
{
	string code = "";

	// need to write code

	return code;
}

void HuffmanTree::makeEmpty(BinaryNode*& t) {
	// need to write code
}

void HuffmanTree::printTree(BinaryNode* node, std::ostream& out) const
{
	// need to write code
}

void HuffmanTree::printCodes(BinaryNode* node, std::ostream& out, string code) const
{
	// need to write code
}


void HuffmanTree::saveTree(BinaryNode* current, string code)
{
	// need to write code
}

// writes tree information to file so the tree can be rebuilt when unzipping
void HuffmanTree::saveTree(std::ostream& compressedFileStream)
{
	// need to write code
	// calls recursive function
}


void HuffmanTree::rebuildTree(BinaryNode* node, string element, string codedRoute)
{

	// need to write code

}

void HuffmanTree::rebuildTree(ifstream& compressedFile) {
	// read info from file
	// use info to build tree

	// need to write code
	// calls recursive function
}

HuffmanTree::BinaryNode* HuffmanTree::buildTree(string frequencyText) {
	//We need to begin with building a table of frequencies with the string
	priority_queue<HuffmanTree::BinaryNode*,
		vector<HuffmanTree::BinaryNode*>,
		compareBinaryNodes > nodes;
	//This Priority queue automatically sorts by number of occurances

	/*
	* We need to store each letter into a node, get the number of occurances it
	* has, then made a new BinaryNode to store it. we can then push it into the
	* priority queue, which will sort it by weight (hopefully pushing weight at
	* the bottom)
	*
	* We scan the cString charcter by character, with each new character
	* calling new dynamic memory and storing it there. This will be garbage and
	* unoptimized. Too bad.
	*
	* find the first unknown character, start making a count, scan entire thing
	* I am tainted: there was a StackOverflow that gave me both a hint, but
	* also showed an explanation why to do erase(remove):
	* https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c
	*
	* also stole some help from https://stackoverflow.com/questions/17201590/how-can-i-create-a-string-from-a-single-character
	*
	*/

	char currentLetter = 0;

	while (frequencyText.size() > 0) {

		currentLetter = frequencyText.at(0);
		string singleDamnLetter{ currentLetter };	//WHY WTF THIS

		nodes.push(
			new BinaryNode(singleDamnLetter,
				std::count(frequencyText.begin(), frequencyText.end(),
					currentLetter)
			)
		);

		frequencyText.erase(
			std::remove(
				frequencyText.begin(), frequencyText.end(),
				currentLetter)
		);
	}





	return nodes.top();
}

HuffmanTree::HuffmanTree(string frequencyText)
{
	root = buildTree(frequencyText);
	//saveTree(root, string());   // build the lookupTable for codes...can write later
}

HuffmanTree::HuffmanTree(ifstream& frequencyStream) {

	std::string frequencyText((std::istreambuf_iterator<char>(frequencyStream)),
		std::istreambuf_iterator<char>());    // builds the frequencyText by using STL iterators
	frequencyStream.close();
	if (frequencyText.size() > 0) {
		root = buildTree(frequencyText);
		//saveTree(root, string());   // build the lookupTable for codes
	}
}

HuffmanTree::~HuffmanTree()
{
	// need to write code	
}

// print out the char and its encoding
void HuffmanTree::printCodes(std::ostream& out) const
{
	// need to write code
	// calls recursive function
}

// prints out the char and frequency
void HuffmanTree::printTree(std::ostream& out) const
{
	// need to write code
	// calls recursive function
}

void HuffmanTree::makeEmpty()
{
	// need to write code
	// calls recursive function	
}

string HuffmanTree::decode(vector<char> encodedBytes) {
	string decoded;

	// need to write code

	return decoded;
}

vector<char> HuffmanTree::encode(string stringToEncode)
{
	stringToEncode.push_back(EOFCharacter); // needed when encoding message for file I/O

	vector<char> encoded;

	// need to write code

	return encoded;
}

void HuffmanTree::uncompressFile(string compressedFileName,
	string uncompressedToFileName) {
	// need to write code	

	// NOTE: when opening the compressedFile, you need to open in 
	//  binary mode for reading..hmmm..why is that?
}

void HuffmanTree::compressFile(string compressToFileName,
	string uncompressedFileName, bool buildNewTree) {
	// need to write code	

	// NOTE: when opening the compressedFile, you need to open in 
	//  binary mode for writing..hmmm..why is that?
}


