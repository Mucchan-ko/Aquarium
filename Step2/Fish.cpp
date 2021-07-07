#include "pch.h"
#include "Fish.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
    CItem(aquarium, filename)
{
    mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
    mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedX;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	// Get constants used for bound checks
	int FishWidth = this->GetItemWidth() / 2;
	int FishHeight = this->GetItemHeight() / 2;
	int AquariumWidth = GetAquarium()->GetWidth();
	int AquariumHeight = GetAquarium()->GetHeight();

	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	// If the fish is outside of x bounds
	if (mSpeedX > 0 && GetX() >= AquariumWidth - 10 - FishWidth
		|| GetX() <= 10 + FishWidth)
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	// If the fish is outside of y bounds
	if (mSpeedY > 0 && GetY() >= AquariumHeight - 40 - FishHeight
		|| GetY() <= 10 + FishHeight)
	{
		mSpeedY = -mSpeedY;
		SetMirror(mSpeedX < 0);
	}
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns xml node with Fish type
 */
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = node->AddChild(L"item");

	double fishX = this->GetX();
	double fishY = this->GetY();

	// save attributes
	itemNode->SetAttribute(L"x", fishX);
	itemNode->SetAttribute(L"y", fishY);
	itemNode->SetAttribute(L"speedx", mSpeedX);
	itemNode->SetAttribute(L"speedy", mSpeedY);

	return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * \param node The Xml node we are loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// get x and y positions
	double fishX = node->GetAttributeDoubleValue(L"x", 0);
	double fishY = node->GetAttributeDoubleValue(L"y", 0);

	this->SetLocation(fishX, fishY);

	// get x and y speeds
	double speedX = node->GetAttributeDoubleValue(L"speedx", 0);
	double speedY = node->GetAttributeDoubleValue(L"speedy", 0);

	// set speeds
	mSpeedX = speedX;
	mSpeedY = speedY;

	if (mSpeedX < 0)
		SetMirror(mSpeedX < 0);
}
