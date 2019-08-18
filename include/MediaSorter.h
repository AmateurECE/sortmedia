///////////////////////////////////////////////////////////////////////////////
// NAME:            MediaSorter.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Contains the definition of the MediaSorter, the class that
//                  implements all the logic for the application.
//
// CREATED:         08/15/2019
//
// LAST EDITED:     08/15/2019
////

#ifndef __ET_MEDIASORTER__
#define __ET_MEDIASORTER__

class MediaSorter
{
public:
  MediaSorter();
  ~MediaSorter();
  int run(int argc, char** argv);

private:
  void bootstrap();
};

#endif // __ET_MEDIASORTER__

///////////////////////////////////////////////////////////////////////////////
