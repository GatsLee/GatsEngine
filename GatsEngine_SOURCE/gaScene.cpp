#include "gaScene.h"

namespace ga
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
		for (auto& gameObject : mGameObjects)
		{
			delete gameObject;
		}
	}

	void Scene::Init()
	{
	}

	void Scene::Update()
	{
		for (auto& gameObject : mGameObjects)
		{
			gameObject->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (auto& gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (auto& gameObject : mGameObjects)
		{
			gameObject->Render(hdc);
		}
	}
}
