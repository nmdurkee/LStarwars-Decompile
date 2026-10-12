/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6aef80; label: FUN_006aef80
 */

void FUN_006aef80(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EDX;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_18;
  int local_10;
  int *local_c;
  int local_8;
  
  local_8 = *(int *)(in_EDX + 4);
  local_18 = 0;
  local_10 = 1;
  if (0 < local_8) {
    local_c = (int *)(in_EDX + 8);
    iVar6 = 1;
    do {
      iVar5 = *local_c;
      iVar1 = param_1 / (iVar5 * iVar6);
      if (iVar5 == 4) {
        FUN_006acdf0(iVar6,param_4 + -4 + local_10 * 4,param_4 + -4 + (local_10 + iVar1) * 4,
                     param_4 + -4 + (local_10 + iVar1 + iVar1) * 4);
LAB_006af0f3:
        local_18 = 1 - local_18;
      }
      else if (iVar5 == 2) {
        FUN_006ac4f0(iVar6,param_4 + -4 + local_10 * 4);
        local_18 = 1 - local_18;
      }
      else {
        if (iVar5 == 3) {
          iVar2 = param_4 + -4 + (local_10 + iVar1) * 4;
          iVar7 = param_4 + -4 + local_10 * 4;
          if (local_18 == 0) {
            FUN_006ac910(iVar6,iVar7,iVar2);
          }
          else {
            FUN_006ac910(iVar6,iVar7,iVar2);
          }
          goto LAB_006af0f3;
        }
        iVar2 = param_2;
        iVar7 = param_3;
        if (local_18 != 0) {
          iVar2 = param_3;
          iVar7 = param_2;
        }
        FUN_006ad8d0(iVar1,iVar5,iVar6,iVar1 * iVar6,iVar2,iVar7,param_4 + -4 + local_10 * 4);
        if (iVar1 == 1) {
          local_18 = 1 - local_18;
        }
      }
      local_c = local_c + 1;
      local_10 = local_10 + (iVar5 + -1) * iVar1;
      local_8 = local_8 + -1;
      iVar6 = iVar5 * iVar6;
    } while (local_8 != 0);
    if (local_18 != 0) {
      iVar6 = 0;
      if (3 < param_1) {
        iVar5 = (param_1 - 4U >> 2) + 1;
        iVar6 = iVar5 * 4;
        puVar3 = (undefined4 *)(param_2 + 4);
        puVar4 = (undefined4 *)(param_3 + 0xc);
        do {
          puVar3[-1] = puVar4[-3];
          iVar5 = iVar5 + -1;
          *puVar3 = *(undefined4 *)((param_3 - param_2) + -0x10 + (int)(puVar3 + 4));
          puVar3[1] = puVar4[-1];
          puVar3[2] = *puVar4;
          puVar3 = puVar3 + 4;
          puVar4 = puVar4 + 4;
        } while (iVar5 != 0);
      }
      if (iVar6 < param_1) {
        param_1 = param_1 - iVar6;
        puVar3 = (undefined4 *)(param_2 + iVar6 * 4);
        do {
          param_1 = param_1 + -1;
          *puVar3 = *(undefined4 *)((int)puVar3 + (param_3 - param_2));
          puVar3 = puVar3 + 1;
        } while (param_1 != 0);
      }
    }
  }
  return;
}

