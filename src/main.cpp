
#include <iostream>
#include <string>
#include <fstream>


using namespace std;
string charCode[256];  //will contain the charCode array of strings
class frequencyCounter{

public:
	int charCounts[256];
//default constructor
    frequencyCounter(){
    	for(int i=0; i<256; i++){
    		this->charCounts[i]=0;
    	}//inatilze to 0

    }


 void computeCount(ifstream& inFile){

	  //datastructures
				unsigned char charIn;
				int index=0;

				if(inFile.is_open()){

				inFile>>noskipws;
				//Space between words need to include in the counting!!!

			  while(inFile>>charIn){ //read single character at a time


			       //step 2- index <- cast charIn to integer
			   index=(int)charIn;


				//step 3: charCounts[index]++, and ignore those greatr then 256
				if(index<256) { //ignore those greater then 255
					this->charCounts[index]++;
				}

		}//end while //step 4: repeat step 1 to step 3 while infile is not empty

				}else{
					cerr<<"Can not open the file"<<endl;
				}

 }//end computeCount

 void printAry(ofstream& outFile){

	 if(outFile.is_open()){

		 for(int index=0;index<256;index++) {
		 							//step2
		 	if(charCounts[index]>0) { //Do not print any charactors that have zero count.
		 													//cast index to character
		 	unsigned char c=(char)index;
		 	string temp(1, c);     //convert to string

		 	outFile<<c<<" "<<this->charCounts[index]<<endl;

		 	}//end if
		}//end for, step 4: repeat step 2 to step 3 while i < 256

	 }else{
			cerr<<"Can not open the file"<<endl;
	}

 }//end printAry



}; //end frequencyCounter

class treeNode{
public:
	string chStr;
		int prob;
		treeNode* next;
		treeNode* left;
		treeNode* right;
		string code;
		string charCode[256];


		// default-constructor with no paramater
		treeNode(){
			this->chStr="";
			this->prob=0;
			this->next=NULL;
			this->left=NULL;
			this->right=NULL;
			this->code="";
		}

		//constructor with two paramaters
		treeNode(string ch, int p){
			this->chStr=ch;
			this->prob=p;
			this->next=NULL;
			this->left=NULL;
			this->right=NULL;
			this->code="";
		}//end constructor


		void printNode(treeNode* T, ofstream &outFile){

			outFile << " (\"" <<T->chStr << "\", " << T->prob << "): "; //first one is empty data

			if(T->next!= NULL){
						outFile<<"(Next: \""<<T->next->chStr<<"\", "<<T->next->prob << ") ";
					}
					else{
						outFile<<"(Next: NULL) ";
					}
			if(T->left!= NULL){
						outFile<<"(Left: \""<<T->left->chStr<<"\", "<<T->left->prob << ") ";
					}
					else{
						outFile<<"(Left: NULL) ";
					}
					if(T->right!= NULL){
						outFile<<"(Right: \""<<T->right->chStr << "\", " << T->right->prob << ") --> ";
					}
					else{
						outFile<<"(Right: NULL) --> ";
					}

					outFile<<endl; //one print per text line

		}//end printTree-node

		///////////////////////////////////////////////////////////////////////////////////

};//end treeNode

class linkedList{

public:
	treeNode* listHead;

	 linkedList(){
	    	treeNode* myHeadNode;
	    	//Step 1:  listHead get a newNode as the dummy listNode with (“dummy” ,0),  listHead to point to.
	    myHeadNode= new treeNode("dummy", 0); //new since its a pointer constructor
	    this->listHead=myHeadNode;

 }//end consructor

	 treeNode* findSpot(treeNode *newNode) {
	    	treeNode* mySpot = listHead;  //start from the treeHead
	    	while(mySpot->next!=NULL && mySpot->next->prob<newNode->prob) {
	    		mySpot=mySpot->next;
	    	} //end while

	    	return mySpot;
	  }//end findSpot

	 void insertNewNode (treeNode *newNode) {
	    	treeNode* mySpot = findSpot(newNode);  //find spot, and insert the node
	    	newNode->next = mySpot->next;
	    	mySpot->next = newNode;
	    }//end inserNewtNode

	 void printList(ofstream& outFile) {

	     	treeNode* currentNode=listHead;
	     	   outFile<<"listHead -->";
	   		while(currentNode->next!=NULL) {
	    			outFile << "(\""<<currentNode->chStr << "\", " <<currentNode->prob<< ", \"" << currentNode->next->chStr << "\")-->";
	     		currentNode=currentNode->next;  //move to the next node

	   		}//end while
	     		//last element
	     		outFile << "(\""<<currentNode->chStr << "\", " <<currentNode->prob<< ", NULL)-->NULL"<<endl;
	     	}//end printList



	 void constructHuffmanLList(int charCount[], ofstream& outFile, linkedList* myLinkedList){

		 string ch;
		 int prob;
		 		// newNode;

		 int index=0;

		 		while(index<256){

		 			if(charCount[index]>0){
		 				prob=charCount[index];
		 				unsigned char c=(char)index;  //cast to char
		 				string temp(1, c);
		 				ch=temp;

		 				treeNode* newNode = new treeNode(ch,prob);  //create new node
		 	 			myLinkedList->insertNewNode(newNode);  //find spot and insert it

		 			}//end if
		 			index++;

		 		}//end while

		 		//print list-// Note: This printList is outside of the loop, therefore, you will only print the list once!!!
		 		myLinkedList->printList(outFile);


	 } //end constructHuffmanLinList



};
class HuffmanBinaryTree{

public:
	treeNode* root; //root of tree

	//constructors

	HuffmanBinaryTree(){
    this->root=NULL;
	}//end constructor

 void constructHuffmanBinTree (ofstream& outFile, linkedList* myLinkedList ){

	 while(myLinkedList->listHead->next->next!=NULL){

		 //create a new node, and set as a tree node
		 treeNode* myNode= new treeNode();  //create a tree node, and set as a tree node, with empty par

		 myNode->chStr=myLinkedList->listHead->next->chStr + myLinkedList->listHead->next->next->chStr; //conconate 1node+ 2nd node
		 myNode->prob=myLinkedList->listHead->next->prob + myLinkedList->listHead->next->next->prob; //1node + 2 node
		 myNode->left=myLinkedList->listHead->next; //left is the first node
		 myNode->right=myLinkedList->listHead->next->next; //right is the second node

		 outFile<<endl; //go to new line

		 //print hear


		 myLinkedList->insertNewNode(myNode); //find the spot, and insert one node (one method for both operation baby)

		 myLinkedList->listHead->next=myLinkedList->listHead->next->next->next;

		 myNode->printNode(myNode, outFile);


		 myLinkedList->printList(outFile);  //print the linkedlist

	 }//end while repeat step 1 – step 2 until the list only has one node left which is the newNode

	 this->root=myLinkedList->listHead->next;  //root is the new node

 }//end constructhuffmanLList

 bool isLeaf(treeNode* T){ // given node is a leaf if both left and right are null.

	 if(T->left==NULL && T->right==NULL){
		 return true;
	 }

	 return false;

 }//end isLeaf

 void preOrderTraversal(treeNode* T, ofstream& outFile){

	 //if (T is null) do nothing

	 if(T==NULL){
		 return;   //do nothing!
	 }else{
		 T->printNode(T, outFile);
		 preOrderTraversal(T->left, outFile);
		 preOrderTraversal(T->right, outFile);
	 }

} //end preOrderTraversal

 void inOrderTraversal(treeNode* T, ofstream& outFile){

 	 //if (T is null) do nothing

 	 if(T==NULL){
 		 return;   //do nothing!
 	 }else{
 		 inOrderTraversal(T->left, outFile);
 		 T->printNode(T, outFile);
 		 inOrderTraversal(T->right, outFile);
 	 }

 } //end ineOrderTraversal

 void postOrderTraversal(treeNode* T, ofstream& outFile){

 	 //if (T is null) do nothing

 	 if(T==NULL){
 		 return;   //do nothing!
 	 }else{
 		 postOrderTraversal(T->left, outFile);
 		 postOrderTraversal(T->right, outFile);
 		 T->printNode(T, outFile);
 	 }

 } //end ineOrderTraversal

void getCode(treeNode* T, string code, ofstream& outFile){

if(isLeaf(T)){
	T->code=code;  //set the tree code
	unsigned char chStr=T->chStr.at(0);  //the character

	int index=(int)chStr;

	T->charCode[index]=code;

	outFile<<chStr<<"\t"<<T->charCode[index]<<endl;  // new line after
	charCode[index]=T->charCode[index];

}else{

	getCode(T->left, code+"0", outFile);
	getCode(T->right, code+"1", outFile);


}//end else

}//end getCode

void Encode(ifstream& inFile, ofstream& outFile){

	           unsigned char charIn;
	              int index=0;
	              inFile>>noskipws; //dont skip whitespace
					if(inFile.is_open()){

					while(inFile>>charIn){ //read single character at a time

			       //step 2- index <- cast charIn to integer
				   index=(int)charIn;

				   //step 3: code =  charCode[index]
				   //write code to outFile
				   outFile<<charCode[index];
			}//end while //step 5: repeat step 1 to step 3 while infile is not empty


				}else{
					cerr<<"Can not open the file"<<endl;
				}


}//end Encode

void Decode(ifstream& inFile, ofstream& outFile, treeNode* T, treeNode* myRoot){

    unsigned char nextBit;
	if(isLeaf(T)){
	outFile<<T->chStr;
    Decode(inFile, outFile, myRoot, myRoot);    //decode from the root
	}else if(inFile.eof()&&!isLeaf(T)){
		cerr<<"the encode file is a corrupted file"<<endl;
	}else{
		inFile>>nextBit;
      if(nextBit=='0'){
    	  Decode(inFile, outFile, T->left, myRoot);
      }

      if(nextBit=='1'){
    	  Decode(inFile, outFile, T->right, myRoot);
      }

	}





}//end Decode

}; //end classhufmanBinaryTree

int main(int argc, char**argv) {


	ifstream inFile1;
	ifstream inFile2;

	inFile1.open(argv[1]);  //Input-1  (argv[1] ):  An English text file to compute char-prob pairs
	inFile2.open(argv[2]); //

	ofstream outFile1;
	ofstream outFile2;
	ofstream outFile3;  //for decode
	ofstream outFile4;

	outFile1.open(argv[3]);
	outFile2.open(argv[4]);
	outFile3.open(argv[5]);
	outFile4.open(argv[6]);    //outFile 4 (argv[6]):   for all the  debugging outputs.

	frequencyCounter myfrequencyCounter;

	//Step 1: computeCount (inFile1)
	myfrequencyCounter.computeCount(inFile1);
	myfrequencyCounter.printAry(outFile4);  //printAry

   //Step 2: constructHuffmanLList  (charCounts, outFile4)  // see below for method update
	 linkedList* myLinkedList= new linkedList();
	 outFile4<<endl;
	 myLinkedList->constructHuffmanLList(myfrequencyCounter.charCounts, outFile4, myLinkedList);

	 //Step 3:  constructHuffmanBinTree (listHead, outFile4) // No update, same as project 3
	 HuffmanBinaryTree* myBinaryTree= new HuffmanBinaryTree();
	 myBinaryTree->constructHuffmanBinTree(outFile4, myLinkedList);

	 myBinaryTree->getCode(myBinaryTree->root,"",outFile1);  //outFile1 (argv[3]): A text file contains the Huffman <char	, code> pairs

	 //Step 5: inFile2  open input file from argv[2] // the text file for encoding

	 //Step 6: Encode (inFile2, outFile2)  // new method, see algorithm steps below
     myBinaryTree->Encode(inFile2, outFile2);  //outFile2 (argv[4]): A text file contains the encoded result.

      //close input2file
     inFile2.close();  //close inputfile after encoding is complete
     outFile2.close(); //outputfile2 contains 1 and 0, that has to be decoded

     char userInput[100];
     cout<<"Enter file name to be Decoded (Ex: foo.txt)"<<endl;
     cin>>userInput;
     //Step 8: decodeFile  open the decodeFileName
     ifstream inFile3;
     inFile3.open(userInput);

    treeNode* myRoot=myBinaryTree->root;  //point at the root
     //Step 9: Decode (decodeFile, outFile3, Root)
        myBinaryTree->Decode(inFile3, outFile3, myBinaryTree->root, myRoot);

	 //step10-close all files
     inFile1.close();
     inFile3.close();

     //output-files
	outFile1.close();
	outFile3.close();
	outFile4.close();
	return 0;
}//end main
