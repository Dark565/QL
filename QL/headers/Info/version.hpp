#pragma once

#define QL_VERSION "0.4"
#define QL_NAME "Qer Library"
#define QL_RELEASE "Qer Library 0.4 05.2018"

namespace ql {

    /* Gets version of the dynamic library */

    const char* getVersion();

    /* Gets name of the dynamic library*/

    const char* getName();

    /* Gets release version of the dynamic library*/

    const char* getRelease();
}