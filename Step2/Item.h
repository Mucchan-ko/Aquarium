/**
 * \file Item.h
 *
 * \author Nick Katarzynski
 *
 * Class that describes an aquarium item
 */

#pragma once
#include "XmlNode.h"
#include <string>
#include <memory>

using namespace Gdiplus;

class CAquarium;

/**
 * Item to be used in an aquarium
 */
class CItem
{
public:
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    virtual ~CItem();

    /** The X location of the item
    * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    virtual void SetLocation(double x, double y);

    /// Draw this item
    /// \param graphics Graphics device to draw on
    void Draw(Gdiplus::Graphics* graphics);

    /** Test this item to see if it has been clicked on
     * \param x X location on the aquarium to test
     * \param y Y location on the aquarium to test
     * \return true if clicked on */
    bool HitTest(int x, int y);

    /**
     * Save this item to an XML node
     * \param node The node we are going to be a child of
     * \return Xml node with position of type item
     */
    virtual std::shared_ptr<xmlnode::CXmlNode>
        CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
    {
        auto itemNode = node->AddChild(L"item");

        itemNode->SetAttribute(L"x", mX);
        itemNode->SetAttribute(L"y", mY);

        return itemNode;
    }

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    /// Get the aquarium this item is in
    /// \returns Aquarium pointer
    CAquarium* GetAquarium() { return mAquarium; }

    /// Set the mirror status
    /// \param m New mirror flag
    void SetMirror(bool m) { mMirror = m; }

    /// Get the width of an item
    /// \returns Item width
    int GetItemWidth() const { return mItemImage->GetWidth(); }

    /// Get the height of an item
    /// \returns Item height
    int GetItemHeight() const { return mItemImage->GetHeight(); }


protected:
    /**
    * Copy constructor from a .aqua save file
    * \param aquarium Aquaarium to copy
    * \param filename File from which to create aquarium
    */
    CItem(CAquarium* aquarium, const std::wstring& filename);

private:
    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

    bool mMirror = false;   ///< True mirrors the item image

};

