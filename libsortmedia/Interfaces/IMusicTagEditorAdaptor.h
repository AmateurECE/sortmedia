///////////////////////////////////////////////////////////////////////////////
// NAME:            IMusicTagEditorAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Adaptor interface for manipulating tags of music files.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     05/04/2023
////

#ifndef __ET_IMUSICTAGEDITORADAPTOR__
#define __ET_IMUSICTAGEDITORADAPTOR__

#include <libsortmedia/namespaces/Interfaces.h>

#include <string>
#include <cstdint>

// TODO: Add means to manipulate generic key/value tags

class SortMedia::Interfaces::IMusicTagEditorAdaptor
{
public:
  virtual ~IMusicTagEditorAdaptor() {}

  enum Tags : uint8_t
    {
      Artist,
      Album,
      Title,
      Comment,
      Genre,
      Year,
      Track,
      TrackTotal,
      AlbumArtist,
      Disc,
      DiscTotal,
      TitleSort,
      AlbumSort,
      ArtistSort,
      AlbumArtistSort
    };

  virtual std::string getTag(Tags) const = 0;
  virtual void setTag(Tags, const std::string&) = 0;
  virtual void setTag(Tags, unsigned int) = 0;
};

#endif // __ET_IMUSICTAGEDITORADAPTOR__

///////////////////////////////////////////////////////////////////////////////
