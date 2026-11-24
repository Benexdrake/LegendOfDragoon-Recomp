# LegendOfDragoon Recompiled release notes

## v0.1.0 - first release (SCES-03045, Europe)

- **16:9 widescreen in battle**, including culling hooks so polygons at the screen edges no longer pop in.
- **60 fps** instead of PAL 50 Hz (PAL timing is forced to NTSC 60 Hz; `PSX_FORCE_60HZ=0` restores 50 Hz).
- Multi-disc support (4 discs).

Known limitation: field scenes use pre-rendered backgrounds that stay 4:3 wide, so black side bars remain there. Only the beginning of the game was tested; world map, towns, menus and FMV are untested.

Save states from other builds do not load. Native memory-card saves are unaffected.
