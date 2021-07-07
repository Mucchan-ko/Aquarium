/**
 * \file Item.cpp
 *
 * \author Nick Katarzynski
 */

#include "pch.h"
#include "Item.h"
#include "Aquarium.h"
#include "memory"

using namespace std;

 /** Constructor
 * \param aquarium The aquarium this item is a member of
 */
CItem::CItem(CAquarium* aquarium, const std::wstring& filename) :
    mAquarium(aquarium)
{
    mItemImage = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
    if (mItemImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += filename;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Destructor
 */
CItem::~CItem()
{
}

void CItem::SetLocation(double x, double y)
{
    mX = x;
    mY = y;
}

/**
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CItem::Draw(Gdiplus::Graphics* graphics)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    if (mMirror)
    {
        graphics->DrawImage(mItemImage.get(),
            float(GetX() + wid / 2), float(GetY() - hit / 2),
            -(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
    }
    else
    {
        graphics->DrawImage(mItemImage.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
    }
}

/**
 * Test to see if we hit this object with a mouse.
 * \param x X position to test
 * \param y Y position to test
 * \return true if hit.
 */
bool CItem::HitTest(int x, int y)
{
    double wid = mItemImage->GetWidth();
    double hit = mItemImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    auto format = mItemImage->GetPixelFormat();
    if (format == PixelFormat32bppARGB || format == PixelFormat32bppPARGB)
    {
        // This image has an alpha map, which implements the 
        // transparency. If so, we should check to see if we
        // clicked on a pixel where alpha is not zero, meaning
        // the pixel shows on the screen.
        Color color;
        mItemImage->GetPixel((int)testX, (int)testY, &color);
        return color.GetAlpha() != 0;
    }
    else {
        return true;
    }
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
void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    mX = node->GetAttributeDoubleValue(L"x", 0);
    mY = node->GetAttributeDoubleValue(L"y", 0);
}
