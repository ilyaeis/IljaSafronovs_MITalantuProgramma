#include <iostream>
#include <vector>
#include <string>

int main()
{
    int choice = 0;
    int sum = 0;
    std::string str = "Programmas ir jaraksta cilvekiem, kas tas lasis!";

    while (choice != 6)
    {
        std::cout << "\n\n1: Ievadīt jaunu teksta virkni (parastie burti)\n"
            << "2: Izvada teksta virkni uz ekrāna\n"
            << "3. Izvada summu no 1 + ... + (n-1) + n (kur n = teksta virknes garums)\n"
            << "4. Izvada virkni no otrā gala(reversā)\n"
            << "5. Saskaita un attelo cik katrs simbols atkartojas teksta virkne\n"
            << "6. Beigt darbibu\n";

        std::cout << "\nChoose the available options, please: ";
        std::cin >> choice;

        std::cin.ignore(256, '\n'); // remaining input characters up to the next newline character are ignored (https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin)

        switch (choice) {
        case 1:
            std::cout << "\nWrite new string, please: ";
        std:getline(std::cin, str);
            break;
        case 2:
            std::cout << "\nCurrent string: " << str;
            break;
        case 3:
            sum = 0;
            for (int i = 1; i <= str.size(); i++) {
                sum += i;
            }
            std::cout << "\nSumma no 1 + ... + (n-1) + n (kur n = teksta virknes garums): " << sum;
            break;
        case 4:
            std::cout << "\nVirkni no otra gala(reversa): ";
            for (int i = str.size() - 1; i >= 0; i--) {
                std::cout << str[i];
            }
            break;
        case 5:
            for (int i = 0; i < str.size(); i++) {
                bool cont = true;
                for (int j = i - 1; j << str.size() >= 0; j--) {
                    if (str[i] == str[j]) { cont = false; }
                }
                if (!cont) continue;

                int counter = 0;
                for (int j = 0; j < str.size(); j++) {
                    if (str[i] == str[j]) counter++;
                }
                std::cout << str[i] << " - " << counter << "\n";

            }
            break;
        case 6:
            break;
        default:
            std::cout << "\nNo such option exists, please choose another valid one\n";
            break;
        }
    }
}