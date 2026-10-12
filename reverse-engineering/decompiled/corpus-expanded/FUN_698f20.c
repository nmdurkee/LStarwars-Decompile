/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x698f20; label: FUN_00698f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698f20(int param_1)

{
  int iVar1;
  
  FUN_00698c50();
  if (param_1 != 0) {
    FUN_006989b0(DAT_02972bf8);
    FUN_006989b0(DAT_00810dac);
    while ((iVar1 = FUN_006997a0(), iVar1 != 0 || (iVar1 = FUN_006997a0(), iVar1 != 0))) {
      Sleep(10);
    }
  }
  return;
}

