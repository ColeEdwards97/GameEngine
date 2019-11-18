#pragma once

#include "GameEngine/Layer.h"

namespace GameEngine
{

	class GAMEENGINE_API ImGuiLayer : public Layer
	{

	public:
		
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& e);

	private:

		float mTime = 0.0f;

	};

}