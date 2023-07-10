// c++ that implement the scenario of mushroom

//AGARIC JAUNISSANT:-GI LLS->MEADOWS(NO FOREST)->COMVEX CUP ->RING
//AMANITE TUEMOUCHE:-GILLS->FOREST->COMVEX CUP ->RING 
//CEPE DE BORDEAU:-PORES(NO GILLS)->FOREST->(NO COMVEX CUP) ->(NO RING)
//COPRIN CHEVELU:-GILLS->MEADOWS(NO FOREST)->(NO COMVEX CUP) ->RING
//GIROLLE:-GILLS->FORESTS->(NO COMVEX CUP)->(NO RING)
//PIED BLEU:-GILLS->FOREST-> COMVEX CUP->(NO RING)

#include<iostream>
using namespace std;
int main(){
	string gills, forest, ring, comvex_cup;
	cout<<"----- please enter y for yes and n for no ------- \n \n";
	cout<<"does your mushrooom have gills :\n";
	cin>>gills;
	cout<<"does your mushroom grow in forest ?: \n";
	cin>> forest;
	cout<<"does your mushroom have a ring ?: \n";
	cin>> ring;
	

if(gills =="yes"&&forest =="yes"&&ring =="yes"){
		cout<<"your mushroom is: AMANITE TUEMOUCHE";
	}
	else if(gills == "yes"&&forest == "no"&&ring =="yes"){
		cout<<"your mushroom is : AGARIC JAUNISSANT";
	}
	else if(gills =="no"&&forest =="yes"&&ring =="no"){
		cout<<"your mushroom is : CEPE DE BORDEAU";
	}
		else if(gills =="yes"&&forest =="yes"&&ring =="no"){
		cout<<"does your mushroom have comvex cup? : \n";
	cin>> comvex_cup;
	if(comvex_cup =="yes") cout<<"your mushrooom is: GIROLLE ";
	else if(comvex_cup =="no")
	cout<<" your mushroom is : PIED BLEU";
	}
	
	else if (gills!="yes"||gills!="no"||forest!="yes"||forest!="no"||
ring!="no"||ring!="no"){
	cout<<" answer must be only either yes or no !!\n";
}else
cout<<"no mushroom match!";	

	return 0;
}

