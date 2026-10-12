/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8af0; label: FUN_004f8af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f8af0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004f20f0(param_1,param_2);
  if (iVar1 == 0) {
    _DAT_0091eecc = _DAT_0091eecc + 1;
  }
  return;
}

