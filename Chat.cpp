#include <iostream>
#include "Chat.h"

Chat::Chat(int size) : _count(0)
{
    vector<Participants> _participants(size - 1);

    loginSource.insert("Log1"); loginSource.insert("Log2"); loginSource.insert("Log3");
    loginSource.insert("Login1"); loginSource.insert("Login2"); loginSource.insert("Login3");
    loginSource.insert("log1"); loginSource.insert("log2"); loginSource.insert("log3");
    loginSource.insert("login1"); loginSource.insert("login2"); loginSource.insert("login3");
}

Chat::~Chat()
{
}

bool Chat::compareLogin(string login)
{
    for (int i = 0; i < _count; i++)
    {
        if (login == _participants[i].getLogin())
            return true;
    }

    return false;
}

bool Chat::compareName(string name)
{
    if (name == "all")
        return true;
    
    for (int i = 0; i < _count; i++)
    {
        if (name == _participants[i].getName())
            return true;
    }

    return false;
}

void Chat::addParticipant(string login, string password, string name)
{
    Participants participant;
    
    participant.setLogin(login);
    participant.setPassword(password);
    participant.setName(name);
    participant.setPasswordHash(password);

    vector<Participants>::iterator it = _participants.begin() + _count;
    vector<Participants>::iterator newIt = _participants.insert(it, participant);

    _count++;
}

bool Chat::SignIn(string login, string password)
{
    uint hash = findHash(password);
    
    for (int i = 0; i < _count; i++)
    {
        if (login == _participants[i].getLogin())
        {
            // Первый вариант
            /*if (password == _participants[i].getPassword())
            {
                iSender = i;
                return true;
            }
            else
            {
                return false;
            }*/

            // Второй вариант
            if (hash == _participants[i].getPasswordHash())
            {
                iSender = i;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

void Chat::SignOut()
{
    iSender = -1;
}

void Chat::sendMessage(string name, string text)
{
    if (name == "all")
    {
        for (int i = 0; i < _count; i++)
        {
            if (i != iSender)
            {
                _participants[i].recordMessage(_participants[iSender].getName(), text);
            }
        }
    }
    else
    {
        for (int i = 0; i < _count; i++)
        {
            if (name == _participants[i].getName())
            {
                _participants[i].recordMessage(_participants[iSender].getName(), text);
                break;
            }
        }
    }
}

void Chat::readMessages()
{
    _participants[iSender].showMessages();
}

void Chat::findFreeLogin(string keyword)
{
    string res;
    
    loginSource.findPrefixWords(keyword, &res);

    if (res.at(0) == ' ')
    {
        cout << "No words with matching keyword found " << endl;
    }
    else
    {
        string newLogin;

        cout << "Words with keyword: " << endl;
        
        for (size_t i = 0; i < res.length(); i++)
        {
            
            if (res.at(i) == ' ')
            {
                bool key = compareLogin(newLogin);
                if (!key)
                    cout << newLogin + ' ';

                newLogin.clear();
            }
            else
                newLogin += res.at(i);
        }
    }

    cout << endl;
}

uint Chat::findHash(string password)
{
    const char* charPassword = password.c_str();
    int length = strlen(charPassword);

    uint* hash = sha1(charPassword, (uint)length);

    return *hash;
}