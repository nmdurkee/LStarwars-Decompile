/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9180; label: FUN_006c9180
 */

bool FUN_006c9180(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_30;
  int local_28;
  int iStack_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_30 = 3.4028235e+38;
  iVar3 = 0;
  local_14 = 0;
  local_1c = 0;
  local_18 = 0;
  if (0 < DAT_02973bac) {
    local_28 = 0;
    do {
      iVar4 = local_28 + DAT_02973b90;
      if ((((*(uint *)(in_ECX + 0x6c) & 1 << ((byte)iVar3 & 0x1f)) != 0) &&
          (*(int *)(iVar4 + 0x14) != 0)) && ((*(byte *)(iVar4 + 4) & 8) != 0)) {
        for (iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(0); iVar1 != 0;
            iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(iVar1)) {
          iVar2 = FUN_006c8b60(iVar1,iVar4,0xffffffff);
          if (iVar2 != 0) {
            fVar5 = (float10)(**(code **)(**(int **)(iVar4 + 0x14) + 0x6c))
                                       (param_1,param_2,iVar1,&iStack_20);
            if ((float)fVar5 < local_30) {
              local_14 = iStack_20;
              local_30 = (float)fVar5;
              local_1c = iVar4;
              local_18 = iVar1;
            }
          }
        }
      }
      iVar3 = iVar3 + 1;
      local_28 = local_28 + 0x18;
    } while (iVar3 < DAT_02973bac);
  }
  if ((param_4 != 0) && (0.0 < local_30)) {
    local_1c = 0;
    local_18 = 0;
  }
  *param_3 = local_1c;
  param_3[1] = local_18;
  param_3[2] = local_14;
  return param_3[1] != 0;
}

