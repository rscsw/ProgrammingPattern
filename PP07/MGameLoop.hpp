#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Monster.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		bool _isPlayerAlive = true;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Monster m;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{

				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Initialize()
		{

		}
		void Release()
		{
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
 				p.isKeyPressed();
			}
			else
			{
				p.isKeyUnpressed();
			}
		}
		void Update()
		{
			
		}
		void Render()
		{
			if (_isPlayerAlive)
			{
				cRenderer.MoveCursor(p.x, p.y);
				cRenderer.DrawString("P");
				cRenderer.MoveCursor(m.x, m.y);
				cRenderer.DrawString("M");
				m.Moving();
				if (p.x == m.x && p.y == m.y) _isPlayerAlive = false;


				cRenderer.MoveCursor(10, 20);
				renderDuration = chrono::system_clock::now() - startRenderTimePoint;
				startRenderTimePoint = chrono::system_clock::now();
				string fps = "FPS : " + to_string(1.0 / renderDuration.count());
				cRenderer.DrawString(fps);

				this_thread::sleep_for(chrono::milliseconds(20));
				cRenderer.Clear();
			}
			else
			{
				cRenderer.MoveCursor(20, 7);
				cRenderer.DrawString("뒤졌습니다.");
			}
		}


		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}