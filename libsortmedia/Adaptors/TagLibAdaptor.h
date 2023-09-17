///////////////////////////////////////////////////////////////////////////////
// NAME:            TagLibAdaptor.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Adaptor interface for the TagLib library, implementing the
//                  IMusicTagEditorAdaptor interface.
//
// CREATED:         09/05/2019
////

#ifndef __ET_TAGLIBADAPTOR__
#define __ET_TAGLIBADAPTOR__

#include <libsortmedia/namespaces/Adaptors.h>
#include <libsortmedia/Interfaces/IMusicTagEditorAdaptor.h>

#include <fsadaptor/namespace.h>

#include <memory>
#include <string>

#include <taglib/fileref.h>

class SortMedia::Adaptors::TagLibAdaptor
  : public SortMedia::Interfaces::IMusicTagEditorAdaptor
{
public:
  TagLibAdaptor(const FSAdaptor::Path& path);

  using Tags = Interfaces::IMusicTagEditorAdaptor::Tags;
  virtual std::string getTag(Tags) const final override;
  virtual void setTag(Tags, const std::string&) final override;
  virtual void setTag(Tags, unsigned int) final override;

protected:
  std::string getTagFromPropertyMap(const std::string&) const;
  void setTagInPropertyMap(const std::string& key, const std::string& value);

private:
  // Getters
  virtual std::string getArtist() const;
  virtual std::string getAlbum() const;
  virtual std::string getTitle() const;
  virtual std::string getComment() const;
  virtual std::string getGenre() const;
  virtual std::string getYear() const;
  virtual std::string getTrack() const;

  // Getters for extra tags
  virtual std::string getAlbumArtist() const;
  virtual std::string getDisc() const;
  virtual std::string getDiscTotal() const;
  virtual std::string getTrackTotal() const;
  virtual std::string getTitleSort() const;
  virtual std::string getAlbumSort() const;
  virtual std::string getArtistSort() const;
  virtual std::string getAlbumArtistSort() const;

  // Setters
  virtual void setArtist(const std::string&);
  virtual void setAlbum(const std::string&);
  virtual void setTitle(const std::string&);
  virtual void setComment(const std::string&);
  virtual void setGenre(const std::string&);
  virtual void setYear(const std::string&);
  virtual void setTrack(const std::string&);

  // Setters for extra tags
  virtual void setAlbumArtist(const std::string&);
  virtual void setDisc(const std::string&);
  virtual void setDiscTotal(const std::string&);
  virtual void setTrackTotal(const std::string&);
  virtual void setTitleSort(const std::string&);
  virtual void setAlbumSort(const std::string&);
  virtual void setArtistSort(const std::string&);
  virtual void setAlbumArtistSort(const std::string&);

  std::unique_ptr<TagLib::FileRef> m_fileRef;
};

#endif // __ET_TAGLIBADAPTOR__

///////////////////////////////////////////////////////////////////////////////
