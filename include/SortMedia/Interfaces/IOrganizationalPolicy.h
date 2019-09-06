///////////////////////////////////////////////////////////////////////////////
// NAME:            IOrganizationalPolicy.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Interface for Organizational Policies.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_IORGANIZATIONALPOLICY__
#define __ET_IORGANIZATIONALPOLICY__

class SortMedia::Interfaces::IOrganizationalPolicy
{
public:
  virtual ~IOrganizationalPolicy() {};
  virtual std::unique_ptr<IFileOperation[]> ensure() = 0;
};

#endif // __ET_IORGANIZATIONALPOLICY__

///////////////////////////////////////////////////////////////////////////////
