///////////////////////////////////////////////////////////////////////////////
// NAME:            SortMedia.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     The SortMedia Namespace.
//
// CREATED:         08/27/2019
//
// LAST EDITED:     09/05/2019
////

#ifndef __ET_SORTMEDIA__
#define __ET_SORTMEDIA__

// As soon as Apple Clang gets C++17 filesystem library on my machine:
// namespace std
// {
//   class path;
// }

namespace SortMedia
{
  class MediaSorter;

  namespace Logging
  {
    class NullLogger;
    class StreamLogger;    
  };
};

#endif // __ET_SORTMEDIA__

///////////////////////////////////////////////////////////////////////////////
