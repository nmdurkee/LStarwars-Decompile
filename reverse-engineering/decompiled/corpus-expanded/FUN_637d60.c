/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637d60; label: FUN_00637d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00637d60(uint *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = FUN_005bec00(param_3);
  if (iVar2 < 2) {
    DAT_029139c0 = 2;
  }
  else {
    DAT_029139c0 = FUN_005bec00(param_3);
  }
  _DAT_029138b0 = *param_1 + 3 & 0xfffffffc;
  DAT_029135e4 = (*param_1 + 3 & 0xfffffffc) + DAT_029139c0 * 0x4600;
  DAT_029134e8 = DAT_029135e4 + DAT_029139c0 * 4;
  DAT_029138c0 = DAT_029134e8 + DAT_029139c0 * 4;
  DAT_029134bc = DAT_029138c0 + DAT_029139c0 * 4;
  uVar1 = DAT_029134bc + DAT_029139c0 * 0xc;
  *param_1 = uVar1;
  if (param_2 < uVar1) {
    FUN_00633df0();
    return;
  }
  return;
}

