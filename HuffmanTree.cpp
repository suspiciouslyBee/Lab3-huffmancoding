//#include "stdafx.h"

/**
 * Programmer: June
 * 
 * Class: CS233
 * 
 * Instructor Provided Huffman Tree, edited with implemented functions for Lab 3
 * Requirements. 
 * 
 * 
 */

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
	//we're just gonna grab the code from the unordered map..
	//assumption: normalizing to lowercase (for now)
	string returnStr;

	
	try{
		returnStr = codeLookup.at(tolower(letter));
	}
	catch(out_of_range &e){
		return "NOT FOUND";
	}
	return codeLookup.at(tolower(letter));
}

void HuffmanTree::makeEmpty(BinaryNode*& t) {
	// need to write code
}

void HuffmanTree::printTree(BinaryNode* node, std::ostream& out) const
{
	if(node->left){
		printTree(node->left, out);
	}
	if(node->right){
		printTree(node->right, out);
	}
		if(node->left == nullptr || node->right == nullptr){
		out << "\'" << node->element
		<< "\' with frequency: " << node->frequency << endl;
	}
}

void HuffmanTree::printCodes(BinaryNode* node, std::ostream& out, string code) const
{
	if(node->left){
		printCodes(node->left, out, code + "0");
	}
	if(node->right == nullptr){
		out << "\'" << node->element << "\' has code " << code << endl;
	}
	if(node->right){
		printCodes(node->right, out, code + "1");
	}
	
	return;
}
/*
string HuffmanTree::IntBinToStr(int element) {
	//temporary function to parse an element into a string
	string returnStr = "";

	if (element < 0) {
		//we do not wa
		return returnStr = "INVALID ELEMENT";
	}

	if (element == 0) {
		returnStr = "0";
		return returnStr;
	}

	for (int i = 1; (element >> i) > 0; i++) {
		returnStr += (element & 1) ? "1" : "0";
	}

	return returnStr;
}
*/


void HuffmanTree::saveTree(BinaryNode* current, string code)
{
	//build the unordered map in the hufftree

	/*
	the M.O. here is to build the unordered map tree. We need to recursively 
	take the frequency text, then recursively move down to a leaf. when we have
	found a leaf, we can then take the key value of the node and pop that from
	the string. this is probably horribly inefficient but im litterally writing
	this in Canada rn so i dont care. it just has to work. sorry lonnie
	*/
	


	//first thing we need to do is get the hell to the bottom. doesnt matter
	//what order
	if (current->left) {
		saveTree(current->left, code + "0");
	}
	if((current->left == nullptr) || (current->right == nullptr)){
		codeLookup[current->element[0]] = code;
	}
	if (current->right) {
		saveTree(current->right, code + "1");
	}


	

	//oh god
	//yes I KNOW its implied already, but current code flow would execute this
	//on internal nodes without a check. we need to insert the code only for 
	//children


	
}
/*
string HuffmanTree::buildBinary(BinaryNode* current) {

}
*/

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

	priority_queue<
		HuffmanTree::BinaryNode*, 
		vector<HuffmanTree::BinaryNode*>, 
		compareBinaryNodes
	>
	nodes;
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

	//really dumb code that somehow compiles

	while (frequencyText.size() > 0) { //basically while not empty

		currentLetter = frequencyText.at(0);

		//one and done to make a new binary node with the unique character and
		//its number of occurrances

		nodes.push(
			new BinaryNode(string{ currentLetter },
				std::count(frequencyText.begin(), frequencyText.end(),
					currentLetter)
			)
		);

		//the letter has outlived its purpose, tell the computer to cull it
		//string is passed by value, so can do whatever with it

		frequencyText.erase(
			std::remove(
				frequencyText.begin(), frequencyText.end(), currentLetter
			),
			frequencyText.end()
		);

		//now the size will be decreased, and we loop again
	}


	/*
	* at this point we now have the raw occurrance table, and now we need to
	* make "super nodes" that are combinations of the two, starting from the
	* top two.
	*
	* Pop the first two from root, make a "super node" with those nodes as a
	* child. (so constructing setting left and right) then inserting.
	*/

	BinaryNode* first = nullptr;
	BinaryNode* second = nullptr;
	BinaryNode* parent = nullptr;
	while (nodes.size() >= 2) {

		//we need to grab/remove the smallest elements which will be at root
		first = nodes.top();
		nodes.pop();
		second = nodes.top();
		nodes.pop();


		//cout << "Node 1: " 
		//	<< first->element << " " << first->frequency << endl;
		//cout << "Node 2: " 
		//<< second->element << " " << second->frequency << endl;

		
		//then we can now make the "super node" by constructing a combo



		nodes.push(new BinaryNode(
			first->element + second->element ,
			second->frequency + first->frequency ,
			first,
			second)
		);

		//priority queue will push the next smallest one to the top
		//repeat until there is one node.
	}




	return nodes.top(); //our tree will now be complete
}

HuffmanTree::HuffmanTree(string frequencyText)
{
	string blank = "";
	root = buildTree(frequencyText);
	printCodes(root, cout, blank);
	saveTree(root, blank);
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
	string dummy = "";
	printCodes(root, out, dummy);
	return;
}

// prints out the char and frequency
void HuffmanTree::printTree(std::ostream& out) const
{
	printTree(root, out);
	return;
}

void HuffmanTree::makeEmpty()
{
	// need to write code
	// calls recursive function	
}

string HuffmanTree::decode(vector<char> encodedBytes) {

	int i = 0;
	BinaryNode* it = root;
	string decoded = "";
	//every use we 'discard' the character by moving our iterator forward
	//take the top of the "stack", and that will guide us left or right
	//then we need to do something when we hit the end
	
	//TODO: CLEAN ME.

	while(i < encodedBytes.size() && 
		(encodedBytes.at(i) == '0' || encodedBytes.at(i) == '1')){
		
		if(it == nullptr){
			//OOB CHECK: WE SHOULDNT BE HERE
			return "Failure.";
		}

		if((it->right != nullptr) || (it->left != nullptr)){ //check for children
			if(encodedBytes.at(i)=='0'){
				it = it->left;
			}
			if(encodedBytes.at(i)=='1'){
				it = it->right;
			}
		} else {
			//no children
			decoded += it->element;
			it = root;
			i--;
		}

		i++;
	}
	decoded += it->element;


	return decoded;
}

vector<char> HuffmanTree::encode(string stringToEncode)
{
	stringToEncode.push_back(EOFCharacter); // needed when encoding message for file I/O

	vector<char> encoded;
	string encodedStr = ""; //garbage but i need something working
	for(int i = 0; i < stringToEncode.length() - 1; i++){
		encodedStr = encodedStr + getCode(stringToEncode.at(i)) ;
	}

	//convert the string to vector array
	for(int i = 0; i < encodedStr.length(); i++){

		encoded.push_back(encodedStr.at(i));
	}
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


