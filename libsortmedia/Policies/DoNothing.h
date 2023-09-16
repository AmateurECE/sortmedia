///////////////////////////////////////////////////////////////////////////////
// NAME:            DoNothing.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     A DoNothing Policy that does...nothing.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/09/2019
////

#ifndef __ET_DONOTHINGPOLICY__
#define __ET_DONOTHINGPOLICY__

#include <libsortmedia/namespaces/Interfaces.h>
#include <libsortmedia/namespaces/Policies.h>
#include <libsortmedia/Policies/OrganizationalBase.h>
#include <libsortmedia/Interfaces/IFileOperation.h>

#include <list>
#include <memory>

class SortMedia::Policies::DoNothing
  : public OrganizationalBase
{
public:
  DoNothing() {}
};

#endif // __ET_DONOTHINGPOLICY__

///////////////////////////////////////////////////////////////////////////////
