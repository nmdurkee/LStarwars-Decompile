/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55cee0; label: FUN_0055cee0
 */

int FUN_0055cee0(float *param_1,int param_2,uint param_3,float param_4,float param_5,int param_6,
                int param_7,int param_8,float *param_9,int param_10,code *param_11)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int local_10;
  int local_8;
  
  fVar1 = param_4 * param_4;
  local_10 = 0;
  local_8 = 0;
  param_4 = 1e+08;
  iVar6 = 0;
  iVar7 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      fVar2 = param_4;
      iVar6 = local_10;
      if ((((((*(uint *)(iVar7 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
           (*(char *)(iVar7 + 0x28b) == '\0')) &&
          (((*(byte *)(iVar7 + 0xe20) & 0x20) == 0 &&
           ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar7 + 0x7b5) * 0x10 + 8) & 0x8000) == 0)))) &&
         ((param_7 == -1 || (*(short *)(iVar7 + 0x1064) == param_7)))) {
        if (-1 < param_8) {
          if (param_8 < 2) {
            bVar8 = *(char *)(iVar7 + 0x280) == param_8;
LAB_0055cfc9:
            if (!bVar8) goto LAB_0055d0ea;
          }
          else if (param_8 == 99) {
            if (*(char *)(iVar7 + 0x280) == -1) goto LAB_0055d0ea;
          }
          else if (param_8 == 100) {
            bVar8 = *(char *)(iVar7 + 0x280) == -1;
            goto LAB_0055cfc9;
          }
        }
        if ((((param_2 == 0) || (iVar7 != param_2)) &&
            ((param_3 == 0 || ((*(uint *)(*(int *)(iVar7 + 0x54) + 4) & param_3) == param_3)))) &&
           (((param_6 == -1 || (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + param_6 * 4) != 0)
             ) && ((param_11 == (code *)0x0 || (iVar5 = (*param_11)(iVar7), iVar5 != 0)))))) {
          fVar2 = *(float *)(iVar7 + 0x80) - *param_1;
          fVar3 = *(float *)(iVar7 + 0x84) - param_1[1];
          fVar4 = *(float *)(iVar7 + 0x88) - param_1[2];
          if (param_10 == 0) {
            fVar2 = fVar3 * fVar3 + fVar2 * fVar2;
          }
          else {
            fVar2 = fVar2 * fVar2;
          }
          fVar2 = fVar2 + fVar4 * fVar4;
          if (param_2 == 0) {
            fVar3 = fVar1;
            if (fVar1 > 0.0) goto joined_r0x0055d0e6;
LAB_0055d0c3:
            iVar6 = iVar7;
            if (fVar2 < param_4) goto LAB_0055d0ea;
          }
          else if ((fVar1 <= 0.0) || (fVar2 < fVar1)) {
            fVar3 = *(float *)(iVar7 + 0xac) + *(float *)(param_2 + 0xac) + param_5;
            fVar3 = fVar3 * fVar3;
joined_r0x0055d0e6:
            if (fVar2 < fVar3) goto LAB_0055d0c3;
          }
          fVar2 = param_4;
          iVar6 = local_10;
        }
      }
LAB_0055d0ea:
      local_10 = iVar6;
      param_4 = fVar2;
      local_8 = local_8 + 1;
      iVar7 = iVar7 + 0x10d8;
    } while (local_8 < DAT_0093d500);
    iVar6 = local_10;
    if ((local_10 != 0) && (param_9 != (float *)0x0)) {
      *param_9 = param_4;
    }
  }
  return iVar6;
}

