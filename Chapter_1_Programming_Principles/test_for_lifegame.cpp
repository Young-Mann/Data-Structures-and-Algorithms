#include <iostream>
using namespace std;
#include "lifegame.h"
#include "lifegame.cpp"




int main()
/* Pre:   The user supplies an initial configuration of living cells.
   Posts: The program prints a sequence of pictures showing the changes in the configuration.
   Uses:  The class Life and its methods initialize(), print(), and update(); 
		  the functions instructions(), user_says_yes().
*/

{	
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while (user_says_yes()) {
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}
}

