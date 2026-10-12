/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50fed0; label: FUN_0050fed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050fed0(undefined4 param_1)

{
  short sVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar7 = DAT_00800944;
  local_8 = 0;
  if (((DAT_00921dec != 0) || (0.0 < _DAT_00921df4)) || (0.0 < _DAT_00921df0)) {
    if (DAT_00921e74 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005100e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_00921e74)();
      return;
    }
  }
  else {
    iVar8 = DAT_00800944 * 0xe0;
    iVar4 = DAT_00800944 * 0x38;
    if ((&DAT_00921454)[DAT_00800944 * 0x70] != -1) {
      DAT_00921d44 = 1;
      iVar6 = DAT_00921ea0;
      if (DAT_00921ea0 == 0) {
        iVar6 = DAT_00921e8c;
      }
      local_c = local_8;
      if (iVar6 != 0) {
        iVar6 = DAT_00921ea0;
        if (DAT_00921ea0 == 0) {
          iVar6 = DAT_00921e8c;
        }
        local_c = *(undefined4 *)(iVar6 + 0x18);
        iVar6 = DAT_00921ea0;
        if (DAT_00921ea0 == 0) {
          iVar6 = DAT_00921e8c;
        }
        *(undefined4 *)(iVar6 + 0x18) = 0;
      }
      if (DAT_00921ea4 != 0) {
        local_8 = *(undefined4 *)(DAT_00921ea4 + 0x18);
        *(undefined4 *)(DAT_00921ea4 + 0x18) = 0;
      }
      iVar6 = DAT_00921ea0;
      sVar1 = (&DAT_0092144e)[iVar7 * 0x70];
      sVar2 = (&DAT_00921452)[iVar7 * 0x70];
      *(undefined4 *)(iVar8 + 0x9214d0) = 0x3f800000;
      *(undefined4 *)(iVar8 + 0x9214e0) = 0;
      *(int *)(&DAT_009214cc + iVar7 * 0x70) = (int)sVar1;
      *(undefined4 *)(iVar8 + 0x9214ec) = param_1;
      pcVar5 = DAT_00921d74;
      bVar9 = DAT_00921d74 != (code *)0x0;
      DAT_009213f8._0_1_ = 0;
      fVar3 = (float)((int)sVar2 - (int)sVar1) * _DAT_00800994 * 0.5;
      *(float *)(iVar8 + 0x9214e4) = fVar3;
      *(undefined4 *)(iVar8 + 0x9214d4) = 0;
      *(float *)(iVar8 + 0x9214d8) = -fVar3;
      *(undefined4 *)(iVar8 + 0x9214dc) = 0x3f800000;
      if (bVar9) {
        (*pcVar5)(&DAT_00921440 + iVar4);
        iVar6 = DAT_00921ea0;
      }
      if ((code *)(&PTR_FUN_00800ab0)[(short)(&DAT_00921454)[iVar7 * 0x70] * 7] != (code *)0x0) {
        (*(code *)(&PTR_FUN_00800ab0)[(short)(&DAT_00921454)[iVar7 * 0x70] * 7])
                  (&DAT_00921440 + iVar4);
        iVar6 = DAT_00921ea0;
      }
      if (PTR_FUN_0080096c != (undefined *)0x0) {
        (*(code *)PTR_FUN_0080096c)();
        iVar6 = DAT_00921ea0;
      }
      if ((0.5 < _DAT_00921d5c != (_DAT_00921d5c == 0.5)) && (DAT_00800960 != 0)) {
        FUN_0050fea0((int)(char)(&DAT_00800ac1)[(short)(&DAT_00921454)[iVar7 * 0x70] * 0x1c],
                     (int)(char)(&DAT_00800ac2)[(short)(&DAT_00921454)[iVar7 * 0x70] * 0x1c],1,
                     DAT_00800998,DAT_00800999,DAT_00921da8,DAT_00921d60);
        iVar6 = DAT_00921ea0;
      }
      iVar7 = iVar6;
      if (iVar6 == 0) {
        iVar7 = DAT_00921e8c;
      }
      if (iVar7 != 0) {
        if (iVar6 == 0) {
          iVar6 = DAT_00921e8c;
        }
        *(undefined4 *)(iVar6 + 0x18) = local_c;
      }
      if (DAT_00921ea4 != 0) {
        *(undefined4 *)(DAT_00921ea4 + 0x18) = local_8;
        return;
      }
    }
  }
  return;
}

