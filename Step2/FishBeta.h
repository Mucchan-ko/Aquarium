/**
 * \file FishBeta.h
 *
 * \author Nick Katarzynski
 *
 * Declaration of CFishBeta class
 *
 * Beta fish are aggressive so they
 * move faster
 */

#pragma once
#include "Item.h"
#include "Fish.h"
#include <string>
#include <memory>


/**
 * Class that describes a beta fish
 */
class CFishBeta : public CFish
{
public:
    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta&) = delete;

    CFishBeta(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;


private:

};
