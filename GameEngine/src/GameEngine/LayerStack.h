#pragma once

#include "Layer.h"


namespace GameEngine
{

	class GAMEENGINE_API LayerStack
	{

	public:

		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
		void popLayer(Layer* layer);
		void popOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return mLayers.begin(); }
		std::vector<Layer*>::iterator end() { return mLayers.end(); }

	private:
		std::vector<Layer*> mLayers;
		std::vector<Layer*>::iterator mLayerInsert;


	};

}