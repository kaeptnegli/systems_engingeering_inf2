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
#ifndef _INPUT_H_
#define _INPUT_H_

#include "Utilities.h"
#include "CppHelper.h"

class Input {
NO_COPY_NO_MOVE(Input);
public:
    Input();
    ~Input();

    char evalRequest();
    bool operator==(char c);

private:
    
    Utilities::CinPollingHandle handle_;
    char request_{0};

};

#endif  // _INPUT_H_

