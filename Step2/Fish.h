/**
 * \file Fish.h
 *
 * \author Nick Katarzynski
 *
 * Class that describes a fish item
 */

#pragma once
#include "Item.h"
#include "Aquarium.h"


/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{
public:
    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

    void Update(double elapsed);

    /**
     * Save this item to an XML node
     * \param node The node we are going to be a child of
     */
    std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /**
     * Load the attributes for an item node.
     * \param node The Xml node we are loading the item from
     */
    void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** The X speed of the fish
    * \returns X speed*/
    double GetXSpeed() { return mSpeedX; }

    /** The Y speed of the fish
    * \returns Y speed*/
    double GetYSpeed() { return mSpeedY; }

    /** 
     * Set the X speed of the fish
     * \param speed Speed to update fish speed to
     */
    void SetXSpeed(double speed) { mSpeedX = speed; }

    /**
     * Set the Y speed of the fish
     * \param speed Speed to update fish speed to
     */
    void SetYSpeed(double speed) { mSpeedY = speed; }


protected:
    CFish(CAquarium* aquarium, const std::wstring& filename);


private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;
};
