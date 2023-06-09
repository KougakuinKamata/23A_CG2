#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>

class Window
{
public:
	~Window();
	void WindowCreate(const wchar_t* windowTitle);

	int32_t GetClientWidth() { return kClientWidth; }
	int32_t GetClientHeight() { return kClientHeight; }
	HWND GetHWND() { return hwnd; }
private:
	WNDCLASS wc{};
	RECT wrc{};
	HWND hwnd{};
	// クライアント領域のサイズ
	const int32_t kClientWidth = 1280;
	const int32_t kClientHeight = 720;
};

