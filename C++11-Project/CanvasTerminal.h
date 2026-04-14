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
#ifndef _CANVAS_TERMINAL_H_
#define _CANVAS_TERMINAL_H_

#include <string>
#include "CppHelper.h"

class Timing;  // forward declaration - sufficient for use as references
class Area;    // forward declaration - sufficient for use as references
class State;   // forward declaration - sufficient for use as references
class Hoover;  // forward declaration - sufficient for use as references


class CanvasTerminal {
NO_COPY_NO_MOVE(CanvasTerminal);
public:
	CanvasTerminal(const Area &area, const Timing &timing, State &state);
	void render(double elapsed, const Hoover &hoover, const std::string& strategyName, bool isStop);
	~CanvasTerminal();

private:
	
	void flush();
	void renderAreaRow(size_t y);
	void renderText(const char* fmt, ...);  //XXX
	void renderState(size_t y, double elapsed, const Hoover &hoover, const std::string& strategyName, bool isStop);
	void clear();

	const Area   &area_;
	const Timing &timing_;
	State        &state_;
};

#endif  // _CANVAS_TERMINAL_H_

