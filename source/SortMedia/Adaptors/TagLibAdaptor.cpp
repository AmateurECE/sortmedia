///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibAdaptor.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the methods of the TagLibAdaptor class.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#include <SortMedia/Adaptors/TagLibAdaptor.h>

// Getters
const std::string& SortMedia::Adaptors::TagLibAdaptor::getArtist() const
{
  return {};
}

const std::string& SortMedia::Adaptors::TagLibAdaptor::getAlbum() const
{
  return {};
}

const std::string& SortMedia::Adaptors::TagLibAdaptor::getTitle() const
{
  return {};
}

const std::string& SortMedia::Adaptors::TagLibAdaptor::getComment() const
{
  return {};
}

const std::string& SortMedia::Adaptors::TagLibAdaptor::getGenre() const
{
  return {};
}

unsigned int SortMedia::Adaptors::TagLibAdaptor::getYear() const
{
  return 0UL;
}

unsigned int SortMedia::Adaptors::TagLibAdaptor::getTrack() const
{
  return 0UL;
}


// Setters
void SortMedia::Adaptors::TagLibAdaptor::setArtist(const std::string&) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setAlbum(const std::string&) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setTitle(const std::string&) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setComment(const std::string&) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setGenre(const std::string&) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setYear(unsigned int) const
{}

void SortMedia::Adaptors::TagLibAdaptor::setTrack(unsigned int) const
{}


///////////////////////////////////////////////////////////////////////////////
