/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fd9c0; label: FUN_005fd9c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd9c0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = FUN_00741610();
  if (iVar2 != 0) {
    if (8 < iVar1) {
      iVar2 = FUN_005f74a0();
    }
    FUN_00744060(iVar2,0x18,0,iVar1,param_1 + 1);
  }
  return;
}

