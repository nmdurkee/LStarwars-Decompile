/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443ef0; label: FUN_00443ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443ef0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_4;
  
  local_4 = 1e+09;
  if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
    iVar1 = 0;
    if (DAT_0093d810 != 0) {
      fVar2 = (float10)FUN_005b3cf0(DAT_0093d810 + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,0);
      local_4 = (float)fVar2;
      iVar1 = DAT_0093d810;
    }
    if (DAT_0093d814 != 0) {
      fVar2 = (float10)FUN_005b3cf0(DAT_0093d814 + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,0);
      if (fVar2 < (float10)local_4) {
        iVar1 = DAT_0093d814;
      }
    }
    if ((iVar1 != 0) &&
       ((*(uint *)(*(int *)(param_3 + 0xd0) + 0x2b0) & *(uint *)(iVar1 + 0x2b0)) != 0 ||
        (*(uint *)(*(int *)(param_3 + 0xd0) + 0x2b4) & *(uint *)(iVar1 + 0x2b4)) != 0)) {
      return (float10)1;
    }
  }
  return (float10)0;
}

