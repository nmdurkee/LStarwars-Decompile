/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c6110; label: FUN_005c6110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c6110(void)

{
  bool bVar1;
  
  bVar1 = DAT_00973848 == 0;
  DAT_00973848 = (uint)bVar1;
  DAT_00806b94 = (uint)!bVar1;
  _DAT_00806b90 = DAT_00806b94;
  _DAT_00806b8c = DAT_00806b94;
  DAT_00806b88 = DAT_00806b94;
  DAT_00806b84 = DAT_00806b94;
  return;
}

