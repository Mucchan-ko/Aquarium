/**
 * \file DecorCastle.h
 *
 * \author Nick Katarzynski
 *
 * Declaration of CDecorCastle class
 */

#pragma once
#include "Item.h"
#include <string>
#include <memory>


 /**
  * Class that describes a beta fish
  */
class CDecorCastle : public CItem
{
public:
    /// Default constructor (disabled)
    CDecorCastle() = delete;

    /// Copy constructor (disabled)
    CDecorCastle(const CDecorCastle&) = delete;

    CDecorCastle(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:

};
