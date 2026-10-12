/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49a8f0; label: FUN_0049a8f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049a8f0(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  float10 fVar13;
  float local_1c;
  
  iVar8 = FUN_0055f450();
  iVar3 = *(int *)(param_1 + 0xca4);
  local_1c = *(float *)(iVar3 + 0x2c);
  uVar11 = 0;
  uVar7 = 0;
  if (((*(char *)(param_1 + 0x280) != -1) && (DAT_0087b014 != 0)) &&
     (*(int *)(iVar8 + 300) == DAT_0087b014)) {
    if (*(float *)(param_1 + 0xc44) != 0.0) {
      if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b090) && (DAT_00882410 != 1)) &&
          ((_DAT_00950780 != 0.0 || (DAT_00855de0 != 0)))) &&
         ((*(char *)(param_1 + 0x671) != -1 && (*(float *)(param_1 + 0x69c) < 20.0)))) {
        local_1c = -0.625;
      }
      iVar8 = (int)*(char *)(param_1 + 0x280);
      if (iVar8 < 2) {
        fVar13 = (float10)FUN_0054fad0((&DAT_0087b8f4)[iVar8],local_1c,
                                       _DAT_007fc034 * _DAT_00925018 * ABS(local_1c));
        (&DAT_0087b8f4)[iVar8] = (float)fVar13;
        fVar13 = (float10)FUN_0054fad0((float)fVar13,0,_DAT_007fc038 * _DAT_00925018);
        (&DAT_0087b8f4)[iVar8] = (float)fVar13;
        fVar13 = (float10)FUN_0054fb40((&DAT_0087b8ec)[iVar8],(float)fVar13,0x41000000);
        (&DAT_0087b8ec)[iVar8] = (float)fVar13;
      }
      fVar5 = 0.0;
      *(undefined1 *)(param_1 + 0x107a) = 2;
      if (*(char *)(param_1 + 0x671) != -1) {
        uVar7 = *(undefined2 *)(param_1 + 0x7ce);
      }
      if (*(float *)(param_1 + 0x21c) == 2e+06) {
        uVar12 = 0;
      }
      else {
        fVar4 = *(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c);
        if (0.5 <= fVar4) {
          if (fVar4 < 1.5) {
            fVar5 = 1.0 - (fVar4 - 0.5);
          }
        }
        else {
          fVar5 = 1.0;
        }
        FUN_0054fec0(param_1 + 0xf24,0,0);
        iVar9 = FUN_00550040(0,DAT_0092b0c4);
        uVar11 = (int)ROUND((float)iVar9 * fVar5) & 0xffff;
        iVar9 = FUN_00550040(0,DAT_0092b0c0);
        uVar12 = (int)ROUND((float)iVar9 * fVar5) & 0xffff;
      }
      uVar6 = FUN_00550070(*(undefined2 *)(param_1 + 0x278),uVar11,0x41000000);
      *(undefined2 *)(param_1 + 0x278) = uVar6;
      uVar6 = FUN_00550070(*(undefined2 *)(param_1 + 0x27c),uVar12,0x41000000);
      *(undefined2 *)(param_1 + 0x27c) = uVar6;
      if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
        *(undefined4 *)(param_1 + 0xf20) = 0;
        pfVar1 = (float *)(param_1 + 0xf18);
        *(undefined4 *)(param_1 + 0xf1c) = 0;
        *pfVar1 = 0.0;
        if (*(char *)(param_1 + 0x671) != -1) {
          if (iVar8 < 2) {
            *pfVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c) *
                      (float)(&DAT_0087b8ec)[iVar8];
            *(undefined4 *)(param_1 + 0xf1c) = 0;
          }
          else {
            *pfVar1 = *(float *)(iVar3 + 0x28) * local_1c;
            *(undefined4 *)(param_1 + 0xf1c) = 0;
          }
        }
        FUN_00499300(param_1,1,1,1);
        if (((*pfVar1 != 0.0) || (*(float *)(param_1 + 0xf1c) != 0.0)) ||
           (*(float *)(param_1 + 0xf20) != 0.0)) {
          FUN_005b3620(pfVar1,pfVar1,uVar7);
        }
        if (*(char *)(param_1 + 0x671) != -1) {
          FUN_00499be0(param_1);
        }
        uVar2 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x44);
        fVar13 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x68),*pfVar1,uVar2);
        *(float *)(param_1 + 0x68) = (float)fVar13;
        fVar13 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x70),
                                       *(undefined4 *)(param_1 + 0xf20),uVar2);
        *(float *)(param_1 + 0x70) = (float)fVar13;
      }
      else {
        FUN_00499170(param_1,1,0);
      }
      uVar10 = FUN_005be2d0(*(undefined4 *)(param_1 + 0xf18),*(undefined4 *)(param_1 + 0xf20));
      uVar2 = _DAT_007fc03c;
      *(short *)(param_1 + 0x5a) = (short)uVar10;
      uVar7 = FUN_00550070(*(undefined2 *)(param_1 + 0x58),uVar10,uVar2);
      *(undefined2 *)(param_1 + 0x27a) = uVar7;
      *(undefined2 *)(param_1 + 0x58) = uVar7;
      return 1;
    }
    return 1;
  }
  return 0;
}

