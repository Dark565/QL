#pragma once

#include <cstdint>
#include <string>

#include "../Arrays/array.hpp"
#include "../Colorize/colors.hpp"
#include "../Definitions/defs.hpp"
#include "../Pixmap/pixmap.hpp"
#include "OS/os.hpp"

namespace ql {
    class Window {
        window_t w_handle;

    public:

        class enum BarFlags {
            normal = 1,
            no_exit = 2,
            no_fold = 4,
            no_resize = 8,
            no_buttons = 16

        }

        /*Creates the window*/

        bool create(uint32_t x, uint32_t y, q, const std::string& name, const Pixel& col, BarFlags flags);

        /*Destroys the window*/

        bool destroy();

        /*Checks does window exist*/

        bool isLegit();

        /*Hides the window*/

        bool hide(bool yn);

        /*Applies pixmap to the window*/

        bool applyPixmap(const Pixmap& pix);

        /*Sets background color*/

        bool setBackgroundColor(const Pixmap& col);

        /*Sets window's name*/

        bool setName(const std::string& name);

        /*Hides title bar*/

        bool hideTitlebar(bool yn);

        /*Sets window's size*/

        bool setSize(uint32_t x, uint32_t y);

        /*Sets window's position*/

        bool setPosition(uint32_t x, uint32_t y);
        
        /*Gets window's size*/

        Array<uint32_t, 2> getWindowSize();

        /*Gets window's position*/
        
        Array<uint32_t, 2> getWindowPos();

        /*Updates window*/

        bool update();

        /*Gets window's content as pixmap*/

        Pixmap getWindowContent();

    };
}