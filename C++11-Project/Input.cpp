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
#include "Utilities.h"
#include "Input.h"

Input::Input(){
    handle_ = Utilities::cinPollingInit();
    request_ = 0;
}

Input::~Input(){
    Utilities::cinPollingDeInit(handle_);
}

char Input::evalRequest(){
    if (!Utilities::cinPoll(request_)) {
        request_ = 0;
    }
    return request_;
}

bool Input::operator==(char c) {
    return request_ == c;
}
