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
#ifndef _WIN32
#include <unistd.h>
#include <termios.h>
#else
#include <conio.h>
#endif

#include "Utilities.h"

double Utilities::deg_to_rad(double deg) {
	return kPi * (deg / 180.0);
}
double Utilities::rad_to_deg(double rad) {
	return 180.0 * (rad / kPi);
}


// character polling
Utilities::CinPollingHandle Utilities::cinPollingInit() {
	CinPollingHandle handle;
#ifndef _WIN32
    tcgetattr(STDIN_FILENO, &handle.old_);

    termios raw = handle.old_;
    raw.c_lflag &= ~(ICANON | ECHO);  // no line buffering, no echo
    raw.c_cc[VMIN]  = 0;              // non-blocking read
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
#endif
    return handle;
}

bool Utilities::cinPoll(char& c) {
#ifndef _WIN32
    return read(STDIN_FILENO, &c, 1) == 1;
#else
    if (_kbhit())
    {
        c = static_cast<char>(_getch());
        return true;
    }
    return false;
#endif
}

void Utilities::cinPollingDeInit(Utilities::CinPollingHandle& handle) {
#ifndef _WIN32
    tcsetattr(STDIN_FILENO, TCSANOW, &handle.old_);
#else
	(void)handle;  // suppress compiler warning
#endif
}

