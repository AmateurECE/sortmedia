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

#include <FSAdaptor/Path.h>

#include <taglib/fileref.h>

SortMedia::Adaptors::TagLibAdaptor::TagLibAdaptor(const FSAdaptor::Path& path)
  : m_fileRef(std::make_unique<TagLib::FileRef>(path.string().c_str()))
{}

// Getters
std::string SortMedia::Adaptors::TagLibAdaptor::getArtist() const
{
  return m_fileRef->tag()->artist().to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getAlbum() const
{
  return m_fileRef->tag()->album().to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getTitle() const
{
  return m_fileRef->tag()->title().to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getComment() const
{
  return m_fileRef->tag()->comment().to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getGenre() const
{
  return m_fileRef->tag()->genre().to8Bit(true);
}

unsigned int SortMedia::Adaptors::TagLibAdaptor::getYear() const
{
  return m_fileRef->tag()->year();
}

unsigned int SortMedia::Adaptors::TagLibAdaptor::getTrack() const
{
  return m_fileRef->tag()->track();
}


// Setters
void SortMedia::Adaptors::TagLibAdaptor::setArtist(const std::string& artist)
{
  m_fileRef->tag()->setArtist(artist);
}

void SortMedia::Adaptors::TagLibAdaptor::setAlbum(const std::string& album)
{
  m_fileRef->tag()->setAlbum(album);
}

void SortMedia::Adaptors::TagLibAdaptor::setTitle(const std::string& title)
{
  m_fileRef->tag()->setTitle(title);
}

void SortMedia::Adaptors::TagLibAdaptor::setComment(const std::string& comment)
{
  m_fileRef->tag()->setComment(comment);
}

void SortMedia::Adaptors::TagLibAdaptor::setGenre(const std::string& genre)
{
  m_fileRef->tag()->setGenre(genre);
}

void SortMedia::Adaptors::TagLibAdaptor::setYear(unsigned int year)
{
  m_fileRef->tag()->setYear(year);
}

void SortMedia::Adaptors::TagLibAdaptor::setTrack(unsigned int track)
{
  m_fileRef->tag()->setTrack(track);
}


///////////////////////////////////////////////////////////////////////////////
