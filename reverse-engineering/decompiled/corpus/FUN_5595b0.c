/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x5595b0; label: FUN_005595b0
 */

undefined4 FUN_005595b0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_006218c0();
  if (cVar1 != 0) {
    FUN_006216f0(param_1,(int)cVar1);
    return 1;
  }
  return 0;
}

