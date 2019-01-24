# Huffman-Coding
## Phase 1: Computing Frequency in Given File for char prob pairs:
Algorithm steps for counting:

Step 0: Open the input and output file.
: Initialize the charCounts array to Zero 

Step 1: charIn <- get the next character from the input file (inFile), each character at a time. 
Step 2: index <- cast the character (inChar) to an integer
Step 3: charCounts[index]++ <- increment the occurrence of that character to determine the probability.
Step 4: repeat steps 1 to 3 while while the file is not empty
Step 5: print the array. //The algorithm is listed below
Step 6: close all files.

Algorithm steps for printing Array:

Step 1: Begin from the first index (index<-- 0)

Step 2: if the charCounts[index]>0, if the occurrence of the symbol is more than 0
	: Symbol <-- cast index to character
	: Write the symbol character charCounts[index] per text line
Step 3: index ++ 

Step 4: Repeat step 2 and 3 while index is <256 
 
## Phase 2: Huffman Linked List Insertion 

Algorithm steps for computing:

Step 0: Allocate/initialize all member/linkList head.

Step 1: listHead  get a new node as the dumy listNode with (“dummy”, 0) for the listHead to point to.

Step 2: inFile open input file using argv[1]
          :outFIle  open ouput file using arg[2]

Step 3: chr   get  from inFile
            Prob   get  from inFile
	newNode  get a new listNode
        	newNode.chStr  chr
	newNode.prob  Prob
	newNode.next  null
Step 4: insertNewNode (listHead, newNode) //Algorithm provided next.

Step 5: printList (listHead) // Out put the list to outFile.

Step 6: repeat step 3 – step 5 until the end of inFile.

Step 7: close inFile
	close outFile

Algorithm for insertNewNode:

Step 1: First find the spot findspot(lHead, newNode) //Algorithm for findspot is provided next.

Step 2: Insert the newNode after the spot. That is, 
	newNode.next=mySpot.next
	mySpot.next=newNode

Algorithm for finding the spot: findSpot(lHead, newNode)

Step 1: let mySpot  listHead

Step 2: If mySpot.next is ≠ null and 
	    mySpot.next.Prob < newNode.Prob
	    mySpot=mySpot.next
 
Step 3: Repeat Step 2 until one of the conditions is false.

Step 4: Return the Spot.

## Phase 3: Huffman Coding Continued, constructing huffman Binary tree
Algorithm steps for computing:

Step 0: inFile  open input  file from argv[1]
:outFile1, outFile2, …, outFile5  open from argv[2], …, argv[6]

Step 1: constructHuffmanLList (inFile, outFile5), Algorithm is provided below

Step 2:  constructHuffmanBinTree (listHead, outFile5), Algorithm is provided below

Step 3: preOrderTraveral (Root, outFile2), In recursion
 inOrderTraversal (Root, outFile3), In recursion
postOrderTraveral (Root, outFile4), In recursion

Step 4:  getCode (Root, ‘’, outFile1) ,  ‘’ is an empty string


Algorithm steps for computing constructHuffmanLList (inFile, outFile5)

Step 1:  listHead  get a newNode as the dummy listNode with (“dummy” ,0),  listHead to point to

Step 3: chr   get  from inFile
            Prob   get  from inFile
	newNode  get a new listNode
        	newNode.chStr  chr
	newNode.prob  Prob
	newNode.next  null
Step 4: spot  findSpot (listHead, newNode) 
            insertOneNode(spot, newNode)

Step 5: printList (listHead, outFile) 
// print the list to outFile, from listHead to the end of the list 
// using the format given in the above.

Step 6: repeat step 3 – step 5 until the end of inFile .
	
Step 7: close inFile

Algorithm steps for computing constructHuffmanBinTree (listHead, outFile)

Step 1: newNode  create a treeNode
        newNode’s prob  the sum of prob of the first and second node of the list // first is the node after dummy
        newNode’s chStr  concatenate chStr of the first node and chStr of the second node in the list
        newNode’s left  the first node of the list
        newNode’s right  the second node of the list

Step 2: spot  findSpot(listHead, newNode)  

          insertOneNode (spot, newNode)  // inserting newNode between spot and spot.next.
				// only need two statements.
         listHead.next  listHead .next.next.next  

	printList (listHead, outFile) 

Step 3: repeat step 1 – step 2 until the list only has one node left which is the newNode

Step 4:  Root  newNode


Algorithm steps for computing getCode (T, code, outFile)

if  isLeaf (T)
	    
 	T.code =  code;
	 output   T. chStr  and T.code to outfile   // new line after 
	else 
	      constructCharCode (T->left, code + “0”) //string concatenation
	      constructCharCode (T->right, code + “1”) //string concatenation



Algorithm steps for computing preOrderTraveral (T, outFile)

if (T is null)
     do nothing
else
      printNode (T) // output to outFile,  see printing format in listBinTreeNode in above
      preOrderTraveral (T.left, outFile)
                  preOrderTraveral (T.right, outFile)


Algorithm steps for computing InOrderTraveral (T, outFile)

if (T is null)
     do nothing
else
      InOrderTraveral (T.left, outFile)
      printNode (T) // output to outFile,  see printing format in listBinTreeNode in above
                  InOrderTraveral (T.right, outFile)

Algorithm steps for computing postOrderTraveral (T, outFile)
if (T is null)
     do nothing
else
      postOrderTraveral (T.left, outFile)
                  postOrderTraveral (T.right, outFile)
                  printNode (T) // output to outFile,  see printing format in listBinTreeNode in above
Main (….)
Step 0: inFile  open input  file from argv[1]
outFile1, outFile2, …, outFile5  open from argv[2], …, argv[6]

Step 1: constructHuffmanLList  (inFile, outFile5) // see below
Step 2:  constructHuffmanBinTree (listHead, outFile5) // see below
Step 3: preOrderTraveral (Root, outFile2)  // In recursion
 inOrderTraversal (Root, outFile3) // In recursion
postOrderTraveral (Root, outFile4)// In recursion

Step 4:  getCode (Root, ‘’, outFile1) // ‘’ is an empty string

## Phase 4: Huffman Encode and Decode(continued)
Algorithm steps for computing:

Step1: Open a text file to compute the probabilities of characters in the file;
	and store the char-prob pairs in two 1-D arrays (charCounts[256] 
	as defined in project 1 with additional charCode [256]) in this project, 

	Output the char-prob pairs to an output file, as in your project 1.

Step 2:  Construct the ordered linked list from the char-prob pair and then,
             from the ordered linked list to construct the Huffman binary tree
             similar to your project 3. Output debugging print as in your project 3.

Step 3: Open a text file to be encoded (see algorithm below)
and outputs the encoded result (zero’s and 1’s ) to a text file.

Step 4: Next, asks the user for the name of the text file (1’s and 0’s) that is to be decode. 
Then,  do the decoding; then, 
output the result of the decode text to an output file.  
Main()
Step 0: inFile1  open input  file from argv[1]
outFile1, outFile2, …, outFile4  open from argv[3], …, argv[6]

Step 1: computeCount (inFile1) // see below for method update 
Step 2: constructHuffmanLList  (charCounts, outFile4)  // see below for method update
Step 3:  constructHuffmanBinTree (listHead, outFile4) // No update, same as project 3
Step 4:  getCode (Root, ‘’, outFile1) // ‘’ is an empty string // see below for method update
*** below are new for this project ***
Step 5: inFile2  open input file from argv[2] // the text file for encoding
Step 6: Encode (inFile2, outFile2)  // new method, see algorithm steps below
Step 7: decodeFileName  ask user from console to provide the name of the file to be decode
	// decodeFileName is a string variable!
Step 8: decodeFile  open the decodeFileName
Step 9: Decode (decodeFile, outFile3, Root) // new method, see algorithm steps below
Step 10: close all files
 


 computeCount (inFile)
  
step 1: charIn  read the next character from inFile, one character at a time
		// declare charIn as unsign char
	
step 2: index  cast charIn to integer // you may use atoi (charIn) function in C++

step 3: charCounts[index]++

step 4: repeat step 1 to step 3 while inFile is not empty

step 5: printAry (outFile4)

printAry (outFile) 

step 1: index 0
step 2: if charCounts[index] > 0
           symbol  cast index to character // you may use itoa (index) function in C++
           write symbol  charCounts[index]  per text line to outFile

step 3: index ++

step 4: repeat step 2 to step 3 while i < 256

.  constructHuffmanLList  (charCounts[], outFile)  
Step 1:  listHead  get a newNode as the dummy listNode with (“dummy” ,0),  listHead to point to.  
Step 2: index  0
Step 3: if charCount[index] > 0
	chr   cast index to asci // you may use C++ itoa function 
            	Prob   charCounts [index]
	newNode  get a new listNode
        	newNode.chStr  chr
	newNode.prob  Prob
	newNode.next  null
spot  findSpot (listHead, newNode) // use algorithm steps given in class
           	insertOneNode(spot, newNode) // insert newNode after spot
Step 4: index++
Step 5: repeat step 3 – step 4 while index <= 255
Step 6:  printList (listHead, outFile) 

constructHuffmanBinTree (listHead, outFile) 
Step 1: newNode  create a treeNode
        newNode’s prob  the sum of prob of the first and second node of the list // first is the node after dummy
        newNode’s chStr  concatenate chStr of the first node and chStr of the second node in the list
        newNode’s left  the first node of the list
        newNode’s right  the second node of the list

Step 2: spot  findSpot(listHead, newNode)  

          insertOneNode (spot, newNode)  // inserting newNode between spot and spot.next.
				// only need two statements.
         listHead.next  listHead .next.next.next  //  

	printList (listHead, outFile)  // 

Step 3: repeat step 1 – step 2 until the list only has one node left which is the newNode

Step 4:  Root  newNode
getCode (T, code) 

if  isLeaf (T)
	    
 	T.code  code;
       Index cast T. chStr  to integer, you may use C++ atoi function
	charCode[index]  code  
	else 
	      constructCharCode (T->left, code + “0”) //string concatenation
	      constructCharCode (T->right, code + “1”) //string concatenation

Encode (inFile, outFile)

step 1: charIn  read the next character from inFile, one character at a time
		// including spaces!!!

step 2: index  cast charIn to integer  // You may use C++ atoi function

step 3: code   charCode[index]

step 4: write code to outFile  

step 5: repeat step 1 to step 4 while inFile is not empty 

Decode (inFile, outFile, node) // a recursive function!
if isLeaf (node)
   		Write node.chr to outFile
		 Decode (inFile, outFile, Root)
else
    if eof inFile  // and node is NOT a leaf
	write error message “the encode file is a corrupted file”
   else 
 nextBit  read the next char from inFile
if nextBit is ‘0’
Decode (inFile, outFile, node’s left)
           		If nextBit is ‘1’ 
Decode (inFile, outFile, node’s right)
