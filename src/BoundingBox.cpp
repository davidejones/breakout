#include "BoundingBox.h"

BoundingBox::BoundingBox(void)
{
}

BoundingBox::BoundingBox(int left = 0, int right = 0, int top = 0, int bottom = 0)
{
	minX = left;
	maxX = right;
	minY = top;
	maxY = bottom;
}

bool BoundingBox::checkIntersect(BoundingBox b) {
	//return (std::abs(minX - b.minX) * 2 <= (maxX + b.maxX)) && (std::abs(minY - b.minY) * 2 <= (maxY + b.maxY));
	if (maxX < b.minX) return false; // a is left of b
	if (minX > b.maxX) return false; // a is right of b
	if (maxY < b.minY) return false; // a is above b
	if (minY > b.maxY) return false; // a is below b
	return true; // boxes overlap
}