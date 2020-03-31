///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibAdaptor.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Definition of the methods of the TagLibAdaptor class.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     03/30/2020
////

#include <SortMedia/Adaptors/TagLibAdaptor.h>

#include <FSAdaptor/Path.h>

#include <taglib/fileref.h>
#include <taglib/tpropertymap.h>
#include <taglib/tstring.h>

using Tags = SortMedia::Interfaces::IMusicTagEditorAdaptor::Tags;

// TODO: Make tags static const strings to avoid repetition.

std::string SortMedia::Adaptors::TagLibAdaptor
::getTag(Tags) const { return ""; }
void SortMedia::Adaptors::TagLibAdaptor
::setTag(Tags, std::string) {}
void SortMedia::Adaptors::TagLibAdaptor
::setTag(Tags, unsigned int) {}

SortMedia::Adaptors::TagLibAdaptor::TagLibAdaptor(const FSAdaptor::Path& path)
  : m_fileRef(std::make_unique<TagLib::FileRef>(path.string().c_str()))
{}

// Private functions
std::string SortMedia::Adaptors::TagLibAdaptor
::getTagFromPropertyMap(const std::string& tagName) const
{
  TagLib::PropertyMap map = m_fileRef->file()->properties();
  map.removeEmpty();
  TagLib::StringList& list = map[tagName];
  if (list.isEmpty())
    {
      return "";
    }
  return list.front().to8Bit(true);
}

void SortMedia::Adaptors::TagLibAdaptor
::setTagInPropertyMap(const std::string& key, const std::string& value)
{
  TagLib::PropertyMap properties = m_fileRef->tag()->properties();
  properties.erase(key);
  // TODO: Check success of insert?
  properties.insert(key, TagLib::StringList{value});
  m_fileRef->tag()->setProperties(properties);
}

// Getters
std::string SortMedia::Adaptors::TagLibAdaptor::getArtist() const
{
  TagLib::String s = m_fileRef->tag()->artist();
  if (s == TagLib::String::null)
    {
      return "";
    }
  return s.to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getAlbum() const
{
  TagLib::String s = m_fileRef->tag()->album();
  if (s == TagLib::String::null)
    {
      return "";
    }
  return s.to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getTitle() const
{
  TagLib::String s = m_fileRef->tag()->title();
  if (s == TagLib::String::null)
    {
      return "";
    }
  return s.to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getComment() const
{
  TagLib::String s = m_fileRef->tag()->comment();
  if (s == TagLib::String::null)
    {
      return "";
    }
  return s.to8Bit(true);
}

std::string SortMedia::Adaptors::TagLibAdaptor::getGenre() const
{
  TagLib::String s = m_fileRef->tag()->genre();
  if (s == TagLib::String::null)
    {
      return "";
    }
  return s.to8Bit(true);
}

// TODO: Allow to return unsigned int
std::string SortMedia::Adaptors::TagLibAdaptor::getYear() const
{
  return std::to_string(m_fileRef->tag()->year());
}

std::string SortMedia::Adaptors::TagLibAdaptor::getTrack() const
{
  return std::to_string(m_fileRef->tag()->track());
}

// Extra getters
std::string SortMedia::Adaptors::TagLibAdaptor::getAlbumArtist() const
{
  return getTagFromPropertyMap("ALBUMARTIST");
}

std::string SortMedia::Adaptors::TagLibAdaptor::getDisc() const
{
  return getTagFromPropertyMap("DISCNUMBER");
}

std::string SortMedia::Adaptors::TagLibAdaptor::getTrackTotal() const
{
  std::string track = getTagFromPropertyMap("TRACKNUMBER");
  std::size_t pos = track.find("/");
  if (pos != std::string::npos)
    {
      return track.substr(pos + 1);
    }
  return "";
}

std::string SortMedia::Adaptors::TagLibAdaptor::getTitleSort() const
{
  return getTagFromPropertyMap("TITLESORT");
}

std::string SortMedia::Adaptors::TagLibAdaptor::getAlbumSort() const
{
  return getTagFromPropertyMap("ALBUMSORT");
}

std::string SortMedia::Adaptors::TagLibAdaptor::getArtistSort() const
{
  return getTagFromPropertyMap("ARTISTSORT");
}

std::string SortMedia::Adaptors::TagLibAdaptor::getAlbumArtistSort() const
{
  return getTagFromPropertyMap("ALBUMARTISTSORT");
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

void SortMedia::Adaptors::TagLibAdaptor::setYear(const std::string& year)
{
  m_fileRef->tag()->setYear(std::stoi(year));
}

void SortMedia::Adaptors::TagLibAdaptor::setTrack(const std::string& track)
{
  m_fileRef->tag()->setTrack(std::stoi(track));
}

// Setters for extra tags
void SortMedia::Adaptors::TagLibAdaptor
::setAlbumArtist(const std::string& albumArtist)
{
  setTagInPropertyMap("ALBUMARTIST", albumArtist);
}

void SortMedia::Adaptors::TagLibAdaptor
::setDisc(const std::string& disc)
{
  setTagInPropertyMap("DISCNUMBER", disc);
}

// TODO: Implement setTrackTotal
void SortMedia::Adaptors::TagLibAdaptor
::setTrackTotal(const std::string& trackTotal)
{
  throw std::logic_error{"Function not yet implemented."};
}

void SortMedia::Adaptors::TagLibAdaptor
::setTitleSort(const std::string& title)
{
  setTagInPropertyMap("TITLESORT", title);
}

void SortMedia::Adaptors::TagLibAdaptor
::setAlbumSort(const std::string& album)
{
  setTagInPropertyMap("ALBUMSORT", album);
}

void SortMedia::Adaptors::TagLibAdaptor
::setArtistSort(const std::string& artist)
{
  setTagInPropertyMap("ARTISTSORT", artist);
}

void SortMedia::Adaptors::TagLibAdaptor
::setAlbumArtistSort(const std::string& albumArtist)
{
  setTagInPropertyMap("ALBUMARTISTSORT", albumArtist);
}

///////////////////////////////////////////////////////////////////////////////
