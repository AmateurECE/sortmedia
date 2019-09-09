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
// LAST EDITED:     09/09/2019
////

#ifndef __ET_TAGLIBADAPTOR__
#define __ET_TAGLIBADAPTOR__

#include <namespaces/Adaptors.h>
#include <SortMedia/Interfaces/IMusicTagEditorAdaptor.h>

#include <FSAdaptor/namespace.h>

#include <memory>
#include <string>

#include <taglib/fileref.h>

class SortMedia::Adaptors::TagLibAdaptor
  : public SortMedia::Interfaces::IMusicTagEditorAdaptor
{
public:
  TagLibAdaptor(const FSAdaptor::Path& path);

  // Getters
  virtual std::string getArtist() const final override;
  virtual std::string getAlbum() const final override;
  virtual std::string getTitle() const final override;
  virtual std::string getComment() const final override;
  virtual std::string getGenre() const final override;
  virtual unsigned int getYear() const final override;
  virtual unsigned int getTrack() const final override;

  // Setters
  virtual void setArtist(const std::string&) final override;
  virtual void setAlbum(const std::string&) final override;
  virtual void setTitle(const std::string&) final override;
  virtual void setComment(const std::string&) final override;
  virtual void setGenre(const std::string&) final override;
  virtual void setYear(unsigned int) final override;
  virtual void setTrack(unsigned int) final override;

private:
  std::unique_ptr<TagLib::FileRef> m_fileRef;
};

#endif // __ET_TAGLIBADAPTOR__

///////////////////////////////////////////////////////////////////////////////
