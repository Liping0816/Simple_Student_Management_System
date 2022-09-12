#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
	void getData();
	void append();
	void del();
	void display();
	void search();
	void update();
	void save();
	void deleteall();
	void exitprog();


struct ListNode
{
	string name;
	string ID;
	string address;
	string phone;
	string DOB;
	string clas;
	ListNode *next;
	ListNode *prev;
};

ListNode *head = NULL, *pCur,*pCur2,*pRev;
int con = 1;         // use to identity data found or not
int numItem = 0;     // use to count number of data


int main(){
	
	getData();  //getdata **must not** be in a loop.
	//display();
	
	cout << "\n***********************************************************\n";
	cout << "\nPlease select your choice base on :\n";
	cout << "\nAdd(A)     Update(U)      Search(F)  Display(D)" << endl;
	cout << "\nRemove(M)  Remove all(E)  Save(S)    Exitprogram(N)" << endl;
	cout << "\n***********************************************************\n";
	
char choose;

	do{
		cout << "\n--------------------------------------------------------\n" ;
		cout << "\nchoose your operation : " ;
		cin >> choose;
		switch(choose){
			
			case 'A':
				append();
				break;
			
			case 'U':
				update();
				break;
			
			case 'F':
				search();
				break;
			
			case 'D':
				display();
				break;
			
			case 'M':
				del();
				break;
			
			case 'E':
				deleteall();
				break;
				
			case 'S':
				save();
				break;
				
			case 'N':
				exitprog();
				break;	
			
			default:
				cout << "Default" << endl;
				
		}
		
	}while(choose != 'N');

		
	return 0;
}

//************************Get Data*********************************
void getData() {
	
	ifstream of; 
	string temp;     //string to define space in database
	head = NULL;
	ListNode *tail = NULL;
	
	of.open(".\\record.txt");
	while (getline(of,temp)){    //store first name in temp
		
		if(temp.empty())break;   //break when read space
		
		ListNode *pNew = new ListNode;
		
		pNew->name = temp;       //point temp to name
		getline(of, pNew->ID);
		getline(of, pNew->address);
		getline(of, pNew->phone);
		getline(of, pNew->DOB);
		getline(of, pNew->clas );
		
		
		if(head == NULL){          //if link list blank,pNew become head
        	head = pNew;
    	}
    
	    else {
	    	tail->next = pNew;     //add the next pNew at end of list
	    	pNew->prev = tail;
		}
	
		tail = pNew;
		
		numItem++;
	
	}
	of.close();
}


//***************************Display************************************
void display(){
	
	cout << "--------------Printing Information----------------------\n\n";
	
	if (head == NULL){
		
		cout << "No data\n" << endl;
		cout << "----------------------END-------------------------------\n\n";
		return;
	}
	
	pCur = head;
	int no=0;
	while (pCur){
		
		no++;
		cout << "No. " << no << endl;
		cout << "Name      :" << pCur->name << endl;
		cout << "ID        :" << pCur->ID << endl;
		cout << "Address   :" << pCur->address << endl;
		cout << "Phone no. :" << pCur->phone << endl;
		cout << "DOB       :" << pCur->DOB << endl;
		cout << "Class     :" << pCur->clas << endl;
		cout << "-----------------------------------------\n";
		pCur = pCur->next;
		
	}
	
}


//************************** Append ***********************************
void append(){
	
    ListNode *pNew, *cur, *prev;
    cur = head;
	prev = NULL;

 		cout << "---------------Insert New Item--------------------------\n";
		pNew = new ListNode;
		
		cin.ignore();
		cout << "\nEnter Student name:  ";
		getline(std::cin, pNew->name);
		
		cout << "\nEnter Student ID:  ";
		getline(std::cin, pNew->ID);

		cout << "\nEnter Student address:  ";
		getline(std::cin, pNew->address);
		
		cout << "\nEnter Student phone:  ";
		getline(std::cin, pNew->phone);
		
		cout << "\nEnter Student DOB(DD/MM/YYYY):  ";
		getline(std::cin, pNew->DOB);
		
		cout << "\nEnter Student class:  ";
		getline(std::cin, pNew->clas);
		
		pNew->next = NULL;
		
		numItem++;
		
	if(head == NULL){
        head = pNew;
    }
    
//sort the new insert    
	else{
		while(cur != NULL && pNew->name > cur->name){
			prev = cur;
        	cur = cur->next;
    	}
    
	//insert pNew in front of the list
		if(prev == NULL){
			pNew->next = cur;
	        head = pNew;
	    }
	    
	//insert pNew at the middle or the end of the list    
		else {
			pNew->next = cur;
			prev->next = pNew;
	    }
    }

}
	

//*************************** Search ***********************************	
void search(){
	char find;
	string iData;
	string iName;
    pCur = head;
	pRev = NULL;
    
 /*   cout << "search by Name(n) or ID(i)?\n";
    cin >> find;
    
    if(find == 'n'){
    	cout << "\nPlease enter the student's name that you want to find : ";
		cin >> iName;
		cin.ignore();

		while(pCur != NULL && iName != pCur->name){
			pRev = pCur;
        	pCur = pCur->next;
    	}
	}
 */   
   // if(find == 'i'){
    	cout << "\nPlease enter the student's ID that you want to find : ";
		cin >> iData;
    	//pCur = head;

		while(pCur != NULL && iData != pCur->ID){
			pRev = pCur;
        	pCur = pCur->next;
    	}
	//}
    
	if(pCur == NULL){
		con = 0;     // data not found
		cout << "\nSorry the data is not found\n";
	}
		
	else{
		con = 1;     // data found
		cout << "\nYes, the data is found!\n";
		cout << "Name      :" << pCur->name << endl;
		cout << "ID        :" << pCur->ID << endl;
		cout << "Address   :" << pCur->address << endl;
		cout << "Phone no. :" << pCur->phone << endl;
		cout << "DOB       :" << pCur->DOB << endl;
		cout << "Class     :" << pCur->clas << endl;
	}
}


//************************* Delete *************************************
void del(){
	
	cout << "\nSearch the data that you want to DELETE:  " << endl;
	char confirm;
	search();
	
	if(con == 1){
		cout << "\nDo you want to delete this?(Y/N)" << endl;
		cin >> confirm;
	
		if(confirm =='Y'){
			if(pRev==NULL)head = pCur->next; //delete first data
			else pRev->next = pCur->next;    //non-first data,point prev's next to data's next
			
			pCur->next=NULL;                  // delete pCur(target data)
			delete pCur;
			
			cout << "The data was delete." << endl;
    	} 
		
		else cout << "You cancel the deletion." << endl;	
	}
}


//*************************** Update *************************************
void update(){
	
	cout << "\nSearch the data that you want to UPDATE:  " << endl;
	char confirm;
	search();
	
	if(con == 1){
		cout << "Do you want to update this?(Y/N)" << endl;
		cin >> confirm;
		cin.ignore();
	
		if(confirm =='Y'){
		
			cout << "\nEnter Student new address:  ";
			getline(std::cin, pCur->address);
			
			cout << "\nEnter Student new phone:  ";
			getline(std::cin, pCur->phone);
			
			cout << "\nEnter Student new class:  ";
			getline(std::cin, pCur->clas);
		
    	} 
		
		else cout << "You cancel the update." << endl;	
	}
	
}


//**************************** Save ************************************
void save(){
	
	std::ofstream wf;   //write file(wf)

	wf.open(".//record.txt"); 
	pCur = head;
	
	while(pCur != NULL){
		wf << pCur->name << endl;
		wf << pCur->ID << endl;
		wf << pCur->address << endl;
		wf << pCur->phone << endl;
		wf << pCur->DOB << endl;
		wf << pCur->clas << endl;
		
		pCur = pCur->next;
	}
	
	wf.close();
	cout << "The data has been save." << endl;
}


//************************** Delete All ************************************
void deleteall(){
	
	ListNode *temphead = head, *temp;
	
	while (temphead){
		
		temp = temphead->next;
		delete temphead;
		temphead = temp;
		
	}
	
	cout << "All the data has been remove";
	head = NULL;
	numItem=0;
	
}


//************************** Exit Program ***********************************
void exitprog(){
	
	system("CLS");
	cout << "\n-----------Thank you for using this system-------------\n\n";
	
}


