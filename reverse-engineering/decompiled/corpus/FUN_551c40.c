/* Ghidra analysis pseudocode, not original source.
 * ev_79d77eca71f7fc5404139f960d2da4bb199b6774aebfe9446502c31b4f71f31f
 * Entry: 0x551c40; label: FUN_00551c40
 */

void FUN_00551c40(int param_1,undefined4 *param_2,short *param_3,char param_4,short param_5,
                 short param_6)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_14;
  undefined1 local_c [12];
  
  local_14 = 1e+09;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    if (((param_1 != 0) && (param_3 != (short *)0x0)) && (1 < *param_3)) {
      *param_2 = param_3;
      *(char *)((int)param_2 + 6) = param_4;
      sVar1 = *param_3;
      iVar4 = (int)sVar1;
      if (param_4 != '\0') {
        iVar4 = iVar4 + 1;
      }
      if (param_5 < 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (int)param_5;
        if (iVar4 <= iVar5) {
          return;
        }
      }
      if ((param_6 < 0) || (sVar1 < param_6)) {
        param_6 = sVar1;
      }
      iVar6 = param_3[1] * iVar5 + *(int *)(param_3 + 4);
      do {
        fVar8 = (float10)FUN_005b3c50(param_1,iVar6,local_c);
        if ((float)fVar8 < local_14) {
          *(short *)(param_2 + 1) = (short)iVar5;
          local_14 = (float)fVar8;
        }
        psVar3 = (short *)*param_2;
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + psVar3[1];
      } while (iVar5 < param_6);
      sVar1 = psVar3[1];
      iVar5 = *(int *)(psVar3 + 4);
      sVar2 = *psVar3;
      param_2[2] = 0;
      puVar7 = (undefined4 *)((int)*(short *)(param_2 + 1) * (int)sVar1 + iVar5);
      fVar8 = (float10)FUN_005becc0(((*(short *)(param_2 + 1) + 1) % (int)sVar2) * (int)sVar1 +
                                    iVar5,puVar7,local_c);
      param_2[3] = (float)fVar8;
      param_2[4] = *puVar7;
      param_2[5] = puVar7[1];
      param_2[6] = puVar7[2];
      param_2[7] = ((float)(int)*(short *)(param_2 + 1) + (float)param_2[2] / (float)fVar8) /
                   (float)(iVar4 + -1);
    }
  }
  return;
}

