/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/* QueueItem.h
 *
 * Copyright (C) 2008 SUSE Linux Products GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef ZYPP_SOLVER_DETAIL_QUEUEITEMINSTALLONEOF_H
#define ZYPP_SOLVER_DETAIL_QUEUEITEMINSTALLONEOF_H

#include <iosfwd>
#include <string>

#include <zypp/solver/detail/SolverQueueItem.h>

/////////////////////////////////////////////////////////////////////////
namespace zypp
{ ///////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////
  namespace solver
  { /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
    namespace detail
    { ///////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
//
//	CLASS NAME : SolverQueueItemInstallOneOf

class SolverQueueItemInstallOneOf : public SolverQueueItem {

  public:
    typedef std::list<PoolItem> PoolItemList;

  private:

    PoolItemList _oneOfList; // List of candidates
    bool _soft;          // if triggered by a soft requirement (a recommends)

  public:

    SolverQueueItemInstallOneOf (const ResPool & pool, const PoolItemList & itemList, bool soft = false);
    virtual ~SolverQueueItemInstallOneOf();

    // ---------------------------------- I/O

    virtual std::ostream & dumpOn( std::ostream & str ) const;

    friend std::ostream& operator<<(std::ostream & str, const SolverQueueItemInstallOneOf & obj)
    { return obj.dumpOn (str); }

    // ---------------------------------- accessors

    bool isSoft (void) const { return _soft; }

    // ---------------------------------- methods

    virtual bool addRule (sat::detail::CQueue & q);
    virtual SolverQueueItem_Ptr copy (void) const;
    virtual int cmp (SolverQueueItem_constPtr item) const;
};

///////////////////////////////////////////////////////////////////
    };// namespace detail
    /////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////
  };// namespace solver
  ///////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////
};// namespace zypp
/////////////////////////////////////////////////////////////////////////

#endif // ZYPP_SOLVER_DETAIL_QUEUEITEMINSTALLONEOF_H
