/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x545240; label: FUN_00545240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00545240(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int *param_5,
                 undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  int local_4;
  
  iVar1 = param_5[1];
  local_4 = 0;
  piVar2 = param_5;
  if (*param_5 < iVar1) {
    do {
      FUN_00545030(param_1,param_2 + *piVar2 * 0xc,iVar1 - *piVar2,param_6);
      FUN_00545030(param_1,param_3 + *piVar2 * 0xc,piVar2[1] - *piVar2,param_6);
      local_4 = local_4 + 1;
      piVar2 = param_5 + local_4;
      iVar1 = piVar2[1];
    } while (*piVar2 < iVar1);
  }
  return;
}

