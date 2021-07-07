/**
 * \file ClownFish.cpp
 *
 * \author Nick Katarzynski
 */

#include "pch.h"
#include "ClownFish.h"
#include "XmlNode.h"

using namespace std;
using namespace Gdiplus;


/// Fish filename 
const wstring ClownFishImageName = L"images/clown-fish.png";

/// Range for clownfish paranoid chance
double MaxParanoid = 7000;

/// If clownfish is paranoid
double paranoid;

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CClownFish::CClownFish(CAquarium* aquarium) :
    CFish(aquarium, ClownFishImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \returns Xml node with type of fish included
 */
std::shared_ptr<xmlnode::CXmlNode>
CClownFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"clown");

    return itemNode;
}

/**
 * Makes clownfish check behind itself if paranoid
 * \param elapsed Time elapsed since the class call
 */
void CClownFish::Update(double elapsed)
{
    paranoid = ((double)rand() / RAND_MAX) * MaxParanoid;

    if (paranoid > 6850)
        this->SetMirror(true);
    else
        this->SetMirror(false);

    this->CFish::Update(elapsed);
}