/**
 * \file ClownFish.h
 *
 * \author Nick Katarzynski
 *
 * Declaration of CClownFish class
 *
 * Clownfish are paranoid, so every so
 * often they feel the need to check behind
 * themselves
 */

#pragma once
#include "Item.h"
#include "Fish.h"
#include <string>
#include <memory>


 /**
  * Class that describes a beta fish
  */
class CClownFish : public CFish
{
public:
    /// Default constructor (disabled)
    CClownFish() = delete;

    /// Copy constructor (disabled)
    CClownFish(const CClownFish&) = delete;

    CClownFish(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;

private:

};

