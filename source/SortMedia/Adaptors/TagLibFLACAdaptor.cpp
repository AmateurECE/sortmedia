///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibFLACAdaptor.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Adaptor class for FLAC files using the TagLib library.
//
// CREATED:         03/30/2020
//
// LAST EDITED:     03/31/2020
////

#include <SortMedia/Adaptors/TagLibFLACAdaptor.h>

SortMedia::Adaptors::TagLibFLACAdaptor
::TagLibFLACAdaptor(const FSAdaptor::Path& path)
  : TagLibAdaptor{path}
{}

std::string
SortMedia::Adaptors::TagLibFLACAdaptor
::getDiscTotal() const
{
  return getTagFromPropertyMap("TOTALDISCS");
}

std::string
SortMedia::Adaptors::TagLibFLACAdaptor
::getTrackTotal() const
{
  return getTagFromPropertyMap("TOTALTRACKS");
}

void
SortMedia::Adaptors::TagLibFLACAdaptor
::setDiscTotal(const std::string& total)
{
  setTagInPropertyMap("TOTALDISCS", total);
}

void
SortMedia::Adaptors::TagLibFLACAdaptor
::setTrackTotal(const std::string& total)
{
  setTagInPropertyMap("TOTALTRACKS", total);
}

///////////////////////////////////////////////////////////////////////////////
