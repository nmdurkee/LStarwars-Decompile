/* Ghidra pseudocode, not original source.
 * ev_d4a7937fff77c5bbe199b0bfbeb7b7598feaf173902b06fa34e0deca16dde16c
 * Entry: 0x690180; label: FUN_00690180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00690180(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float10 fVar7;
  float local_8;
  float local_4;
  
  if ((DAT_02962050 == 0) && (DAT_008104b4 != 0)) {
    FUN_00684ee0(param_1,param_2,*param_3,param_3[1],param_3[2]);
    if (*param_1 != -1) {
      *(undefined4 *)(*param_1 * 0x330 + 0x1d4 + DAT_029620a4) = param_6;
      fVar1 = _DAT_0296205c;
      if (*(char *)(*(int *)(DAT_0296209c + param_2 * 4) + 0x2f1) == '\x04') {
        fVar1 = _DAT_02962060;
      }
      *(undefined2 *)(*param_1 * 0x330 + 0x1d8 + DAT_029620a4) = 0;
      iVar4 = *param_1 * 0x330;
      fVar1 = *(float *)(iVar4 + 0x1e0 + DAT_029620a4) - fVar1;
      *(float *)(iVar4 + 0x1e0 + DAT_029620a4) = *(float *)(iVar4 + 0x1e0 + DAT_029620a4) - fVar1;
      *(float *)(*param_1 * 0x330 + 0x1e4 + DAT_029620a4) =
           *(float *)(*param_1 * 0x330 + 0x1e4 + DAT_029620a4) - fVar1;
      iVar4 = DAT_029620a4 + *param_1 * 0x330;
      *(undefined4 *)(iVar4 + 0x324) = *(undefined4 *)(iVar4 + 800);
      *(undefined1 *)(*param_1 * 0x330 + 0x184 + DAT_029620a4) = 1;
      if (DAT_02962080 == 0) {
        local_8 = 0.0;
      }
      else {
        fVar7 = (float10)FUN_005becc0(param_3,DAT_02962080,0);
        local_8 = (float)fVar7;
      }
      *(float *)(*param_1 * 0x330 + 0x31c + DAT_029620a4) = local_8;
      iVar4 = DAT_0296209c;
      iVar6 = *param_1 * 0x330 + DAT_029620a4;
      if (*(char *)(iVar6 + 0x2f5) != '\0') {
        local_4 = 0.0;
        iVar2 = *(int *)(DAT_0296209c + param_2 * 4);
        if (*(float *)(iVar2 + 0x40) == 0.0) {
          if (*(float *)(iVar2 + 0x3c) == 0.0) {
            fVar1 = *(float *)(iVar2 + 0x38);
          }
          else {
            fVar1 = *(float *)(iVar2 + 0x3c);
          }
        }
        else {
          fVar1 = *(float *)(iVar2 + 0x40);
        }
        pfVar5 = (float *)(iVar6 + 0x31c);
        fVar7 = (float10)fVar1;
        if ((float10)*pfVar5 < fVar7) {
          iVar6 = 0;
          do {
            iVar2 = *(int *)(*(int *)(iVar4 + param_2 * 4) + 0x3e0 + iVar6);
            if (iVar2 != -1) {
              fVar7 = (float10)FUN_00650570(iVar2);
            }
            iVar6 = iVar6 + 0xc;
          } while (iVar6 < 0x30);
          pfVar5 = (float *)(*param_1 * 0x330 + 0x31c + DAT_029620a4);
          local_4 = (float)((fVar7 - (float10)*(float *)(*param_1 * 0x330 + 0x31c + DAT_029620a4)) /
                           fVar7);
        }
        if ((float10)*pfVar5 < fVar7) {
          iVar6 = 0;
          do {
            iVar2 = *(int *)(iVar4 + param_2 * 4);
            iVar3 = *(int *)(iVar6 + 0x3e0 + iVar2);
            if ((iVar3 != -1) && (*(int *)(iVar6 + 0x3e4 + iVar2) == 1)) {
              FUN_00650f20(iVar3,param_3,local_4,0x3f800000);
              iVar4 = DAT_0296209c;
            }
            iVar6 = iVar6 + 0xc;
          } while (iVar6 < 0x30);
        }
      }
      if (param_4 != (undefined4 *)0x0) {
        FUN_006559a0(*param_1,*param_4,param_4[1],param_4[2]);
      }
      if (param_5 != (undefined4 *)0x0) {
        FUN_006559f0(*param_1,*param_5,param_5[1],param_5[2]);
      }
    }
  }
  return;
}

