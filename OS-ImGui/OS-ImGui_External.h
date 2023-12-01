#pragma once
#include "OS-ImGui_Base.h"

namespace OSImGui
{
	class OSImGui_External : public OSImGui_Base
	{
	private:
		// Window type
		WindowType Type = NEW;
	public:
		// Create a new window
		void NewWindow(std::string WindowName, Vec2 WindowSize, std::function<void()> CallBack);
		// Attatch to another window
		void AttachAnotherWindow(std::string DestWindowName, std::string DestWindowClassName, std::function<void()> CallBack);
	private:
		void MainLoop();
		bool UpdateWindowData();
		bool CreateMyWindow();
		bool PeekEndMessage();
	};
}