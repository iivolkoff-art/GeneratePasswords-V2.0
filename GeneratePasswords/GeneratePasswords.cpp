#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;


class PassGen {
private:
    int numOfSmallChars;
    int numOfBigChars;
    int numOfNumbers;
    int numOfSmallCharsRus;
    int numOfBigCharsRus;
    char* password;
    int option;

public:
    void displayMessage()
    {
        int passLenght;
        int numOfPasswords;
        string FileName = "Password.txt";

        cout << "Введеные даные должны быть 0 < X < 11" << endl;
        cout << "Введите длину пароля для генерации: ";
        cin >> passLenght;
        
        if (passLenght < 1 || passLenght > 10)
        {
            system("cls");
            cout << "Ошибка ввода данных, попробуйте еще раз" << endl;
            cout << endl;
            displayMessage();
        }

        cout << "Введите количество паролей для генерации: ";
        cin >> numOfPasswords;
        if (numOfPasswords < 1 || numOfPasswords > 10)
        {
            system("cls");
            cout << "Ошибка ввода данных, попробуйте еще раз" << endl;
            cout << endl;
            displayMessage();
        }

        cout << "Будет сгенерировано паролей: " << numOfPasswords << "." << endl;
        cout << endl;

        cout << "1) цифры\n"
            "2) строчные латинские буквы\n"
            "3) латинские строчные и заглавные буквы\n"
            "4) кириллица строчные\n"
            "5) кириллица строчные, заглавные\n"
            "6) цифры , латиница строчные\n";
        cin >> option;
        
        ofstream outFile(FileName);

        auto start = high_resolution_clock::now();
        switch (option) 
        {
        case 1:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorNumb(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        case 2:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorSmallChars(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        case 3:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorBigSmallChars(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        case 4:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorSmallCharsRus(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        case 5:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorBigSmallCharsRus(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        case 6:
            for (int k = 0; k < numOfPasswords; k++)
            {
                for (int i = 0; i < passLenght; ++i)
                {
                    passGeneratorNumbAndSmallCharsRus(passLenght);

                    outFile << password[i];
                }
                outFile << endl;
            }
            break;
        }

        auto end = high_resolution_clock::now();
        duration<float> duraction = end - start;

        outFile.close();

        cout << "Пароли успешно сгенерированы и записаны в файл " << FileName << "" << endl;
        cout << "Время генерации: " << duraction.count() << " секунд" << endl;
    }

    void passGeneratorNumb(int passLenght)
    {
        password = new char[passLenght];
        
        numOfNumbers = rand() % passLenght;
        for (int i = 0; i < passLenght; ++i)
        {
            password[i] = char(rand() % 10 + 48);
        }
    }

    void passGeneratorSmallChars(int passLenght)
    {
        password = new char[passLenght];

        numOfBigChars = rand() % passLenght;
        for (int i = 0; i < passLenght; ++i)
        {
            password[i] = char(rand() % 26 + 97);
        }
    }

    void passGeneratorBigSmallChars(int passLenght)
    {
        password = new char[passLenght];

        numOfBigChars = rand() % passLenght;
        numOfSmallChars = rand() % passLenght - numOfBigChars;
        for (int i = 0; i < numOfBigChars; ++i)
        {
            password[i] = char(rand() % 26 + 65);
        }
        for (int i = numOfBigChars; i < passLenght; ++i)
        {
            password[i] = char(rand() % 26 + 97);
        }
    }

    void passGeneratorSmallCharsRus(int passLenght)
    {
        password = new char[passLenght];

        numOfSmallCharsRus = rand() % passLenght;
        for (int i = 0; i < passLenght; ++i)
        {
            password[i] = char(rand() % 31 + 223);
        }
    }

    void passGeneratorBigSmallCharsRus(int passLenght)
    {
        password = new char[passLenght];

        numOfBigCharsRus = rand() % passLenght;
        numOfSmallCharsRus = rand() % passLenght - numOfBigCharsRus;
        for (int i = 0; i < numOfBigCharsRus; ++i)
        {
            password[i] = char(rand() % 31 + 192);
        }
        for (int i = numOfBigCharsRus; i < passLenght; ++i)
        {
            password[i] = char(rand() % 31 + 223);
        }
    }

    void passGeneratorNumbAndSmallCharsRus(int passLenght)
    {
        password = new char[passLenght];

        numOfNumbers = rand() % passLenght;
        numOfBigCharsRus = rand() % passLenght - numOfNumbers;
        for (int i = 0; i < numOfNumbers; ++i)
        {
            password[i] = char(rand() % 10 + 48);
        }
        for (int i = numOfNumbers; i < passLenght; ++i)
        {
            password[i] = char(rand() % 31 + 223);
        }
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    PassGen pass;
    pass.displayMessage();
}