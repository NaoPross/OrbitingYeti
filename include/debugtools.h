#ifndef DEBUGTOOLS_H
#define DEBUGTOOLS_H

#ifdef QT_NO_DEBUG

#define debug_msg(msg)
#define debug_err(msg)

#else
#include <iostream>

#define debug_msg(msg) \
do { \
    std::cout << "DEBUG [" \
              << __FILE__ << " @ " << __LINE__ \
              << "]: " << msg << std::endl; \
} while (0)

#define debug_err(msg) \
do { \
    std::cerr << "ERROR [" \
              << __FILE__ << " @ " << __LINE__ \
              << "]: " << msg << std::endl; \
} while (0)

#endif // QT_NO_DEBUG
#endif // DEBUGTOOLS_H
