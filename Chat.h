#pragma once

#include <vector>
#include <string>
#include "Participants.h"
#include "AutoLogin.h"

using namespace std;

class Chat
{
private:
	int _count; // ���������� ������������������ ��������� ����
	int iSender; // ����� ��������������� ��������� ���� �� ������� _participants
	vector<Participants> _participants;

	AutoLogin loginSource; // ���������� ������ ��� �������� ����� ������� � ����

public:
	//�����������
	Chat(int size);

	// ����������
	~Chat();

	// ��������� ������������ � ���������� �������
	bool compareLogin(string);

	// ��������� ������������ � ���������� ����
	bool compareName(string);

    // ���������� ������ ��������� ����
	void addParticipant(string, string, string);

	// ���� � �������
	bool SignIn(string, string);

	// ����� �� ��������
	void SignOut();

	// �������� ���������
	void sendMessage(string, string);

	// ������ ���������
	void readMessages();

	// ������������ ���������� ������
	void findFreeLogin(string);

	// ����������� ��� �� ������
	uint findHash(string);
};