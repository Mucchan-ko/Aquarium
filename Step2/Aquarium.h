/**
 * \file Aquarium.h
 *
 * \author Nick Katarzynski
 *
 *  Class that describes an aquarium and hold aquarium members
 */

#pragma once
#include "Item.h"
#include <vector>
#include <memory>

/**
 * Aquarium class
 */
class CAquarium
{
public: 
    CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);

    void Add(std::shared_ptr<CItem> item);

    void MoveBack(std::shared_ptr<CItem> item);

    std::shared_ptr<CItem> HitTest(int x, int y);

    void Save(const std::wstring& filename);

    void Load(const std::wstring& filename);

    void Clear();

    bool IsEmpty();

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

    void Update(double elapsed);

    /// Get the width of the aquarium
    /// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }


private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;
};

