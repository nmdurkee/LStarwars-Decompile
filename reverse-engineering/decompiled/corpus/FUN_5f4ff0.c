/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f4ff0; label: FUN_005f4ff0
 */

uint FUN_005f4ff0(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_6c;
  undefined4 local_68;
  uint local_64;
  int local_60;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  iVar4 = DAT_00806ccc;
  if (DAT_00806ccc == -1) {
    iVar4 = FUN_005da980(param_1,param_2,param_5);
  }
  if (DAT_00966384 < 1) {
    iVar5 = 0;
  }
  else {
    FUN_005b30a0(local_4c,param_1 + 0x1ac,param_2);
    FUN_005b30a0(local_58,param_1 + 0x1b8,param_2);
    iVar5 = FUN_005ea6a0(local_4c,local_58,1);
  }
  iVar2 = DAT_00806ccc;
  if ((iVar4 == 0) && (iVar5 == 0)) {
    DAT_009715a0 = 0;
    return 0;
  }
  DAT_00806ccc = iVar4;
  FUN_005f9fa0(param_1,param_2,param_5);
  local_6c = 0;
  local_60 = 0;
  if (0 < param_3) {
    do {
      if (param_4 == 0) {
        param_3 = 1;
        iVar4 = 0;
LAB_005f50e6:
        iVar4 = iVar4 * 0x14;
        iVar5 = *(int *)(param_1 + 0x194) + iVar4;
        if ((*(int *)(iVar5 + 8) != 0) || (*(int *)(iVar5 + 0x10) != 0)) {
          *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
          puVar3 = DAT_009736e0;
          local_64 = *DAT_009736e0 + 0x7f & 0xffffff80;
          uVar6 = *DAT_009736e0 + 0x7f & 0xffffff80;
          *DAT_009736e0 = uVar6;
          *puVar3 = *(int *)(param_1 + 0x168) * 0x40 + uVar6;
        }
        if (param_6 == 0) {
          local_68 = 0;
        }
        else {
          local_68 = *(undefined4 *)(param_6 + local_60 * 4);
        }
        if ((*(int *)(*(int *)(param_1 + 0x194) + 4 + iVar4) != 0) &&
           (iVar7 = 0, iVar5 = param_5, 0 < *(int *)(param_1 + 0x168))) {
          do {
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x194) + 4 + iVar4) + iVar7 * 4) != 0) {
              FUN_005c0500(local_40,iVar5,param_2);
              piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x194) + 4 + iVar4) + iVar7 * 4);
              if (((piVar1 == (int *)0x0) || (*piVar1 == 0)) || (piVar1[2] == 0)) {
                uVar6 = 0;
              }
              else {
                uVar6 = FUN_005f0f00(piVar1,local_40,0,0,0);
              }
              local_6c = local_6c | uVar6;
            }
            iVar7 = iVar7 + 1;
            iVar5 = iVar5 + 0x40;
          } while (iVar7 < *(int *)(param_1 + 0x168));
        }
        if ((*(int *)(*(int *)(param_1 + 0x194) + 0xc + iVar4) != 0) &&
           (iVar7 = 0, iVar5 = param_5, 0 < *(int *)(param_1 + 0x168))) {
          do {
            if (*(int *)(*(int *)(*(int *)(param_1 + 0x194) + 0xc + iVar4) + iVar7 * 4) != 0) {
              FUN_005c0500(local_40,iVar5,param_2);
              piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 0x194) + 0xc + iVar4) + iVar7 * 4);
              if (((piVar1 == (int *)0x0) || (*piVar1 == 0)) || (piVar1[2] == 0)) {
                uVar6 = 0;
              }
              else {
                uVar6 = FUN_005f0f00(piVar1,local_40,0,0,0);
              }
              local_6c = local_6c | uVar6;
            }
            iVar7 = iVar7 + 1;
            iVar5 = iVar5 + 0x40;
          } while (iVar7 < *(int *)(param_1 + 0x168));
        }
        if ((*(int *)(*(int *)(param_1 + 0x194) + 8 + iVar4) != 0) ||
           (*(int *)(*(int *)(param_1 + 0x194) + iVar4 + 0x10) != 0)) {
          FUN_005c0350(local_64,*(undefined4 *)(param_1 + 0x174),param_5,
                       *(undefined4 *)(param_1 + 0x168));
          piVar1 = *(int **)(*(int *)(param_1 + 0x194) + 8 + iVar4);
          if (piVar1 != (int *)0x0) {
            if (*piVar1 == 0) {
              uVar6 = 0;
            }
            else if (piVar1[2] == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = FUN_005f0f00(piVar1,param_2,2,local_64,local_68);
            }
            local_6c = local_6c | uVar6;
          }
          piVar1 = *(int **)(*(int *)(param_1 + 0x194) + 0x10 + iVar4);
          if (piVar1 != (int *)0x0) {
            if (*piVar1 == 0) {
              uVar6 = 0;
            }
            else if (piVar1[2] == 0) {
              uVar6 = 0;
            }
            else {
              uVar6 = FUN_005f0f00(piVar1,param_2,2,local_64,local_68);
            }
            local_6c = local_6c | uVar6;
          }
        }
      }
      else {
        iVar4 = (int)*(short *)(param_4 + local_60 * 2);
        if ((-1 < iVar4) && (iVar4 < *(int *)(param_1 + 400))) goto LAB_005f50e6;
      }
      local_60 = local_60 + 1;
    } while (local_60 < param_3);
  }
  DAT_00806ccc = iVar2;
  DAT_009715a0 = 0;
  return local_6c;
}

