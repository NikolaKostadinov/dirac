#pragma once

#include <stdexcept>

#define INF_DX              std::logic_error("DIRAC ENGINE: infinite dx"          )
#define FORBIDDEN_SIZE      std::logic_error("DIRAC ENGINE: forbidden size"       )
#define BASE_NOT_SAME       std::logic_error("DIRAC ENGINE: basis not same"       )
#define OUT_OF_BOUNDS       std::logic_error("DIRAC ENGINE: index out of bounds"  )
#define OUT_OF_X_BOUNDS     std::logic_error("DIRAC ENGINE: index out of x bounds")
#define OUT_OF_Y_BOUNDS     std::logic_error("DIRAC ENGINE: index out of y bounds")
#define OUT_OF_Z_BOUNDS     std::logic_error("DIRAC ENGINE: index out of z bounds")
#define ZERO_NORM           std::logic_error("DIRAC ENGINE: zero norm"            )
#define NEGATIVE_NORM       std::logic_error("DIRAC ENGINE: negative norm"        )
#define ZERO_MASS           std::logic_error("DIRAC ENGINE: zero mass"            )
#define NEGATIVE_MASS       std::logic_error("DIRAC ENGINE: negative mass"        )