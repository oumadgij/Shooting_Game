#pragma once

class ItemBase
{
public:
	virtual ~ItemBase() {};

	virtual void Update() = 0;
	virtual void Draw()const = 0;
	int GetType()const { return type; }

private:
	int speed;
	int type;
};