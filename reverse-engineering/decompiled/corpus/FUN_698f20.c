/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698f20; label: FUN_00698f20
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

