//Minh-Thai Nguyen
//4/3/2018
//This program implements the data structures of stacks and queues through singly linked lists to interpret commmands from an input file and writes the corresponding output to an output file. 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <list>
#include <iterator>
#include <typeinfo>
#include <cmath>

using namespace std;


void ReadFile(ifstream& a, ofstream& b);

//This creates a node with both data and a pointer to the next node
template <typename T>
struct node
{
	T data;
	node *next;	
};	

//Class declaration Simple List with member functions for inserting a nodeat the end of the list, inserting a node at the start of the list, and deleting the first node of list
//Also declares virtual pop and push functions that call one of the three other member functions.
//Also defines a node and a string name, along with a function that sets the name.
template <typename T>
class SimpleList{
	protected:
		node <T> *head, *tail;
		
		void InsertEnd( T v );
		void InsertStart( T v );
		T DeleteFirst( void );
		
	public:

		SimpleList()
		{
			head = NULL;
			tail = NULL;
		}
		
		virtual T pop()=0;
		virtual void push( T v )=0;

		void SetName( string a ){
			name=a;
		}

		string name;
};

//Inserts a new node at the end of the list and reassigns head and tail. 
template <typename T>
void SimpleList<T>::InsertEnd(T val)
{
	node <T> *var=new node <T>;
	var->data=val;
	var->next=NULL;

	if(head==NULL)
	{
		head=var;
		tail=var;
		var=NULL;
	}
	else
	{
		tail->next=var;
		tail=var;
	}
}

//Inserts a new node at the beginning list and reassigns head and tail if necessary
template <typename T>
void SimpleList<T>::InsertStart(T val)
{
	node <T> *var=new node <T>;
	var->data=val;
	var->next=head;
	head=var;

	if(head==NULL)
	{
		head=var;
		tail=var;
		var=NULL;
	}
}

//Deletes the first item in the list, throwing exceptions if the list is empty.
template<typename T>
T SimpleList<T>::DeleteFirst()
{
	T x;	
	if(head==NULL && tail==NULL)
		throw "ERROR: This list is empty!";
	else
	{
		node <T> *v=new node <T>;
		v=head;
		if(head==NULL)
		{
			tail=NULL;
			throw "ERROR: This list is empty!";
		}
		head=head->next;
		return v->data;
		delete v;
	}
}

//This Stack class defines the virtual push and pop member functions which call the appropriate member function
//in this case it calls InsertStart for push and DeleteFirst for pop
template <typename T>
class Stack: public SimpleList<T>{
	public:
	       void push( T val ){
		       this->InsertStart( val );
	       }
	       T pop(){
		       return this->DeleteFirst();
	       }
};

//This Queue class defines the virtual push and pop member functions which call the appropriate member function
//in this case it calls InsertEnd for push and DeleteFirst for pop
template <typename T>
class Queue: public SimpleList<T>{
	public:
		void push( T val ){
			this->InsertEnd( val );
		}
		T pop(){
			return this->DeleteFirst();
		}
};

//This function checks the name of the read line and calls the appropriate functions for the words or creates a new queue or stack.
//If a syntax is violated it will display an error message. 
template <typename T>
void CheckName( vector <string> v, list<SimpleList<T> *>& list1, ofstream& outfile )
{
	typename list<SimpleList<T> *>::iterator it;	
	for(it = list1.begin(); it != list1.end(); it++)
	{
		if((*it)->name==v[1])
		{
			try
			{

			if(v[0] == "create")
			{
				outfile<<"ERROR: This name already exists!"<<endl;
				return;
			}
			if(v[0]== "push")
			{
				stringstream ss(v[2]);
				T x;
				ss >> x;
				(*it)->push(x);
				return;
			}
			if(v[0]== "pop")
			{
				T x = (*it)->pop();
					
					outfile<<"Value popped: "<<x<<endl;	
				return;
			}
			}
			catch(const char* msg)
			{
				outfile<<msg<<endl;
				return;
			}
		}
	}
	if(v[0] =="create")
 	{	
 		if(v[2]=="queue")
		{
			Queue <T> *temp = new Queue <T>;
			temp->SetName(v[1]);
			list1.push_back(temp);
		}
		if(v[2]=="stack")
		{
			Stack <T> *temp = new Stack <T>;
			temp->SetName(v[1]);
			list1.push_back(temp);
		}
	}
	else
	{
		outfile<<"ERROR: This name does not exist!"<<endl;

	}	
	return;
}

//main function that defines infile and outfile and passes it to ReadFile
int main()
{
	string InputFile;
	string OutputFile;
	
	cout << "What is the name of the input file?\n";
	cin >> InputFile;

	cout << "What is the name of the output file?\n";
	cin >> OutputFile;
	ifstream infile(InputFile);	
	ofstream outfile(OutputFile);

	ReadFile(infile, outfile);
	return 0;	
}

//This function reads the input file line by line and calls the CheckName function, passing the correct lists and variables.
//Also outputs the PROCESSING COMMAND: line and outputs an error message if the file doesn't open.
void ReadFile(ifstream& infile, ofstream& outfile)
{
	string line;
	string words;
	vector <string> v1;
	
	list<SimpleList<int> *> listSLi;
	list<SimpleList<double> *> listSLd;
	list<SimpleList<string> *> listSLs;	
	
	if (infile)
	{

		
		while(getline(infile, line))
		{
			
			stringstream ss(line);
			
			while(ss >> words) 	
				v1.push_back(words);
				
			outfile<<"PROCESSING COMMAND: " << line<<endl; 	
			switch(v1[1][0])
				{
					case 'i':
						CheckName(v1, listSLi, outfile);
						break;
					case 'd':
						CheckName(v1, listSLd, outfile);
						break;
					case 's':
						CheckName(v1, listSLs, outfile);
						break;	
				}
			v1.clear();
		}
		
	
		infile.close();

	}
	else
		cout<<"File didn't open\n";
}


template <typename T>
void CheckName( vector <string> v, list<SimpleList<T> *>& list1, ofstream& outfile );

