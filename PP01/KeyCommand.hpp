#pragma once
#include "MCommand.hpp"

using namespace std;
using namespace Musoeun;

class JumpCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "¾Ñ½Î Á¡ÇÁ!!\n";
	}
};

class RunCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "¾Ñ½Î ´Þ¸®±â!!\n";
	}
};

class LeftCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "¾Ñ½Î ¿ÞÂÊ!!\n";
	}
};

class RightCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "¸¾¸¶¹Ì¾ß ¿À¸¥ÂÊ!!\n";
	}
};

class DownCommand : public MCommand
{
public:
	void Execute()
	{
		cout << "ÀÚÁ¸½É µûÀ© ¾ø´Ù ¾¥±¸¸®!!\n";
	}
};