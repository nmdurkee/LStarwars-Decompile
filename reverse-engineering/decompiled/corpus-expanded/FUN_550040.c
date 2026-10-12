/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550040; label: FUN_00550040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

