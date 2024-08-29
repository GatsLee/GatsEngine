#pragma once

#include "CommonInclude.h"
#include "gaGameObject.h"

namespace ga
{
	class Application
	{
	public:
		Application();
		~Application();

		void Init(HWND hwnd, UINT width, UINT height);
		void Run(void);

		void Update(void);
		void LateUpdate(void);
		void Render(void);
	private:
		HWND mHwnd;
		HDC mHdc;

		HBITMAP mBuffer;
		HDC mBufferHdc;

		UINT mWidth;
		UINT mHeight;

		void adjustWindowSize(UINT width, UINT height);
		void createBuffer(UINT width, UINT height);

		void clearRenderTarget(void);
		void copyRenderTarget(HDC &src, HDC &dest);
	};
}

