// c++ that implement the scenario of mushroom

//AGARIC JAUNISSANT:-GI LLS->MEADOWS(NO FOREST)->COMVEX CUP ->RING
//AMANITE TUEMOUCHE:-GILLS->FOREST->COMVEX CUP ->RING 
//CEPE DE BORDEAU:-PORES(NO GILLS)->FOREST->(NO COMVEX CUP) ->(NO RING)
//COPRIN CHEVELU:-GILLS->MEADOWS(NO FOREST)->(NO COMVEX CUP) ->RING
//GIROLLE:-GILLS->FORESTS->(NO COMVEX CUP)->(NO RING)
//PIED BLEU:-GILLS->FOREST-> COMVEX CUP->(NO RING)

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Define variables to store user input for mushroom characteristics
    string gills, forest, ring, comvex_cup;

    // Prompt the user to provide yes or no answers for mushroom characteristics
    cout << "----- please enter yes OR no ------- \n \n";

    // Function to get valid input ("yes" or "no") from the user
    auto getValidInput = []() -> string {
        string input;
        while (true) {
            cin >> input;
            if (input == "yes" || input == "no") {
                break;
            } else {
                cout << "Please enter 'yes' or 'no': ";
            }
        }
        return input;
    };

    cout << "does your mushroom have gills: \n";
    gills = getValidInput();

    // First question
    if (gills == "yes") {
        cout << "does your mushroom grow in a forest?: \n";
        forest = getValidInput();

        // Second question
        if (forest == "yes") {
            cout << "does your mushroom have a ring?: \n";
            ring = getValidInput();

            // Third question
            if (ring == "yes") {
                cout << "your mushroom is: AMANITE TUEMOUCHE";
            } else {
                cout << "your mushroom is: AGARIC JAUNISSANT";
            }
        } else {
            cout << "your mushroom is: CEPE DE BORDEAU";
        }
    } else {
        cout << "does your mushroom have a convex cup?: \n";
        comvex_cup = getValidInput();

        // Second question
        if (comvex_cup == "yes") {
            cout << "your mushroom is: GIROLLE";
        } else {
            cout << "your mushroom is: PIED BLEU";
        }
    }

    return 0;
}
