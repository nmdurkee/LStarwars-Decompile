/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49a260; label: FUN_0049a260
 */

undefined4 FUN_0049a260(float param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  undefined4 uVar10;
  short sVar11;
  float10 fVar12;
  
  iVar9 = FUN_0055f450();
  iVar7 = (int)param_1;
  iVar4 = *(int *)((int)param_1 + 0xca4);
  if (*(char *)((int)param_1 + 0x280) == -1) {
    return 0;
  }
  if ((((DAT_0087b0e0 != 0) && (*(int *)(iVar9 + 0x128) == DAT_0087b0e0)) &&
      (*(int *)(iVar9 + 0x2988) != 0)) && (*(char *)((int)param_1 + 0x671) != -1)) {
    *(undefined1 *)((int)param_1 + 0x107a) = 3;
    sVar11 = *(short *)(*(char *)((int)param_1 + 0x671) * 0x13c + 0x6e + **(int **)(iVar9 + 0x2988))
             + *(short *)((int)param_1 + 0x696);
    sVar3 = *(short *)(iVar4 + 0x26);
    *(uint *)((int)param_1 + 0xe20) = *(uint *)((int)param_1 + 0xe20) | 0x200000;
    *(short *)((int)param_1 + 0xe0c) = sVar3 + sVar11;
    *(short *)((int)param_1 + 0x5a) = sVar11;
    uVar8 = FUN_00550070(*(undefined2 *)((int)param_1 + 0x58),sVar11,0x41000000);
    iVar9 = DAT_007fc02c * 0x10000;
    *(undefined2 *)(iVar7 + 0x58) = uVar8;
    *(undefined2 *)(iVar7 + 0x27a) = uVar8;
    param_1 = (float)(iVar9 / 0x168);
    uVar10 = FUN_006e6b90();
    uVar8 = FUN_00550070(*(undefined2 *)(iVar7 + 0xe18),uVar10,0x41000000);
    *(undefined2 *)(iVar7 + 0xe18) = uVar8;
    uVar10 = *(undefined4 *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x44);
    if ((*(char *)(iVar7 + 0x7b5) == '#') || (*(char *)(iVar7 + 0x7b5) == '$')) {
      *(undefined4 *)(iVar7 + 0xf20) = 0;
      *(undefined4 *)(iVar7 + 0xf1c) = 0;
      *(undefined4 *)(iVar7 + 0xf18) = 0;
      uVar2 = 0;
    }
    else {
      if ((*(byte *)(iVar7 + 0xe20) & 0x20) != 0) {
        FUN_00499170(iVar7,0,&param_1);
        if (param_1 == 0.0) {
          return 1;
        }
        uVar8 = *(undefined2 *)((int)param_1 + 0x27a);
        *(undefined2 *)(iVar7 + 0x27a) = uVar8;
        *(undefined2 *)(iVar7 + 0x5a) = uVar8;
        *(undefined2 *)(iVar7 + 0x58) = uVar8;
        *(undefined4 *)(iVar7 + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
        *(undefined4 *)(iVar7 + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
        *(undefined4 *)(iVar7 + 0x70) = *(undefined4 *)((int)param_1 + 0x70);
        uVar10 = *(undefined4 *)((int)param_1 + 0xdc8);
        *(undefined2 *)(iVar7 + 0xe18) = 0;
        *(undefined2 *)(iVar7 + 0xe1c) = 0;
        *(undefined4 *)(iVar7 + 0xdc8) = uVar10;
        *(undefined2 *)(iVar7 + 0xe1a) = 0;
        *(undefined2 *)(iVar7 + 0x27c) = 0;
        *(undefined2 *)(iVar7 + 0x278) = 0;
        return 1;
      }
      *(undefined4 *)(iVar7 + 0xf1c) = 0;
      if ((*(float *)(iVar7 + 0x200) == 0.0) && (*(float *)(iVar7 + 0x208) == 0.0)) {
        pfVar1 = (float *)(iVar7 + 0xf18);
        if (*(float *)(iVar4 + 0x28) <= 0.0) {
          *pfVar1 = 0.0;
        }
        else {
          *pfVar1 = *(float *)(iVar4 + 0x2c) * *(float *)(iVar4 + 0x28);
        }
        *(undefined4 *)(iVar7 + 0xf20) = 0;
        if ((0.0 < *(float *)(iVar7 + 0x1018)) && ((*(byte *)(iVar7 + 0xe26) & 7) != 0)) {
          fVar5 = *(float *)(*(int *)(*(int *)(iVar7 + 0x54) + 0x24) + 0x1c) * 1.5;
          fVar6 = *(float *)(iVar7 + 0x1018) / 0.4;
          if ((*(byte *)(iVar7 + 0xe26) & 7) == 3) {
            fVar6 = *pfVar1 * 0.5 - fVar5 * fVar6;
            *pfVar1 = fVar6;
            param_1 = -fVar5;
            if (fVar6 < param_1) {
              *pfVar1 = param_1;
            }
          }
          else {
            param_1 = *pfVar1 * 0.5 + fVar5 * fVar6;
            *pfVar1 = param_1;
            if (fVar5 < param_1) {
              *pfVar1 = fVar5;
            }
          }
        }
        FUN_00499300(iVar7,1,0,0);
        FUN_005b3620(pfVar1,pfVar1,sVar11);
      }
      else {
        *(undefined4 *)(iVar7 + 0xf18) = *(undefined4 *)(iVar7 + 0x200);
        *(undefined4 *)(iVar7 + 0xf20) = *(undefined4 *)(iVar7 + 0x208);
        *(undefined4 *)(iVar7 + 0x208) = 0;
        *(undefined4 *)(iVar7 + 0x200) = 0;
      }
      FUN_00498d40(iVar7);
      uVar2 = *(undefined4 *)(iVar7 + 0xf18);
    }
    fVar12 = (float10)FUN_0054fb40(*(undefined4 *)(iVar7 + 0x68),uVar2,uVar10);
    *(float *)(iVar7 + 0x68) = (float)fVar12;
    fVar12 = (float10)FUN_0054fb40(*(undefined4 *)(iVar7 + 0x70),*(undefined4 *)(iVar7 + 0xf20),
                                   uVar10);
    *(float *)(iVar7 + 0x70) = (float)fVar12;
    return 1;
  }
  return 0;
}

