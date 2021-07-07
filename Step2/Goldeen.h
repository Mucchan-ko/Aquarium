/**
 * \file Goldeen.h
 *
 * \author Nick Katarzynski
 *
 * Declaration of CGoldeen class
 *
 * Goldeen like to move, so they
 * bounce off the bottom of the
 * aquarium
 */

#pragma once
#include "Item.h"
#include "Fish.h"
#include <string>
#include <memory>


 /**
  * Class that describes a beta fish
  */
class CGoldeen : public CFish
{
public:
    /// Default constructor (disabled)
    CGoldeen() = delete;

    /// Copy constructor (disabled)
    CGoldeen(const CGoldeen&) = delete;

    CGoldeen(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;

private:

};
