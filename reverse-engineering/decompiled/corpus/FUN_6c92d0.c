/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c92d0; label: FUN_006c92d0
 */

undefined4 FUN_006c92d0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_e4;
  int local_e0;
  int local_dc;
  int iStack_d4;
  int local_d0;
  int local_cc [50];
  
  iVar3 = 0xf;
  piVar1 = local_cc + 1;
  do {
    iVar4 = 0;
    piVar1[-2] = 0;
    piVar1[-1] = 0;
    *piVar1 = 0;
    piVar1 = piVar1 + 3;
    iVar3 = iVar3 + -1;
  } while (-1 < iVar3);
  local_e4 = 0;
  local_e0 = 0;
  if (0 < DAT_02973bac) {
    local_dc = 0;
    do {
      iVar3 = local_dc + DAT_02973b90;
      if (((((*(uint *)(in_ECX + 0x6c) & 1 << ((byte)local_e0 & 0x1f)) != 0) &&
           (*(int *)(iVar3 + 0x14) != 0)) && ((*(byte *)(iVar3 + 4) & 8) != 0)) &&
         (iVar2 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x14))(0), iVar4 = local_e4, iVar2 != 0))
      {
        piVar1 = local_cc + local_e4 * 3;
        do {
          iVar4 = FUN_006c8b60(iVar2,iVar3,0xffffffff);
          if (((iVar4 != 0) &&
              (fVar5 = (float10)(**(code **)(**(int **)(iVar3 + 0x14) + 0x6c))
                                          (param_1,param_2,iVar2,&iStack_d4), fVar5 < (float10)0.01)
              ) && (local_e4 < 0x10)) {
            local_e4 = local_e4 + 1;
            piVar1[-1] = iVar3;
            *piVar1 = iVar2;
            piVar1[1] = iStack_d4;
            piVar1 = piVar1 + 3;
          }
          iVar2 = (**(code **)(**(int **)(iVar3 + 0x14) + 0x14))(iVar2);
          iVar4 = local_e4;
        } while (iVar2 != 0);
      }
      local_e0 = local_e0 + 1;
      local_dc = local_dc + 0x18;
    } while (local_e0 < DAT_02973bac);
    if (iVar4 != 0) {
      iVar3 = 0;
      if (-1 < iVar4) {
        piVar1 = local_cc;
        do {
          if (*piVar1 == *(int *)(param_4 + 4)) {
            if (iVar4 + -1 <= iVar3) {
              *param_3 = local_d0;
              param_3[1] = local_cc[0];
              param_3[2] = local_cc[1];
              return 1;
            }
            *param_3 = local_cc[iVar3 * 3 + 2];
            iVar4 = local_cc[iVar3 * 3 + 4];
            param_3[1] = local_cc[iVar3 * 3 + 3];
            param_3[2] = iVar4;
            return 1;
          }
          iVar3 = iVar3 + 1;
          piVar1 = piVar1 + 3;
        } while (iVar3 <= iVar4);
      }
      *param_3 = local_d0;
      param_3[1] = local_cc[0];
      param_3[2] = local_cc[1];
      return 1;
    }
  }
  return 0;
}

