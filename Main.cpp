#include <iostream>
#include "Chat.h"

using namespace std;

int main()
{
    cout << "Welcome to the chat!" << endl;

    const int iParticipants = 1;
    Chat chat(iParticipants);

    int action1;
    do
    {
        string login, password, name;
        bool key = true;

        cout << "Select an action (1 - register an account; 2 - log in to your account; 3 - exit the application): ";
        cin >> action1;

        if (action1 == 1) // Регистрация аккаунтов
        {
            do
            {
                int answer;
                cout << "Suggest free logins? (1 - yes; 2 - no): ";
                cin >> answer;
                if (answer == 1)
                {
                    string keyword;
                    cout << "Enter the keyword: ";
                    cin >> keyword;
                    chat.findFreeLogin(keyword);
                }
                cout << "Enter your login: ";
                cin >> login;
                key = chat.compareLogin(login);
                if (key == true)
                    cout << "A user with this login already exists. Come up with a new login." << endl;
            } while (key == true);

            cout << "Enter the password: ";
            cin >> password;

            do
            {
                cout << "Enter your username: ";
                cin >> name;
                key = chat.compareName(name);
                if (key == true)
                    cout << "A user with this username already exists. Come up with a new username." << endl;
            } while (key == true);

            chat.addParticipant(login, password, name);
        }
        else if (action1 == 2)
        {
            do // Вход в аккаунт
            {
                cout << "Enter your login: ";
                cin >> login;
                cout << "Enter the password: ";
                cin >> password;
                key = chat.SignIn(login, password);
                if (key == false)
                    cout << "You have entered an incorrect login or password. Try again." << endl;
            } while (key == false);

            cout << "You are logged in to your account." << endl;

            int action2;
            do
            {
                cout << "Select an action (1 - write a message; 2 - read the sent messages; 3 - log out of your account): ";
                cin >> action2;

                if (action2 == 1) // Ввод сообщения
                {
                    string text;
                    do
                    {
                        cout << "Enter the name of the user to send the message to, or 'all' - all chat participants: ";
                        cin >> name;
                        key = chat.compareName(name);
                        if (key == false)
                            cout << "A user with that name was not found. Try again." << endl;
                    } while (key == false);

                    cout << "Enter the text of the message: ";
                    cin >> text;

                    chat.sendMessage(name, text);
                }
                else if (action2 == 2) // Чтение присланных сообщений
                {
                    chat.readMessages();
                }
                else if (action2 == 3)
                {
                    chat.SignOut();
                }
                else
                {
                    cout << "Invalid operator, repeat the input" << endl;
                }
            } while (action2 != 3);
        }
        else if (action1 == 3)
        {}
        else
        {
            cout << "Invalid operator, repeat the input" << endl;
        }
    } while (action1 != 3);

    return 0;
}