/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622770; label: FUN_00622770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622770(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  _DAT_0080fad8 = (float)param_1;
  _DAT_0080fadc = (float)param_2 * 0.5;
  FUN_00621d90(0);
  uVar1 = FUN_006e6b90();
  *param_4 = uVar1;
  uVar1 = FUN_006e6b90();
  *param_3 = uVar1;
  return;
}

