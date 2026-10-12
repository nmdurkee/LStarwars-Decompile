/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c8cc0; label: FUN_006c8cc0
 */

undefined4 FUN_006c8cc0(float *param_1,int *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  float10 fVar5;
  int local_98;
  int local_94;
  float local_90;
  undefined4 uStack_88;
  int *piStack_84;
  float fStack_80;
  int local_7c;
  int local_78;
  int local_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_50 [48];
  undefined1 auStack_20 [28];
  
  local_90 = 3.4028235e+38;
  local_94 = 0;
  local_98 = 0;
  local_7c = 0;
  if (0 < DAT_02973bac) {
    local_78 = 0;
    local_74 = in_ECX;
    do {
      iVar4 = local_78 + DAT_02973b90;
      if (((*(uint *)(local_74 + 0x6c) & 1 << ((byte)local_7c & 0x1f)) != 0) &&
         ((*(byte *)(iVar4 + 4) & 8) != 0)) {
        for (iVar2 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(0); iVar2 != 0;
            iVar2 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(iVar2)) {
          iVar3 = FUN_006c6a10(&uStack_88,iVar2,8,1);
          if (iVar3 != 0) {
            if ((*(byte *)(piStack_84 + 7) & 8) != 0) {
              if (piStack_84[3] == DAT_02973abc) {
                (**(code **)(*piStack_84 + 4))(uStack_88,DAT_02973abc,auStack_50,0);
                FUN_004ef660(&fStack_60,auStack_20,0x10);
              }
              else {
                (**(code **)(*piStack_84 + 4))(uStack_88,DAT_02973ab8,&fStack_60,0);
              }
            }
            fStack_70 = fStack_60 - *param_1;
            fStack_6c = fStack_5c - param_1[1];
            fStack_68 = fStack_58 - param_1[2];
            fVar1 = fStack_68 * fStack_68 + fStack_6c * fStack_6c + fStack_70 * fStack_70;
            if (fVar1 < local_90) {
              local_98 = iVar2;
              local_94 = iVar4;
              local_90 = fVar1;
            }
          }
        }
      }
      local_7c = local_7c + 1;
      local_78 = local_78 + 0x18;
    } while (local_7c < DAT_02973bac);
    if (local_98 != 0) {
      if (param_3 != 0) {
        fVar5 = (float10)FUN_005c0240(local_90);
        fStack_80 = 1.0;
        if ((((*(byte *)(local_94 + 4) & 0x40) != 0) &&
            (iVar4 = FUN_006c6a10(&uStack_88,local_98,0x40,1), iVar4 != 0)) &&
           ((*(byte *)(piStack_84 + 7) & 0x40) != 0)) {
          (**(code **)(*piStack_84 + 4))(uStack_88,DAT_02973ab4,&fStack_80,0);
        }
        if (fStack_80 < (float)fVar5) goto LAB_006c8eeb;
      }
      *param_2 = local_94;
      param_2[1] = local_98;
      return 1;
    }
  }
LAB_006c8eeb:
  *param_2 = 0;
  param_2[1] = 0;
  return 0;
}

