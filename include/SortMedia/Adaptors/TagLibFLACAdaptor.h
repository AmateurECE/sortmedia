///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibFLACAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     This adaptor is specialized to deal with FLAC files using
//                  the TagLib adaptor.
//
// CREATED:         03/30/2020
//
// LAST EDITED:     03/31/2020
////

#ifndef __ET_TAGLIBFLACADAPTOR__
#define __ET_TAGLIBFLACADAPTOR__

#include <namespaces/Adaptors.h>
#include <SortMedia/Adaptors/TagLibAdaptor.h>

class SortMedia::Adaptors::TagLibFLACAdaptor
  : public SortMedia::Adaptors::TagLibAdaptor
{
public:
  TagLibFLACAdaptor(const FSAdaptor::Path& path);

private:
  virtual std::string getDiscTotal() const final override;
  virtual std::string getTrackTotal() const final override;
  virtual void setDiscTotal(const std::string&) final override;
  virtual void setTrackTotal(const std::string&) final override;
};

#endif // __ET_TAGLIBFLACADAPTOR__

///////////////////////////////////////////////////////////////////////////////
