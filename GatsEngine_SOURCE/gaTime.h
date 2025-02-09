#pragma once

#include "CommonInclude.h"

namespace ga
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hdc);
	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurFrequency;
		static float DeltaTime;
	};
}

