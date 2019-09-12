///////////////////////////////////////////////////////////////////////////////
// NAME:            IMusicTagEditorAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Adaptor interface for manipulating tags of music files.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/12/2019
////

#ifndef __ET_IMUSICTAGEDITORADAPTOR__
#define __ET_IMUSICTAGEDITORADAPTOR__

#include <namespaces/Interfaces.h>

#include <string>

// TODO: Add means to manipulate generic key/value tags

class SortMedia::Interfaces::IMusicTagEditorAdaptor
{
public:
  virtual ~IMusicTagEditorAdaptor() {}

  // Getters
  virtual std::string getArtist() const                     = 0;
  virtual std::string getAlbum() const                      = 0;
  virtual std::string getTitle() const                      = 0;
  virtual std::string getComment() const                    = 0;
  virtual std::string getGenre() const                      = 0;
  virtual unsigned int getYear() const                      = 0;
  virtual unsigned int getTrack() const                     = 0;

  // Getters for extra tags
  virtual std::string getAlbumArtist() const                = 0;
  virtual std::string getDisc() const                       = 0;
  virtual std::string getTitleSort() const                  = 0;
  virtual std::string getAlbumSort() const                  = 0;
  virtual std::string getArtistSort() const                 = 0;
  virtual std::string getAlbumArtistSort() const            = 0;

  // Setters
  virtual void setArtist(const std::string&)                = 0;
  virtual void setAlbum(const std::string&)                 = 0;
  virtual void setTitle(const std::string&)                 = 0;
  virtual void setComment(const std::string&)               = 0;
  virtual void setGenre(const std::string&)                 = 0;
  virtual void setYear(unsigned int)                        = 0;
  virtual void setTrack(unsigned int)                       = 0;

  // Setters for extra tags
  virtual void setAlbumArtist(const std::string&)           = 0;
  virtual void setDisc(const std::string&)                  = 0;
  virtual void setTitleSort(const std::string&)             = 0;
  virtual void setAlbumSort(const std::string&)             = 0;
  virtual void setArtistSort(const std::string&)            = 0;
  virtual void setAlbumArtistSort(const std::string&)       = 0;
};

#endif // __ET_IMUSICTAGEDITORADAPTOR__

///////////////////////////////////////////////////////////////////////////////
