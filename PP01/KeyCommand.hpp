#pragma once
#include "MCommand.hpp"

using namespace std;
using namespace Musoeun;

class JumpCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "�ѽ� ����!!\n";
	}
};

class RunCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "�ѽ� �޸���!!\n";
	}
};

class LeftCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "�ѽ� ����!!\n";
	}
};

class RightCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "�����̾� ������!!\n";
	}
};

class DownCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "������ ���� ���� ������!!\n";
	}
};