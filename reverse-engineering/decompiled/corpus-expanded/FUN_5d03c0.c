/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d03c0; label: FUN_005d03c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d03c0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1[1] != 0) {
    iVar1 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4)
    ;
    FUN_006042e0(iVar1 + 0x1c,iVar1 + 0x28,param_2,0,0);
    return;
  }
  FUN_006042e0(param_1[2] + 0x80,param_1[2] + 0x90,param_2,0,0);
  return;
}

