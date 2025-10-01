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
    setlocale(LC_ALL, "Russian");
    std::string pwd;
    std::cout<<"Введите пароль:\n";
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
    if (hash_pwd == 2405068788601216399)
        std::cout<<"\nПравильный пароль "<<hash_pwd;
    else
        std::cout<<"\nНеправильный пароль "<<hash_pwd;
}
