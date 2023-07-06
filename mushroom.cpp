// c++ that implement the scenario of mushroom

#include<iostream>
using namespace std;
int main(){
	char gills, forest, ring, comvex_cup;
	cout<<"----- please enter y for yes and n for no ------- \n \n";
	cout<<"does your mushrooom have gills :\n";
	cin>>gills;
	cout<<"does your mushroom grow in forest? \n";
	cin>> forest;
	cout<<"does your mushroom have a ring ?: \n";
	cin>> ring;
	
if(gills =='y'&&forest =='y'&&ring =='y'){
		cout<<"your mushroom is: AMANITE TUEMOUCHE";
	}
	else if(gills == 'y'&&forest == 'n'&&ring =='y'){
		cout<<"your mushroom is : AGARIC JAUNISSANT";
	}
	else if(gills =='n'&&forest =='y'&&ring =='n'){
		cout<<"your mushroom is : CEPE DE BORDEAU";
	}
		else if(gills =='y'&&forest =='y'&&ring =='n'){
		cout<<"does your mushroom have comvex cup? : \n";
	cin>> comvex_cup;
	if(comvex_cup =='y') cout<<"your mushrooom is: GIROLLE ";
	else if(comvex_cup =='n')
	cout<<" your mushroom is : PIED BLEU";
	}

else
cout<<"no mushroom match!\n";
	return 0;
}

