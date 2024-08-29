#pragma once

#include "CommonInclude.h"

namespace ga
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring &name) { mName = name; }
		const std::wstring &GetName(void) const { return mName; }

	private:
		std::wstring mName;


	};
}
