#include "gaTime.h"

namespace ga
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurFrequency = {};
	float Time::DeltaTime = 0.0f;

	void Time::Init()
	{
		// Get the frequency of the CPU
		QueryPerformanceFrequency(&CpuFrequency);

		// Get the freq when the program starts
		QueryPerformanceCounter(&PrevFrequency);

	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurFrequency);

		float diffFreq = static_cast<float>(CurFrequency.QuadPart - PrevFrequency.QuadPart);
	
		DeltaTime = diffFreq / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTime;

		//wchar_t str[50] = L"";
		//swprintf_s(str, 50, L"Time: %d", (int)time);
		//int len = wcsnlen(str, 50);

		float fps = 1.0f / DeltaTime;

		wchar_t str2[50] = L"";
		swprintf_s(str2, 50, L"FPS: %d", (int)fps);
		int len = wcsnlen(str2, 50);

		TextOut(hdc, 0, 0, str2, len);

	}
}
