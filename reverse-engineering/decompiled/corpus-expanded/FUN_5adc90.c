/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5adc90; label: FUN_005adc90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_005adc90(undefined4 param_1,int *param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            float *param_7,float *param_8,int param_9,int param_10,undefined4 param_11)

{
  float fVar1;
  ushort uVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  int local_1c;
  float local_14;
  int local_10;
  undefined1 local_c [12];
  
  local_14 = 1e+09;
  local_1c = 0;
  if (param_2 != (int *)0x0) {
    iVar7 = *param_2;
    local_10 = 0;
    if ((short)param_2[2] != 0) {
      do {
        uVar2 = *(ushort *)(iVar7 + 0x13a);
        iVar6 = local_1c;
        fVar3 = local_14;
        if (((((uVar2 & 4) != 0) && ((uVar2 & 2) != 0)) && ((uVar2 & 0x30) == 0)) &&
           ((*(int *)(iVar7 + 0x1c) != 0 && ((uVar2 & 0x200) == 0)))) {
          fVar10 = (float10)FUN_005d02e0(*(int *)(iVar7 + 0x1c) + 4);
          fVar1 = (float)fVar10;
          pfVar4 = (float *)FUN_005cf9e0(*(int *)(iVar7 + 0x1c) + 4);
          if ((((*param_8 < *pfVar4 - fVar1) ||
               ((*pfVar4 + fVar1 < *param_7 || (param_8[2] < pfVar4[2] - fVar1)))) ||
              (pfVar4[2] + fVar1 < param_7[2])) ||
             (((param_8[1] < pfVar4[1] - fVar1 || (pfVar4[1] + fVar1 < param_7[1])) ||
              (iVar8 = param_5 + -1, iVar8 < 0)))) {
LAB_005ade30:
            iVar6 = local_1c;
            fVar3 = local_14;
          }
          else {
            iVar9 = param_4 + iVar8 * 0xc;
            do {
              iVar5 = FUN_0054fc70(pfVar4,fVar1,iVar9,param_6);
              if (iVar5 != 0) {
                if (param_3 == 0) {
                  iVar6 = param_4 + iVar8 * 0xc;
                }
                else {
                  iVar6 = param_3 + 0x80;
                }
                fVar10 = (float10)FUN_005b3c50(iVar6,pfVar4,0);
                iVar6 = iVar7;
                fVar3 = (float)fVar10;
                if (local_14 <= (float)fVar10) goto LAB_005ade30;
                break;
              }
              iVar8 = iVar8 + -1;
              iVar9 = iVar9 + -0xc;
            } while (-1 < iVar8);
          }
        }
        local_14 = fVar3;
        local_1c = iVar6;
        local_10 = local_10 + 1;
        iVar7 = iVar7 + 0x13c;
      } while (local_10 < (int)(uint)*(ushort *)(param_2 + 2));
      if (local_1c != 0) {
        if (((param_10 != 2) && (param_10 != 7)) && (param_9 != 0)) {
          FUN_005806a0(*(undefined1 *)(param_9 + 0x101),PTR_DAT_00802c54);
          FUN_0056e0f0(2);
        }
        iVar7 = FUN_005806a0(*(undefined1 *)(param_9 + 0x101),param_1);
        if (*(int *)(param_9 + 4) == 0) {
          iVar6 = -1;
        }
        else {
          iVar6 = (int)*(char *)(*(int *)(param_9 + 4) + 0x280);
        }
        iVar7 = FUN_005ad540(param_1,local_1c,param_9 + 0x88,iVar6,*(undefined1 *)(iVar7 + 0x3c));
        if (iVar7 == 0) {
          FUN_005b3800(local_c,local_1c + 0x24,param_9 + 0x88);
          FUN_005b3b30(local_c,local_c);
          FUN_0057fc80(param_9,param_9 + 0xac,local_c,param_11);
        }
        else if (param_3 != 0) {
          FUN_0054a850(**(undefined4 **)(param_3 + 0xca4),0x3ecccccd,0);
          FUN_00549f10();
        }
        if (*(int *)(PTR_PTR_008040bc + 8) != 0) {
          (**(code **)(PTR_PTR_008040bc + 8))(param_3,param_4);
        }
        return 1;
      }
    }
  }
  return 0;
}

