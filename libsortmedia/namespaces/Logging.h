///////////////////////////////////////////////////////////////////////////////
// NAME:            Logging.h
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Namespace for logging entities.
//
// CREATED:         09/06/2019
////

#ifndef __ET_LOGGING__
#define __ET_LOGGING__

#include <stdint.h>

namespace SortMedia
{
  namespace Logging
  {
    enum LogLevel : uint8_t
      {
        INFO,
        WARNING,
        ERROR
      };

    class NullLogger;
    class StreamLogger;
  };
};

#endif // __ET_LOGGING__

///////////////////////////////////////////////////////////////////////////////
