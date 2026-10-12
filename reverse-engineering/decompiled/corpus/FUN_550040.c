/* Ghidra analysis pseudocode, not original source.
 * ev_ec07135468de31ab5fb92b99d3a0e31a017920018520f35a1e7400fac21801d6
 * Entry: 0x550040; label: FUN_00550040
 */

int FUN_00550040(ushort param_1,ushort param_2)

{
  int iVar1;
  
  iVar1 = (uint)param_2 - (uint)param_1;
  if (0x8000 < iVar1) {
    return iVar1 + -0x10000;
  }
  if (iVar1 < -0x8000) {
    iVar1 = iVar1 + 0x10000;
  }
  return iVar1;
}

