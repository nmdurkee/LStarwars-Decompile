/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5acf30; label: FUN_005acf30
 */

void FUN_005acf30(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float10 fVar9;
  float local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_10 = 1e+09;
  iVar6 = 0;
  if ((param_1 != (int *)0x0) && (*(ushort *)(param_1 + 2) != 0)) {
    *(char *)(param_1 + 3) = (char)param_1[3] + '\x01';
    if ((int)(uint)*(ushort *)(param_1 + 2) <= (int)(char)param_1[3]) {
      *(undefined1 *)(param_1 + 3) = 0;
    }
    iVar7 = (char)param_1[3] * 0x13c + *param_1;
    uVar2 = *(ushort *)(iVar7 + 0x13a);
    if (((((uVar2 & 1) == 0) && (*(undefined4 *)(iVar7 + 0xe4) = 0, (uVar2 & 4) != 0)) &&
        ((uVar2 & 2) != 0)) && ((uVar2 & 0x38) == 0)) {
      if ((*(byte *)(iVar7 + 0x108) & 4) == 0) {
        local_8 = param_2;
        local_c = param_3;
      }
      else {
        local_8 = param_4;
        local_c = param_5;
      }
      if (((local_8 != 0) && (local_c != 0)) && (local_4 = 0, 0 < local_8)) {
        do {
          iVar3 = **(int **)(local_c + local_4 * 4);
          if ((((*(uint *)(iVar7 + 0x108) & 0x4000) != 0) ||
              ((*(uint *)(*(int *)(iVar3 + 0x54) + 4) & 0x80000) == 0)) &&
             (((*(uint *)(iVar7 + 0x108) & 0x20) == 0 || (*(int *)(iVar3 + 0xcd0) != 0)))) {
            fVar9 = (float10)FUN_005b3c50(iVar3 + 0x80,iVar7 + 0x30,0);
            fVar1 = (float)fVar9;
            if ((fVar1 < *(float *)(iVar7 + 0xec) * *(float *)(iVar7 + 0xec)) &&
               (iVar4 = FUN_005ace90(), iVar4 != 0)) {
              if ((*(uint *)(iVar7 + 0x108) & 0x10) == 0) {
                if ((*(uint *)(iVar7 + 0x108) & 8) == 0) {
LAB_005ad0d4:
                  if (local_10 <= fVar1) goto LAB_005ad0ef;
                }
                else if ((iVar6 != 0) &&
                        ((uVar5 = *(uint *)(iVar3 + 0x1fc) >> 7 & 1, uVar5 == 0 ||
                         ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0)))) {
                  bVar8 = uVar5 == (*(uint *)(iVar6 + 0x1fc) >> 7 & 1);
                  goto LAB_005ad0d2;
                }
              }
              else if ((iVar6 != 0) &&
                      ((uVar5 = *(uint *)(*(int *)(iVar3 + 0x54) + 4) & 0x10, uVar5 == 0 ||
                       ((*(byte *)(*(int *)(iVar6 + 0x54) + 4) & 0x10) != 0)))) {
                bVar8 = uVar5 == (*(uint *)(*(int *)(iVar6 + 0x54) + 4) & 0x10);
LAB_005ad0d2:
                if (bVar8) goto LAB_005ad0d4;
                goto LAB_005ad0ef;
              }
              iVar6 = iVar3;
              local_10 = fVar1;
            }
          }
LAB_005ad0ef:
          local_4 = local_4 + 1;
        } while (local_4 < local_8);
        if (iVar6 != 0) {
          *(int *)(iVar7 + 0xe4) = iVar6;
          *(undefined1 *)(iVar7 + 300) = 0;
        }
      }
    }
  }
  return;
}

