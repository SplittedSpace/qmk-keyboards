#pragma once

#if defined(KEYBOARD_sofle_rev1)
#    include "rev1.h"
#elif defined(KEYBOARD_sofle_keyhive)
#    include "keyhive.h"
#elif defined(KEYBOARD_sofle_ssp)
#    include "ssp.h"
#elif defined(KEYBOARD_sofle_ssp_choc)
#    include "ssp_choc.h"
#endif
