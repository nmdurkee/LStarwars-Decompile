/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd740; label: FUN_006cd740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cd740(int *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  int unaff_EDI;
  int unaff_retaddr;
  int iStack_4;
  
  iVar5 = (**(code **)(*param_1 + 0x18))("Class");
  if (iVar5 != 0) {
    (**(code **)(*param_1 + 0x10))();
    if (param_1[1] == 0) {
      (**(code **)(*param_1 + 8))(&stack0xfffffff4,4,1);
    }
    if (param_1[2] == 2) {
      iVar5 = *(int *)(in_ECX + 8);
      iStack_4 = 0;
      if (iVar5 != 0) {
        do {
          if ((param_1[7] & 0x400000U) == 0) {
            uVar4 = *(uint *)(iVar5 + 0x1c) & 0x10000000;
            if (((-1 < (int)*(uint *)(iVar5 + 0x1c)) || (unaff_retaddr == 0)) ||
               (*(int *)(unaff_retaddr + *(int *)(iVar5 + 0xc) * 4) != -1)) goto joined_r0x006cd7e0;
          }
          else {
            uVar4 = *(uint *)(iVar5 + 0x1c) & 0x400000;
joined_r0x006cd7e0:
            if (uVar4 == 0) {
              iStack_4 = iStack_4 + 1;
            }
          }
          iVar5 = *(int *)(iVar5 + 4);
          in_ECX = unaff_EDI;
        } while (iVar5 != 0);
      }
      (**(code **)(*param_1 + 8))(&iStack_4,4,1);
      for (iVar5 = *(int *)(in_ECX + 8); iVar5 != 0; iVar5 = *(int *)(iVar5 + 4)) {
        if ((param_1[7] & 0x400000U) == 0) {
          uVar4 = *(uint *)(iVar5 + 0x1c) & 0x10000000;
          if (((-1 < (int)*(uint *)(iVar5 + 0x1c)) || (unaff_retaddr == 0)) ||
             (*(int *)(unaff_retaddr + *(int *)(iVar5 + 0xc) * 4) != -1)) goto joined_r0x006cd840;
        }
        else {
          uVar4 = *(uint *)(iVar5 + 0x1c) & 0x400000;
joined_r0x006cd840:
          if (uVar4 == 0) {
            FUN_006c5eb0(param_1,unaff_retaddr);
          }
        }
      }
    }
    if (param_1[2] == 1) {
      if (param_1[1] < 3) {
        (**(code **)(*param_1 + 8))(&iStack_4,4,1);
        iVar5 = 0;
        if (0 < iStack_4) {
          do {
            puVar1 = (undefined4 *)param_1[6];
            puVar2 = (uint *)*puVar1;
            if (*(int *)puVar1[1] - *puVar2 < 0x29) {
LAB_006cd8f8:
              puVar6 = (undefined4 *)0x0;
            }
            else {
              *puVar2 = *puVar2 + 0xf & 0xfffffff0;
              piVar3 = (int *)*puVar1;
              puVar6 = (undefined4 *)*piVar3;
              *piVar3 = *piVar3 + 0x28;
              *puVar6 = 0;
              puVar6[1] = 0;
              puVar6[2] = 0;
              puVar6[3] = 0;
              puVar6[4] = 0;
              puVar6[5] = 0;
              puVar6[6] = 0;
              puVar6[7] = 0;
              puVar6[8] = 0;
              puVar6[9] = 0;
              puVar1[2] = puVar1[2] + 0x28;
              puVar1[3] = puVar1[3] + -0x28;
              if (puVar6 == (undefined4 *)0x0) goto LAB_006cd8f8;
              if (puVar6 + 1 != (undefined4 *)0x0) {
                puVar6[1] = 0;
                puVar6[2] = 0;
              }
              *puVar6 = &PTR_FUN_0076f9d0;
            }
            FUN_006c5eb0(param_1,0);
            FUN_006c67e0(puVar6);
            iVar5 = iVar5 + 1;
          } while (iVar5 < iStack_4);
        }
      }
      (**(code **)(*param_1 + 8))(&iStack_4,4,1);
      iVar5 = 0;
      if (0 < iStack_4) {
        do {
          puVar1 = (undefined4 *)param_1[6];
          puVar2 = (uint *)*puVar1;
          if (*(int *)puVar1[1] - *puVar2 < 0x29) {
LAB_006cd9ba:
            FUN_006b7c40();
          }
          else {
            *puVar2 = *puVar2 + 0xf & 0xfffffff0;
            piVar3 = (int *)*puVar1;
            puVar6 = (undefined4 *)*piVar3;
            *piVar3 = *piVar3 + 0x28;
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            puVar6[4] = 0;
            puVar6[5] = 0;
            puVar6[6] = 0;
            puVar6[7] = 0;
            puVar6[8] = 0;
            puVar6[9] = 0;
            puVar1[2] = puVar1[2] + 0x28;
            puVar1[3] = puVar1[3] + -0x28;
            if (puVar6 == (undefined4 *)0x0) goto LAB_006cd9ba;
            if (puVar6 + 1 != (undefined4 *)0x0) {
              puVar6[1] = 0;
              puVar6[2] = 0;
            }
            *puVar6 = &PTR_FUN_0076f9d0;
            FUN_006c5eb0(param_1,0);
            FUN_006c67e0(puVar6);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iStack_4);
      }
    }
    (**(code **)(*param_1 + 0x1c))();
  }
  return;
}

