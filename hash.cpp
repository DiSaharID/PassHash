#include <iostream>
#include <conio.h>
#include <string>

unsigned int strhashing(std::string pwd)
{
    std::hash<std::string> hash_obj;
    return hash_obj(pwd);
}
int main()
{
    std::string pwd;
    std::cout<<"Enter password:\n";
    int ch = 0;               // Переменная для символа.
    while (true)                // Создание бесконечного цикла.
    {
        ch = _getch();        // Помещаем код нажатой клавиши в переменную.
        if (ch == 13)         // Установка Enter на прерывание цикла.
        {
            break;         // Прерывание цикла.
        }
        if (ch == 27)   // Установка Esc на закрытие консоли.
        {
            exit (0);      // Выход из консоли.
        }
        if (ch == 8)     // Установка Backspace на удаление символов.
        {
            std::cout << (char)8 << ' ' <<char(8);
            if (!pwd.empty())
                pwd.erase(pwd.length()-1);
        }
        else
        {
            std::cout << '*';            // Замена символов на *
            pwd += (char)ch;       // Преврашение кода из целого числа в символ.
        }
    }
    unsigned int hash_pwd = strhashing(pwd);
    if (hash_pwd == 769277631)
        std::cout<<"\nCorrect password";
    else
        std::cout<<"\nIncorrect password";
}
