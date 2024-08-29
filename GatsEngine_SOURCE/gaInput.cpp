#include "gaInput.h"

namespace ga
{
	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
														'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
														'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
														//'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
														VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
														MK_LBUTTON, MK_RBUTTON, MK_MBUTTON
	};

	void Input::Init()
	{
		CreateKeyArr();
	}

	void Input::Update()
	{
		UpdateKeyArr();
	}

	void Input::CreateKeyArr()
	{
		for (size_t i = 0; i < (size_t)eKeyCode::End; i++)
		{
			Key key;
			key.keyCode = (eKeyCode)i;
			key.state = eKeyState::NONE;
			key.bPressed = false;
			mKeys.push_back(key);
		}
	}

	void Input::UpdateKeyArr()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			if (IsKeyDown(ASCII[i]))
			{ 
				UpdateKeyDown(mKeys[i]);
			}
			else
			{
				UpdateKeyUp(mKeys[i]);
			}
		}
	}

	bool Input::IsKeyDown(int keyCode)
	{
		return GetAsyncKeyState(keyCode) & 0x8000;
	}
	 
	void Input::UpdateKeyUp(struct Key &target)
	{
		if (target.bPressed == true)
			target.state = eKeyState::UP;
		else
			target.state = eKeyState::NONE;

		target.bPressed = false;
	}

	void Input::UpdateKeyDown(struct Key &target)
	{
		if (target.bPressed == true)
			target.state = eKeyState::PRESSED;
		else
			target.state = eKeyState::DOWN;

		target.bPressed = true;
	}

}