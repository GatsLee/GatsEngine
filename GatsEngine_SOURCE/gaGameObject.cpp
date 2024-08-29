#include "gaGameObject.h"

namespace ga
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{

		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= 0.1f;
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += 0.1f;
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.1f;
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += 0.1f;
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		Rectangle(hdc, mX, mY, mX + static_cast<float>(100), mY + static_cast<float>(100));
	}
}