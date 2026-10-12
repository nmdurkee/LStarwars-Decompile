/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49cfe0; label: FUN_0049cfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0049cfe0(float param_1,float param_2,int param_3)

{
  float fVar1;
  char cVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  int local_28;
  int local_24;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  iVar3 = (int)param_1;
  if (0.0 < *(float *)(*(int *)((int)param_1 + 0xca4) + 0x28)) {
    uVar6 = FUN_0054b3d0(param_1,*(int *)((int)param_1 + 0xca4));
    FUN_005b3620(local_c,&DAT_0080250c,uVar6);
  }
  param_1 = 1e+08;
  local_24 = 0;
  local_28 = 0;
  iVar8 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      fVar4 = param_1;
      iVar5 = local_24;
      if (((((((iVar8 != iVar3) && ((*(uint *)(iVar8 + 0x1fc) & 1) != 0)) &&
             ((*(uint *)(iVar8 + 0x1fc) & 0x1000) != 0)) &&
            ((*(char *)(iVar8 + 0x28b) == '\0' && ((*(byte *)(iVar8 + 0x1f8) & 1) == 0)))) &&
           ((cVar2 = *(char *)(iVar8 + 0x7b5), cVar2 != ';' && ((cVar2 != '9' && (cVar2 != '<'))))))
          && ((*(uint *)(*(int *)(*(int *)(iVar8 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)) &&
         (((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000) == 0 &&
          ((*(int *)(iVar3 + 0xcd0) == 0 || (iVar8 != *(int *)(iVar3 + 0xcd0))))))) {
        fVar9 = (float10)FUN_005b3c50((float *)(iVar8 + 0x5c),(float *)(iVar3 + 0x5c),local_18);
        fVar1 = (float)fVar9;
        if ((fVar1 < param_2 * param_2) &&
           ((*(float *)(*(int *)(iVar3 + 0xca4) + 0x28) <= 0.0 ||
            (0.0 <= local_18[0] * local_c[0] + local_10 * local_4)))) {
          if (param_3 != 0) {
            uVar6 = FUN_005be2d0(*(float *)(iVar8 + 0x5c) - *(float *)(iVar3 + 0x5c),
                                 *(float *)(iVar8 + 100) - *(float *)(iVar3 + 100));
            iVar7 = FUN_00550040(*(undefined2 *)(iVar3 + 0x5a),uVar6);
            if ((iVar7 < -param_3) || (param_3 < iVar7)) goto LAB_0049d1c0;
          }
          fVar4 = fVar1;
          iVar5 = iVar8;
          if (fVar1 < param_1) goto LAB_0049d1c0;
        }
        fVar4 = param_1;
        iVar5 = local_24;
      }
LAB_0049d1c0:
      local_24 = iVar5;
      param_1 = fVar4;
      local_28 = local_28 + 1;
      iVar8 = iVar8 + 0x10d8;
    } while (local_28 < DAT_0093d500);
  }
  _DAT_0087b88c = param_1;
  return local_24;
}

