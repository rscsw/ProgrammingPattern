#pragma once

using namespace std;

namespace Musoeun
{
	MCommand* key[5];

	void Initialize()
	{
		//cout << "�ʱ�ȭ ��...\n";
		key[0] = new LeftCommand();
		key[1] = new RightCommand();
		key[2] = new DownCommand();
		key[3] = new JumpCommand();
		key[4] = new RunCommand();
	}

	void Input()
	{
		//cout << "�Է� ��...\n";
		int input;
		cin >> input;

		key[input]->Execute();
	}

	void Update()
	{
		//cout << "Update ��...\n";
	}

	void Render()
	{
		//cout << "Rendering ��...\n";
	}

	void Release()
	{
		//cout << "���� ��...\n";
		for (size_t i = 0; i < 5; i++)
		{
			delete(key[i]);
		}
	}

	class MGameLoop
	{
	public:
		bool isGameRunning = false;

		MGameLoop() {}
		~MGameLoop() {}

		void Run()
		{
			isGameRunning = true;
			Initialize();
			while (isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
	};
}