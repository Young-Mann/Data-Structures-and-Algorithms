#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s;
	cin >> s;
	 
    int record = -1, hunter = 0, sum = 0;
        
    for (hunter = 0; hunter < s.size(); hunter ++ ) {
        if (s[hunter] == ' ') {
            record = hunter;
        }

        sum = hunter - record;
    }

    cout << sum << endl;
}