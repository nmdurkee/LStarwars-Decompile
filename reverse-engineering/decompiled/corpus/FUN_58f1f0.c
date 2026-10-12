/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58f1f0; label: FUN_0058f1f0
 */

void FUN_0058f1f0(int param_1,float *param_2,undefined4 *param_3)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = param_1;
  iVar1 = *(int *)(param_1 + 0x798);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) && (*(char *)(iVar1 + 0x6c) != '\0')) {
    uVar5 = (uint)*(byte *)(iVar1 + 0x6c);
    uVar7 = (uint)*(byte *)(iVar1 + 0x6f);
    if (uVar5 <= uVar7) {
      uVar7 = uVar5 - 1;
    }
    if (param_2 != (float *)0x0) {
      iVar6 = 0;
      param_1 = 0;
      uVar7 = ((int)uVar7 / (int)(uint)*(byte *)(iVar1 + 0x70)) * (uint)*(byte *)(iVar1 + 0x70);
      uVar8 = uVar7;
      local_c = DAT_0093b0cc;
      local_8 = DAT_0093b0d0;
      local_4 = DAT_0093b0d4;
      if (*(byte *)(iVar1 + 0x70) != 0) {
        do {
          param_1 = iVar6;
          if ((int)uVar5 <= (int)uVar8) break;
          iVar6 = iVar6 + 1;
          uVar8 = uVar8 + 1;
          param_1 = iVar6;
        } while (iVar6 < (int)(uint)*(byte *)(iVar1 + 0x70));
      }
      for (; (int)uVar7 < (int)uVar8; uVar7 = uVar7 + 1) {
        FUN_005b37d0(&local_c,&local_c,
                     *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x798) + 0x14) + uVar7 * 4) + 0x24)
                     + 0x30);
      }
      if (param_1 < 2) {
        *param_2 = local_c;
        param_2[1] = local_8;
        param_2[2] = local_4;
      }
      else {
        FUN_005b3830(param_2,&local_c,1.0 / (float)param_1);
      }
      *param_2 = (*(float *)(*(int *)(iVar4 + 0x798) + 0x28) + *param_2) * 0.5;
      fVar2 = (*(float *)(*(int *)(iVar4 + 0x798) + 0x30) + param_2[2]) * 0.5;
      param_2[2] = fVar2;
      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x798) + 0x14) +
                               (uint)*(byte *)(*(int *)(iVar4 + 0x798) + 0x6f) * 4) + 0x24);
      fVar3 = *param_2 - *(float *)(iVar1 + 0x70);
      fVar2 = fVar2 - *(float *)(iVar1 + 0x78);
      fVar9 = (float10)FUN_005c0240(fVar3 * fVar3 + fVar2 * fVar2);
      *param_2 = (float)((float10)1 / fVar9) * fVar3 * *(float *)(iVar4 + 0x1dc) + *param_2;
      param_2[2] = (float)((float10)1 / fVar9) * fVar2 * *(float *)(iVar4 + 0x1dc) + param_2[2];
    }
    if (param_3 != (undefined4 *)0x0) {
      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x798) + 0x14) + uVar7 * 4) + 0x24);
      *param_3 = *(undefined4 *)(iVar1 + 0x70);
      param_3[1] = *(undefined4 *)(iVar1 + 0x74);
      param_3[2] = *(undefined4 *)(iVar1 + 0x78);
    }
  }
  return;
}

