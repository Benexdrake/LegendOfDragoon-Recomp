/*
 * Legend of Dragoon widescreen enhancement plugin.
 *
 * Widescreen is mod-owned on PSX: the runtime clamps game.toml / settings.toml
 * aspect values back to 4:3 unless a trusted plugin selects a display aspect on
 * activation. This plugin runs only while the "lod.enhancement.widescreen"
 * feature is enabled in the resolved mod plan.
 *
 * Field backdrops are pre-rendered 4:3 strips and are NOT widened here. A
 * variant that tags the backdrop tiles for stretching (gpu_ws_tag_background_prim
 * from gpu_ws_set_list_kick_hook) fills the width but breaks 8-bit CLUT
 * foreground pieces in the wide pass; it is kept in analysis/ for reference.
 */
#include "mod_plugins.h"

#include <stdio.h>

static void lod_widescreen_activate(void) {
    if (!psx_mod_set_fixed_display_aspect(16, 9)) {
        fprintf(stdout, "lod: widescreen: runtime rejected 16:9 display aspect\n");
    }
}

PSX_MOD_CONSTRUCTOR(lod_register_widescreen_plugin) {
    (void)psx_mod_register_activation_plugin("lod.widescreen",
                                             lod_widescreen_activate);
}
