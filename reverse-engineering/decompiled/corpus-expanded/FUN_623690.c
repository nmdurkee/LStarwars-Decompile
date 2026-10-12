/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623690; label: FUN_00623690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00623690(undefined4 param_1,int param_2)

{
  FUN_006232e0(param_1,param_2);
  FUN_00621d90(1);
  if ((*(byte *)(param_2 + 0x70) & 0x10) != 0) {
    FUN_004f1f10(&DAT_02913060,PTR_DAT_0080fad0 + 7);
    DAT_02912f4d = 0;
  }
  return;
}

