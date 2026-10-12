/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55e660; label: FUN_0055e660
 */

void FUN_0055e660(float *param_1,float param_2,float *param_3,float *param_4,int param_5,int param_6
                 ,float param_7,byte param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  float *pfVar6;
  int iVar7;
  float10 fVar8;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_4;
  
  iVar4 = DAT_0093d500;
  iVar7 = DAT_0093d504;
  if (param_5 != 0) {
    iVar4 = 1;
    iVar7 = param_5;
  }
  if ((param_3 == (float *)0x0) || (pfVar6 = param_3, param_4 == (float *)0x0)) {
    pfVar6 = &local_24;
    param_4 = &local_18;
    local_24 = *param_1 - param_2;
    local_20 = param_1[1] - param_2;
    local_1c = param_1[2] - param_2;
    local_18 = param_2 + *param_1;
    local_14 = param_1[1] + param_2;
    local_10 = param_1[2] + param_2;
  }
  param_3 = (float *)iVar4;
  if (0 < iVar4) {
    do {
      if (((((((iVar7 != param_6) && ((*(uint *)(iVar7 + 0x1fc) & 1) != 0)) &&
             ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
            ((*(char *)(iVar7 + 0x28b) == '\0' && ((*(byte *)(iVar7 + 0xe20) & 0x20) == 0)))) &&
           (((param_8 & 2) == 0 || (*(char *)(iVar7 + 0x281) != '\0')))) &&
          (((((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar7 + 0x7b5) * 0x10 + 8) & 0x40000000) == 0
             && ((*(uint *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)) &&
            (*pfVar6 <= *(float *)(iVar7 + 0x184))) &&
           (((*(float *)(iVar7 + 0x178) <= *param_4 && (pfVar6[2] <= *(float *)(iVar7 + 0x18c))) &&
            (*(float *)(iVar7 + 0x180) <= param_4[2])))))) &&
         (((param_8 & 1) == 0 ||
          ((pfVar6[1] <= *(float *)(iVar7 + 0x188) && (*(float *)(iVar7 + 0x17c) <= param_4[1]))))))
      {
        fVar1 = *(float *)(iVar7 + 0x1dc) + param_2;
        fVar2 = *(float *)(iVar7 + 0x5c) - *param_1;
        fVar3 = *(float *)(iVar7 + 100) - param_1[2];
        if (fVar2 * fVar2 + fVar3 * fVar3 < fVar1 * fVar1) {
          if ((fVar2 == 0.0) && (fVar3 == 0.0)) {
            uVar5 = FUN_0054fa60();
          }
          else {
            uVar5 = FUN_005be2d0(fVar2,fVar3);
          }
          local_4 = *(float *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x1c) * param_7;
          if (1.0 <= local_4) {
            if (3.0 < local_4) {
              local_4 = 3.0;
            }
          }
          else {
            local_4 = 1.0;
          }
          local_c = (float)(&DAT_029899a0)[(uVar5 & 0xffff) >> 1] * local_4;
          local_4 = local_4 * (float)(&DAT_029899a0)[(int)((uVar5 & 0xffff) + 0x4000) >> 1 & 0x7fff]
          ;
          fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(iVar7 + 0x68),local_c,0x41200000);
          *(float *)(iVar7 + 0x68) = (float)fVar8;
          fVar8 = (float10)FUN_0054fb40(*(undefined4 *)(iVar7 + 0x70),local_4,0x41200000);
          *(float *)(iVar7 + 0x70) = (float)fVar8;
        }
      }
      iVar7 = iVar7 + 0x10d8;
      param_3 = (float *)((int)param_3 + -1);
    } while (param_3 != (float *)0x0);
  }
  return;
}

