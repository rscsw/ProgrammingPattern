#pragma once
#include <chrono>
#include <thread>
#include "MConsoleUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		double pp = 0;
		int c = 0;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

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
			startRenderTimePoint = chrono::system_clock::now();
			/*	if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{

				}
				else
				{

				}*/

		}
		void Update()
		{

		}
		void Render()
		{
			cRenderer.Clear();
			cRenderer.MoveCursor(10, 20);

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;

			pp += renderDuration.count();
			if (pp > 1.0)
			{
				c = 0;
				pp = 0;
			}
			c++;

			string s = "FPS : " + to_string(c);
			cRenderer.DrawString(s);

			//chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			//string fps = "FPS(milliseconds) : " + to_string(renderDuration.count());
			//cRenderer.DrawString(fps);


		}
		////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;
		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
	};
}