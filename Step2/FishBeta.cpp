/**
 * \file FishBeta.cpp
 *
 * \author Nick Katarzynski
 */

#include "pch.h"
#include "FishBeta.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;

 /// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/// Max beta speed
double AggressiveSpeed = 125;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
    CFish(aquarium, FishBetaImageName)
{
    double speedX = ((double)rand() / RAND_MAX) * AggressiveSpeed;
    double speedY = ((double)rand() / RAND_MAX) * AggressiveSpeed;
    this->SetXSpeed(speedX);
    this->SetYSpeed(speedY);
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Xml node with type of fish included
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"beta");

    return itemNode;
}
