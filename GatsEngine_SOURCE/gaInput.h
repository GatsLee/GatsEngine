#pragma once
#include "CommonInclude.h"

namespace ga
{
	enum class eKeyState
	{
		NONE,
		PRESSED,
		DOWN,
		UP
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		Left, Right, Up, Down,
		MouseLeft, MouseRight, MouseMiddle,
		End,
	};

	class Input
	{
	public:

		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Init();
		static void Update();

		static bool GetKeyDown(eKeyCode key) { return mKeys[(size_t)key].state == eKeyState::DOWN; }
		static bool GetKeyUp(eKeyCode key) { return mKeys[(size_t)key].state == eKeyState::UP; }
		static bool GetKey(eKeyCode key) { return mKeys[(size_t)key].state == eKeyState::DOWN || mKeys[(size_t)key].state == eKeyState::PRESSED; }
	
	private:
		static std::vector<Key> mKeys;

		static void CreateKeyArr();
		static void UpdateKeyArr();

		static bool IsKeyDown(int keyCode);

		static void UpdateKeyDown(struct Key &target);
		static void UpdateKeyUp(struct Key &target);
	};
}

