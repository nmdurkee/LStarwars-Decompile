/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6ac310; label: FUN_006ac310
 */

void FUN_006ac310(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  int unaff_ESI;
  int iVar6;
  int local_14;
  int *local_10;
  int local_4;
  
  local_4 = *(int *)(in_ECX + 4);
  local_14 = 1;
  if (0 < local_4) {
    local_10 = (int *)(in_ECX + 4 + local_4 * 4);
    iVar3 = param_1;
    iVar6 = param_1;
    do {
      iVar1 = *local_10;
      iVar2 = iVar3 / iVar1;
      iVar3 = param_1 / iVar3;
      local_14 = 1 - local_14;
      iVar6 = iVar6 - (iVar1 + -1) * iVar3;
      if (iVar1 == 4) {
        FUN_006aa330(iVar2,param_3 + -4 + iVar6 * 4,param_3 + -4 + (iVar3 + iVar6) * 4,
                     param_3 + -4 + (iVar3 + iVar6 + iVar3) * 4);
      }
      else if (iVar1 == 2) {
        if (local_14 == 0) {
          FUN_006aa000(iVar2,param_3 + -4 + iVar6 * 4);
        }
        else {
          FUN_006aa000(iVar2,param_3 + -4 + iVar6 * 4);
        }
      }
      else {
        if (iVar3 == 1) {
          local_14 = 1 - local_14;
        }
        if (local_14 == 0) {
          FUN_006aac20(iVar1,iVar2,iVar3 * iVar2);
          local_14 = 1;
        }
        else {
          FUN_006aac20(iVar1,iVar2,iVar3 * iVar2,param_2,param_2);
          local_14 = 0;
        }
      }
      local_10 = local_10 + -1;
      local_4 = local_4 + -1;
      iVar3 = iVar2;
    } while (local_4 != 0);
    if (local_14 != 1) {
      iVar3 = 0;
      if (3 < param_1) {
        iVar6 = (param_1 - 4U >> 2) + 1;
        iVar3 = iVar6 * 4;
        puVar4 = (undefined4 *)(unaff_ESI + 4);
        puVar5 = (undefined4 *)(param_2 + 0xc);
        do {
          puVar4[-1] = puVar5[-3];
          iVar6 = iVar6 + -1;
          *puVar4 = *(undefined4 *)((param_2 - unaff_ESI) + -0x10 + (int)(puVar4 + 4));
          puVar4[1] = puVar5[-1];
          puVar4[2] = *puVar5;
          puVar4 = puVar4 + 4;
          puVar5 = puVar5 + 4;
        } while (iVar6 != 0);
      }
      if (iVar3 < param_1) {
        param_1 = param_1 - iVar3;
        puVar4 = (undefined4 *)(unaff_ESI + iVar3 * 4);
        do {
          param_1 = param_1 + -1;
          *puVar4 = *(undefined4 *)((int)puVar4 + (param_2 - unaff_ESI));
          puVar4 = puVar4 + 1;
        } while (param_1 != 0);
      }
    }
  }
  return;
}

