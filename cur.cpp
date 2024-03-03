/*
	Author : Kathan Majithia
	Date : 03-03-2024
	Task : Enterprise level adaptable and scalable ATM denomination APP
			(by MSU runtime Round 3)
*/
#include<iostream>

using namespace std;

int notes[30] = {2000,500,200,100,50,20,10}; // Notes arrange in descending order
int size = 7; // size will vary upon insert and delete

void addnotes(){ // New notes will be added
	cout<<"\nEnter note (multiple of 10) : ";
	int newnote,ind,flag=0;
	cin>>newnote;
	for(int i=0;i<size;i++){
		if(newnote == notes[i]){ // Check if note exist.
			flag=1;
			break;
		}
	}
	if(newnote % 10 == 0 && !flag){
		for(int i=0;i<size;i++){
			if(newnote > notes[i]){ 
				ind = i; // Find perfect place to add note
				break;
		}
		}
		// Insert note in descending order
		for(int i=size;i>ind;i--)
			notes[i] = notes[i-1];
		notes[ind] = newnote;	
		size++;
		cout<<"\nNote of "<<newnote<<" added.";
	}else{
		cout<<"\nNote could not be added.";
	}
}

void deletenotes(){
	cout<<"\nEnter note to delete : ";
	int del,ind,fl=0;
	cin>>del;
	for(int i=0;i<size;i++){
		if(del == notes[i]){ // Delete only if note exist
			ind = i;
			fl=1;break;
		}
	}
	if(fl){
		for(int i=ind;i<size;i++){
			notes[i] = notes[i+1]; // Delete logic
		}
		size--;
		cout<<"\nNote of "<<del<<" deleted.";
	}
	else
		cout<<"\nNote doesn't exist.";
	
}

void amount(){
//	cout<<"\nNotes : ";
//	for(int i=0;i<size;i++)
//		cout<<notes[i]<<" ";
	long amo;
	int non=0; // number of notes
	cout<<"\nEnter amount to be withdrawn (multiple of 10) : ";
	cin>>amo;
	if(amo % 10 == 0 && amo > 10){
	cout<<"\n\nWithdrawn summary : ";
		for(int i=0;i<size;){
			if(amo >= notes[i]){
				non++;
				amo -= notes[i];
			}else{
			if(non > 0){
				cout<<non<<" note(s) of "<<notes[i]<<(amo==0?".":", ");
				non = 0;
			}	
				i++;
			}
		}
	}else{
		cout<<"\nInvalid amount.";
	}
}

int main(){
	int ch=1;
	while(ch){
		cout<<"\n\nEnter 1 to add notes : \nEnter 2 to delete notes : \nEnter 3 to input amount : ";
		cin>>ch;
		switch(ch){
			case 1:addnotes();
					break;
			case 2:deletenotes();
					break;
			case 3:amount();
					break;
			default:cout<<"\nThank you for using our app.";
			ch = 0;		
		}
	}
}
