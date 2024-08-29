#include "gaApplication.h"
#include "gaInput.h"
#include "gaTime.h"
#include "gaSceneManager.h"

namespace ga
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBuffer(nullptr)
		, mBufferHdc(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Init(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		adjustWindowSize(width, height);
		createBuffer(width, height);

		Input::Init();
		Time::Init();

		SceneManager::Init();
	}

	void Application::Run(void)
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update(void)
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
	}

	void Application::LateUpdate(void)
	{
	}

	void Application::Render(void)
	{
		clearRenderTarget();

		Time::Render(mBufferHdc);
		SceneManager::Render(mBufferHdc);

		copyRenderTarget(mBufferHdc, mHdc);

	}

	void Application::adjustWindowSize(UINT width, UINT height)
	{
		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, \
					mWidth, mHeight, SWP_NOMOVE | SWP_NOZORDER);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		mBuffer = CreateCompatibleBitmap(mHdc, width, height);

		mBufferHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBufferHdc, mBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::clearRenderTarget(void)
	{
		Rectangle(mBufferHdc, -1, -1, mWidth + 1, mHeight + 1);
	}

	void Application::copyRenderTarget(HDC &src, HDC &dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, src, 0, 0, SRCCOPY);
	}
}