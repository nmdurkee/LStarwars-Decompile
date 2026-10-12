/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x4604e0; label: FUN_004604e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004604e0(undefined4 param_1,int param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004850e0(0x3f800000);
  _DAT_0087a188 = (float)fVar1;
  FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),*(int *)(param_2 + 0x84) + *(int *)(param_2 + 0x88),0
               ,0);
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  FUN_004838f0(param_2);
  return;
}

