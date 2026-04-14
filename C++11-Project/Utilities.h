/*
 * ------------------------------------------------------------------
 * --    _       _ _______                                         --
 * --   | |     | |__   __|                                        --
 * --   | |_ __ | |  | |      InIT Institut fuer Informatik        --
 * --   | | '_ \| |  | |      Zuercher Hochschule Winterthur       --
 * --   | | | | | |  | |      (University of Applied Sciences)     --
 * --   |_|_| |_|_|  |_|      8401 Winterthur, Switzerland         --
 * ------------------------------------------------------------------
 * -- Project     : INF2 - Labs                                    --
 * -- Autor       : giei                                           --
 * -- Datum       : 2026-02-13                                     --
 * ------------------------------------------------------------------
 */
#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <unistd.h>
#include "CppHelper.h"
#ifndef _WIN32
#include <termios.h>
#endif

// use compile-time constant for GATE flag
// e.g.: DEBUG_TRACE(true) << "some " << "debug " << " text" << "\n";   // true:  the text is emitted
// or    DEBUG_TRACE(false) << "some " << "debug " << " text" << "\n";  // false: no text emitted
#define DEBUG_TRACE(GATE) if (!GATE) {} else (std::cout << "DEBUG: ")  // make macro usage robust for usage in nested if's

namespace Utilities {

// PI
constexpr double kPi = 3.14159265358979323846;

// rad/dec comversion
double deg_to_rad(double deg);
double rad_to_deg(double rad);

// character polling
struct CinPollingHandle {
#ifndef _WIN32
	struct termios old_;
#endif
};
CinPollingHandle cinPollingInit();
bool cinPoll(char& c);
void cinPollingDeInit(CinPollingHandle& handle);

}  // namespace Utilities

#endif  // _UTILITIES_H_


