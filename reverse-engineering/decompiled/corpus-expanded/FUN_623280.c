/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623280; label: FUN_00623280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00623280(int param_1,float param_2,float param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x70);
  if (iVar1 != DAT_029130c8) {
    DAT_029130c8 = iVar1;
    _DAT_029130c4 = 0.5;
    return iVar1;
  }
  _DAT_029130c4 = _DAT_029130c4 - param_3;
  if (_DAT_029130c4 < 0.0) {
    _DAT_029130c4 = _DAT_029130c4 + param_2;
    return DAT_029130c8;
  }
  return 0;
}

