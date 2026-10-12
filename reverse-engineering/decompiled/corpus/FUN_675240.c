/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x675240; label: FUN_00675240
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00675240(void)

{
  byte *pbVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  int *piVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  float10 fVar14;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  iVar8 = DAT_0292186c;
  local_18 = 0.0;
  local_1c = 0.0;
  local_20 = 0.0;
  piVar11 = DAT_02948edc;
  if (DAT_02948edc == (int *)0x0) {
    piVar11 = (int *)(DAT_0292186c + 0x148);
  }
  fVar2 = *(float *)(DAT_0292186c + 0x50);
  uVar10 = 0;
  local_14 = 0;
  *(undefined1 *)(DAT_0292186c + 0x35) = 0;
  *(undefined4 *)(iVar8 + 0x98) = 0x4479f99a;
  *(undefined1 *)(iVar8 + 0x88) = 0;
  *(undefined2 *)(iVar8 + 0x6c) = 0xffff;
  FUN_00674b30();
  fVar14 = (float10)FUN_005c0240(*(float *)(DAT_0292186c + 0x28) * *(float *)(DAT_0292186c + 0x28) +
                                 *(float *)(DAT_0292186c + 0x30) * *(float *)(DAT_0292186c + 0x30));
  iVar8 = DAT_0292186c;
  *(float *)(DAT_0292186c + 0x3c) = (float)fVar14;
  while( true ) {
    sVar6 = (short)*piVar11;
    while (0 < sVar6) {
      iVar13 = *DAT_0292fc68;
      *(float *)(iVar8 + 0x70) =
           *(float *)(iVar8 + 0x1c) - *(float *)(iVar13 + *(short *)((int)piVar11 + 2) * 0x38);
      *(float *)(iVar8 + 0x74) =
           *(float *)(iVar8 + 0x20) - *(float *)(iVar13 + 4 + *(short *)((int)piVar11 + 2) * 0x38);
      *(float *)(iVar8 + 0x78) =
           *(float *)(iVar8 + 0x24) - *(float *)(iVar13 + 8 + *(short *)((int)piVar11 + 2) * 0x38);
      *(float *)(iVar8 + 0x7c) =
           (*(float *)(iVar8 + 0x28) + *(float *)(iVar8 + 0x1c)) -
           *(float *)(iVar13 + *(short *)((int)piVar11 + 2) * 0x38);
      *(float *)(iVar8 + 0x80) =
           (*(float *)(iVar8 + 0x2c) + *(float *)(iVar8 + 0x20)) -
           *(float *)(iVar13 + 4 + *(short *)((int)piVar11 + 2) * 0x38);
      *(float *)(iVar8 + 0x84) =
           (*(float *)(iVar8 + 0x30) + *(float *)(iVar8 + 0x24)) -
           *(float *)(iVar13 + 8 + *(short *)((int)piVar11 + 2) * 0x38);
      piVar5 = piVar11;
      for (iVar13 = (int)(short)*piVar11; piVar5 = piVar5 + 1, 0 < iVar13; iVar13 = iVar13 + -1) {
        iVar7 = *piVar5;
        bVar4 = false;
        fVar3 = (((*(float *)(iVar8 + 0x84) - *(float *)(iVar7 + 0x20)) * *(float *)(iVar7 + 0x50) +
                 (*(float *)(iVar8 + 0x7c) - *(float *)(iVar7 + 0x18)) * *(float *)(iVar7 + 0x48) +
                 (*(float *)(iVar8 + 0x80) - *(float *)(iVar7 + 0x1c)) * *(float *)(iVar7 + 0x4c)) -
                fVar2) - *(float *)(iVar8 + 0xa4);
        if ((fVar3 < 0.0) &&
           (local_18 = ((*(float *)(iVar8 + 0x78) - *(float *)(iVar7 + 0x20)) *
                        *(float *)(iVar7 + 0x50) +
                       (*(float *)(iVar8 + 0x70) - *(float *)(iVar7 + 0x18)) *
                       *(float *)(iVar7 + 0x48) +
                       (*(float *)(iVar8 + 0x74) - *(float *)(iVar7 + 0x1c)) *
                       *(float *)(iVar7 + 0x4c)) - fVar2, -fVar2 < local_18)) {
          bVar4 = true;
        }
        if (((((*(float *)(iVar7 + 0x58) < 65536.0) &&
              (local_20 = (((*(float *)(iVar8 + 0x84) - *(float *)(iVar7 + 0x44)) *
                            *(float *)(iVar7 + 0x5c) +
                           (*(float *)(iVar8 + 0x7c) - *(float *)(iVar7 + 0x3c)) *
                           *(float *)(iVar7 + 0x54) +
                           (*(float *)(iVar8 + 0x80) - *(float *)(iVar7 + 0x40)) *
                           *(float *)(iVar7 + 0x58)) - fVar2) - *(float *)(iVar8 + 0xa4),
              local_20 < 0.0)) &&
             (local_1c = ((*(float *)(iVar8 + 0x78) - *(float *)(iVar7 + 0x44)) *
                          *(float *)(iVar7 + 0x5c) +
                         (*(float *)(iVar8 + 0x70) - *(float *)(iVar7 + 0x3c)) *
                         *(float *)(iVar7 + 0x54) +
                         (*(float *)(iVar8 + 0x74) - *(float *)(iVar7 + 0x40)) *
                         *(float *)(iVar7 + 0x58)) - fVar2, -fVar2 < local_1c)) || (bVar4)) &&
           (iVar7 = FUN_00674490(local_18,fVar3,local_1c,local_20,iVar7), iVar8 = DAT_0292186c,
           iVar7 != 0)) {
          pbVar1 = (byte *)(DAT_0292186c + 0x88);
          *(short *)(DAT_0292186c + 0x6c) = *(short *)((int)piVar11 + 2);
          local_14 = 1;
          if (((*pbVar1 & 0x10) != 0) && ((*(byte *)(*(int *)(iVar8 + 0x90) + 0x62) & 0x80) != 0)) {
            _DAT_02921834 = *(byte *)(*(int *)(iVar8 + 0x90) + 0x60) + 1;
          }
        }
        uVar10 = local_14;
      }
      piVar11 = piVar5;
      sVar6 = (short)*piVar5;
    }
    sVar6 = (short)*piVar11;
    if (-1 < sVar6) break;
    do {
      uVar9 = (int)sVar6 >> 0x1f;
      piVar11 = piVar11 + (((int)sVar6 ^ uVar9) - uVar9) + 1;
      sVar6 = (short)*piVar11;
    } while (sVar6 < 0);
  }
  iVar13 = 0;
  if (0 < DAT_0292fc64) {
    puVar12 = &DAT_0292166c;
    do {
      local_c = puVar12[-3];
      local_4 = puVar12[-1];
      local_8 = *(float *)(iVar8 + 100) * (float)puVar12[-2] -
                *(float *)(iVar8 + 0x5c) * *(float *)(iVar8 + 0x50);
      FUN_0066fea0(&local_c);
      uVar9 = FUN_006742f0(&local_c,*puVar12);
      iVar13 = iVar13 + 1;
      uVar10 = uVar10 | uVar9;
      puVar12 = puVar12 + 4;
      iVar8 = DAT_0292186c;
    } while (iVar13 < DAT_0292fc64);
  }
  if ((*(char *)(iVar8 + 0x88) != '\0') && (sVar6 = *(short *)(iVar8 + 0x6c), sVar6 != -1)) {
    DAT_02948edc = (int *)0x0;
    if (*(int *)(*DAT_0292fc68 + 0x2c + sVar6 * 0x38) == 1) {
      DAT_0292fb68 = (int)*(short *)(*DAT_0292fc68 + sVar6 * 0x38 + 0x30);
      return uVar10;
    }
  }
  DAT_02948edc = (int *)0x0;
  return uVar10;
}

