///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Adaptor interface for the TagLib library, implementing the
//                  IMusicTagEditorAdaptor interface.
//
// CREATED:         09/05/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_TAGLIBADAPTOR__
#define __ET_TAGLIBADAPTOR__

#include <namespaces/Adaptors.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>

#include <string>

class SortMedia::Adaptors::TagLibAdaptor
  : public SortMedia::Interfaces::IMusicTagEditorAdaptor
{
public:
  TagLibAdaptor() {}

  // Getters
  virtual std::string getArtist() const final override;
  virtual std::string getAlbum() const final override;
  virtual std::string getTitle() const final override;
  virtual std::string getComment() const final override;
  virtual std::string getGenre() const final override;
  virtual unsigned int getYear() const final override;
  virtual unsigned int getTrack() const final override;

  // Setters
  virtual void setArtist(const std::string&) const final override;
  virtual void setAlbum(const std::string&) const final override;
  virtual void setTitle(const std::string&) const final override;
  virtual void setComment(const std::string&) const final override;
  virtual void setGenre(const std::string&) const final override;
  virtual void setYear(unsigned int) const final override;
  virtual void setTrack(unsigned int) const final override;
};

#endif // __ET_TAGLIBADAPTOR__

///////////////////////////////////////////////////////////////////////////////
