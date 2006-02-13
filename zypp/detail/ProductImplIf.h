/*---------------------------------------------------------------------\
|                          ____ _   __ __ ___                          |
|                         |__  / \ / / . \ . \                         |
|                           / / \ V /|  _/  _/                         |
|                          / /__ | | | | | |                           |
|                         /_____||_| |_| |_|                           |
|                                                                      |
\---------------------------------------------------------------------*/
/** \file zypp/detail/ProductImplIf.h
 *
*/
#ifndef ZYPP_DETAIL_PRODUCTIMPLIF_H
#define ZYPP_DETAIL_PRODUCTIMPLIF_H

#include "zypp/detail/ResObjectImplIf.h"

#ifndef PURE_VIRTUAL
#define PURE_VIRTUAL = 0
#endif

///////////////////////////////////////////////////////////////////
namespace zypp
{ /////////////////////////////////////////////////////////////////

  class Product;

  ///////////////////////////////////////////////////////////////////
  namespace detail
  { /////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////
    //
    //	CLASS NAME : ProductImplIf
    //
    /** Abstact Product implementation interface.
    */
    class ProductImplIf : public ResObjectImplIf
    {
    public:
      typedef Product ResType;

    public:
      /** Get the category of the product - addon or base*/
      virtual std::string category() const PURE_VIRTUAL;

      /** Get the vendor of the product */
      virtual Label vendor() const PURE_VIRTUAL;

      /** Get the name of the product to be presented to user */
      virtual TranslatedText displayName() const PURE_VIRTUAL;
    };
    ///////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////
  } // namespace detail
  ///////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////
} // namespace zypp
///////////////////////////////////////////////////////////////////
#endif // ZYPP_DETAIL_PRODUCTIMPLIF_H
