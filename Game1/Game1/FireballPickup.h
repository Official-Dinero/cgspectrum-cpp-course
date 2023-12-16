#pragma once
#include "PlacableActor.h"

class FireballPickup : public PlacableActor
{
public:
	FireballPickup(int x, int y)
		: PlacableActor(x, y)
	{

	}
	virtual void Draw() override;
};
