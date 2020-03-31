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
// LAST EDITED:     03/30/2020
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

  using Tags = Interfaces::IMusicTagEditorAdaptor::Tags;
  virtual std::string getTag(Tags) const final override;
  virtual void setTag(Tags, std::string) final override;
  virtual void setTag(Tags, unsigned int) final override;

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
  virtual void setTrackTotal(const std::string&);
  virtual void setTitleSort(const std::string&);
  virtual void setAlbumSort(const std::string&);
  virtual void setArtistSort(const std::string&);
  virtual void setAlbumArtistSort(const std::string&);

  typedef std::string (SortMedia::Adaptors::TagLibAdaptor::*getter)() const;
  static constexpr getter getters[] = {
    [Tags::Artist]=&TagLibAdaptor::getArtist,
    [Tags::Album]=&TagLibAdaptor::getAlbum,
    [Tags::Title]=&TagLibAdaptor::getTitle,
    [Tags::Comment]=&TagLibAdaptor::getComment,
    [Tags::Genre]=&TagLibAdaptor::getGenre,
    [Tags::Year]=&TagLibAdaptor::getYear,
    [Tags::Track]=&TagLibAdaptor::getTrack,
    [Tags::AlbumArtist]=&TagLibAdaptor::getAlbumArtist,
    [Tags::Disc]=&TagLibAdaptor::getDisc,
    [Tags::TrackTotal]=&TagLibAdaptor::getTrackTotal,
    [Tags::TitleSort]=&TagLibAdaptor::getTitleSort,
    [Tags::AlbumSort]=&TagLibAdaptor::getAlbumSort,
    [Tags::ArtistSort]=&TagLibAdaptor::getArtistSort,
    [Tags::AlbumArtistSort]=&TagLibAdaptor::getAlbumArtistSort
  };

  typedef void (SortMedia::Adaptors::TagLibAdaptor::*setter)(const std::string&);
  static constexpr setter setters[] = {
    [Tags::Artist]=&TagLibAdaptor::setArtist,
    [Tags::Album]=&TagLibAdaptor::setAlbum,
    [Tags::Title]=&TagLibAdaptor::setTitle,
    [Tags::Comment]=&TagLibAdaptor::setComment,
    [Tags::Genre]=&TagLibAdaptor::setGenre,
    [Tags::Year]=&TagLibAdaptor::setYear,
    [Tags::Track]=&TagLibAdaptor::setTrack,
    [Tags::AlbumArtist]=&TagLibAdaptor::setAlbumArtist,
    [Tags::Disc]=&TagLibAdaptor::setDisc,
    [Tags::TrackTotal]=&TagLibAdaptor::setTrackTotal,
    [Tags::TitleSort]=&TagLibAdaptor::setTitleSort,
    [Tags::AlbumSort]=&TagLibAdaptor::setAlbumSort,
    [Tags::ArtistSort]=&TagLibAdaptor::setArtistSort,
    [Tags::AlbumArtistSort]=&TagLibAdaptor::setAlbumArtistSort
  };

  template<class extType, class intType>
  extType getTag(intType (*accessor)(void));

  std::string getTagFromPropertyMap(const std::string&) const;
  void setTagInPropertyMap(const std::string& key, const std::string& value);

  std::unique_ptr<TagLib::FileRef> m_fileRef;
};

#endif // __ET_TAGLIBADAPTOR__

///////////////////////////////////////////////////////////////////////////////
