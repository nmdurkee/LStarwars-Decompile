/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40ebc0; label: FUN_0040ebc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040ebc0(void)

{
  undefined4 *unaff_ESI;
  
  if ((unaff_ESI != (undefined4 *)0x0) && (unaff_ESI[1] != 0)) {
    _memset((void *)*unaff_ESI,0,unaff_ESI[1] * 0x60);
    unaff_ESI[2] = 0;
  }
  return;
}

