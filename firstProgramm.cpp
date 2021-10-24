#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isNumber(int c){
    if (c != ' ' && c != '+' && c != '-' && c != EOF && c!= '\r' && c!= '\n')
        return true;
    else
        return false;
}

int main(){

    FILE* fin = fopen("fin.txt", "r");
    int c = 0;
    char operation = '+';
    string value;
    int result = 0;
    int current = 0;
    bool inNum = false;
    bool hasOperation = true;
    while((c = fgetc(fin)) != EOF){
        if (isNumber(c) == true){
            do{
                value.push_back(c);
                c = fgetc(fin);
            }while (isNumber(c) == true);
            inNum = true;
        }
        if  (inNum == true) {
            for (int i = value.size() - 1; i >= 0; i--) {
                current = current + (value[value.size() - 1 - i] - '0') * pow(10, i);
            }
            value = "";
            inNum = false;
        }
        if (hasOperation == true && current != 0){
            if (operation == '+'){
                result = result + current;
            }
            else if (operation == '-'){
                result = result - current;
            }
            current = 0;
            hasOperation = false;
        }

        if ((c == '+') || c == '-') {
            operation = c;
            hasOperation = true;
        }
    }
    cout << result;
	cout << "I Love Git!!!!";
	// some changes
	
    return 0;
}
