/**
 * \file Goldeen.cpp
 *
 * \author Nick Katarzynski
 */

#include "pch.h"
#include "Goldeen.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;


/// Fish filename 
const wstring GoldeenImageName = L"images/goldeen.png";

/// Maximum random speed for increment
double MaxBounceSpeed = 15;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CGoldeen::CGoldeen(CAquarium* aquarium) :
    CFish(aquarium, GoldeenImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Xml node with fish type included
 */
std::shared_ptr<xmlnode::CXmlNode>
CGoldeen::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"goldeen");

    return itemNode;
}

/**
 * Makes goldeen bounce off the bottom of the aquarium
 * \param elapsed Time elapsed since the class call
 */
void CGoldeen::Update(double elapsed)
{
    double rand_speed = ((double)rand() / RAND_MAX) * MaxBounceSpeed;
    this->SetYSpeed(this->GetYSpeed() + rand_speed);
    this->CFish::Update(elapsed);
}
