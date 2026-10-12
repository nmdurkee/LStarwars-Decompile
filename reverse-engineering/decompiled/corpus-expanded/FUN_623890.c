/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623890; label: FUN_00623890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00623890(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  _DAT_0080fad8 = (float)param_3;
  _DAT_0080fadc = (float)param_4 * 0.5;
  FUN_00621d90(0);
  uVar1 = FUN_006e6b90();
  *(undefined4 *)(param_1 + 0x20) = uVar1;
  uVar1 = FUN_006e6b90();
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return *(undefined4 *)(param_1 + 0x20);
}

