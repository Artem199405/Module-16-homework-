#pragma once

#include <vector>
#include <string>
#include "Participants.h"
#include "AutoLogin.h"

using namespace std;

class Chat
{
private:
	int _count; // Количество зарегистрированных учатников чата
	int iSender; // Номер авторизованного участника чата из массива _participants
	vector<Participants> _participants;

	AutoLogin loginSource; // Префиксное дерево для создания новых логинов в чате

public:
	//Конструктор
	Chat(int size);

	// Деструктор
	~Chat();

	// Сравнение существующих и введенного логинов
	bool compareLogin(string);

	// Сравнение существующих и введенного имен
	bool compareName(string);

    // Добавление нового участника чата
	void addParticipant(string, string, string);

	// Вход в аккаунт
	bool SignIn(string, string);

	// Выход из аккаунта
	void SignOut();

	// Отправка сообщения
	void sendMessage(string, string);

	// Чтение сообщения
	void readMessages();

	// Автодопление введенного логина
	void findFreeLogin(string);

	// Определение хеш от пароля
	uint findHash(string);
};