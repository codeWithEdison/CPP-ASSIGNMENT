//c++ that implement bicycles rental program

//0-7 && 21-24:500 rwf
//7-14 && 19-21: 1000 rwf
//14-19: 1500 rwf
#include<iostream>
using namespace std;
int main(){
	int start_time, end_time, amaunt=0, time, payment;
	 cout<<"enter stating time:\n";	
	 cin>>start_time;
	
	 cout<<" enter ending time: \n";
	 cin>>end_time;
	  if(start_time<0 || start_time>23){
	 	cout<<"starting time must between 0 and 23\n";
	 }
	 else if(end_time<1 || end_time>24){
	 	cout<<"ending time must between 1 and 24\n";
	 }
	else if(start_time >= end_time){
	 	cout<<"staring time must be always less than ending time!!\n";
	 }
	 else{
	 	time=end_time-start_time;
	 	
	 	if(time>=0 &&  time<=7 || time>=21 && time<=24){
	 		amaunt=time*500;
		 }
		 else if(time>=7 && time<=14 || time>=19 &&  time<=21){
	 		amaunt=time*1000;
		 }
		 else if(time>=14 && time<=19){
		 	amaunt=time*1500;
		 
		 }
		 cout<<"you use bicycle in "<< time<<"hours \n"<<"you will pay "<<amaunt<<" rwf";
	 }
	 return 0;
}

