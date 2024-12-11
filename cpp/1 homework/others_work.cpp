#include <iostream>
#include <string>
#include <map>
using namespace std;

int Choice() {
    string line;
    cout << "1: Ievadīt jaunu teksta virkni (parastie burti)\n2: Izvada teksta virkni uz ekrāna\n3. Izvada summu no 1..n (kur n = teksta virknes garums)\n4. Izvada virkni no otrā gala (reversā)\n5. Saskaita un attēlo cik katrs simbols atkārtojas teksta virknē\n6. Beigt darbību\n";
    getline(cin, line);
    return stoi(line);
}

string TextInput(string textLine) {
    getline(cin, textLine);
    return textLine;
}

void TextOutput(string textLine) {
    cout << textLine << "\n";
}

void TextSum(string textLine) {
    int sum=0, textLength = textLine.length();
    for(int i=1; i<=textLength; i++) {
        sum += i;
    }
    cout << "No 1 līdz " << textLength << " skaitļu summa ir " << sum << endl;
}

void TextReverse(string textLine) {
    int textLength = textLine.size();
    for(int i=textLength-1; i>=0; i--) {
        cout << textLine[i];
    }
    cout << endl;
}

void TextSymbolCount(string textLine) {
    map<char, int> charCounter;
    for(char c : textLine) {
        charCounter[c] += 1;
    }
    for(auto character : charCounter) {
        cout << character.first  << " - " << character.second << "\n";
    }
}

int main() {
    string textLine = "Programmas ir jaraksta cilvekiem, kas tas lasis!";
    bool end = false;
    int madeChoice;

    while(!end) {
        madeChoice = Choice();

        switch (madeChoice) {
            case 1:
                textLine = TextInput(textLine);
                break;
            case 2:
                TextOutput(textLine);
                break;
            case 3:
                TextSum(textLine);
                break;
            case 4:
    	        TextReverse(textLine);
                break;
            case 5:
                TextSymbolCount(textLine);
                break;
            case 6:
                end = true;
                break;
            default:
                cout << "Tika ievadīts kļudaina atbilde";
        }
    }

    return 0;
}