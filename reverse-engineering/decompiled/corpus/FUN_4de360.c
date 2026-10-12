/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4de360; label: FUN_004de360
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de360(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float10 fVar12;
  float10 fVar13;
  undefined1 auStack_84 [4];
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  double local_60;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48 [15];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)auStack_84;
  local_64 = param_1;
  iVar3 = FUN_0058a900(DAT_009553d4);
  if (iVar3 == 0) {
    _memset(&DAT_00882bd0,0,0x63f0);
    _DAT_00888edc = DAT_007fff40;
    DAT_00882b10 = FUN_00578750(0x20);
    if ((DAT_00951b50 == 0) &&
       (local_7c = -_DAT_007fff50, fVar1 = _DAT_007fff50, fVar2 = _DAT_007fff64,
       local_7c < _DAT_007fff50 != (local_7c == _DAT_007fff50))) {
      do {
        local_6c = -fVar1;
        if (local_6c < fVar1 != (local_6c == fVar1)) {
          do {
            local_60 = (double)_DAT_007fff5c;
            fVar12 = (float10)FUN_005b9d90(&DAT_00888edc);
            fVar13 = (float10)local_60;
            local_78 = (float)((fVar13 - (fVar13 + fVar13) * fVar12) + (float10)local_7c);
            local_74 = 0.0;
            local_60 = (double)_DAT_007fff5c;
            fVar12 = (float10)FUN_005b9d90(&DAT_00888edc);
            fVar13 = (float10)local_60;
            local_70 = (float)((fVar13 - (fVar13 + fVar13) * fVar12) + (float10)local_6c);
            local_80 = local_78 * local_78 + local_70 * local_70;
            if ((local_80 < _DAT_007fff50 * _DAT_007fff50) &&
               (_DAT_007fff58 * _DAT_007fff58 < local_80)) {
              fVar12 = (float10)FUN_005506f0(0,&local_78,0x40a00000,0);
              local_80 = (float)fVar12;
              if (local_80 != 2e+06) {
                local_74 = local_80;
              }
              uVar4 = FUN_005b9e10(&DAT_00888edc);
              iVar3 = FUN_004de100(local_64,uVar4,local_48,_DAT_007fff50);
              if ((iVar3 != 0) && (DAT_00888ed0 < 0x100)) {
                local_54 = 0;
                iVar3 = (int)DAT_00888ed0;
                local_50 = 0;
                DAT_00888ed0 = DAT_00888ed0 + 1;
                local_4c = _DAT_007fff60;
                iVar8 = iVar3 * 0x60;
                pfVar9 = (float *)(&DAT_00882bd0 + iVar8);
                (&DAT_00882c2c)[iVar3 * 0x18] = (&DAT_00882c2c)[iVar3 * 0x18] & 0xfffffffd;
                *pfVar9 = local_78;
                *(float *)(&DAT_00882bd4 + iVar8) = local_74;
                *(float *)(&DAT_00882bd8 + iVar8) = local_70;
                puVar10 = local_48;
                puVar11 = (undefined4 *)(&DAT_00882bec + iVar8);
                for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *puVar11 = *puVar10;
                  puVar10 = puVar10 + 1;
                  puVar11 = puVar11 + 1;
                }
                uVar4 = FUN_005b9e10(&DAT_00888edc);
                local_68 = uVar4;
                uVar5 = FUN_005b9e10(&DAT_00888edc);
                FUN_005b3620(&local_54,&local_54,uVar5);
                uVar6 = FUN_005b9e10(&DAT_00888edc);
                local_80 = 0.0;
                iVar3 = uVar6 % (uint)(DAT_007fff4c - DAT_007fff48) + DAT_007fff48;
                local_60 = (double)CONCAT44(local_60._4_4_,iVar3);
                if (0 < iVar3) {
                  do {
                    if (0xff < DAT_00888ed0) break;
                    if (local_80 != 0.0) {
                      uVar4 = FUN_005be590(uVar4,(int)(0x10000 / (longlong)iVar3));
                      local_68 = uVar4;
                    }
                    FUN_005b3620(&local_78,&local_54,uVar4);
                    FUN_005b37d0(&local_78,&local_78,pfVar9);
                    iVar7 = FUN_004de100(local_64,uVar4,local_48,_DAT_007fff50);
                    if (iVar7 != 0) {
                      iVar3 = (int)DAT_00888ed0;
                      DAT_00888ed0 = DAT_00888ed0 + 1;
                      iVar7 = iVar3 * 0x60;
                      (&DAT_00882c2c)[iVar3 * 0x18] = (&DAT_00882c2c)[iVar3 * 0x18] | 2;
                      *(float *)(&DAT_00882bd0 + iVar7) = local_78;
                      *(float *)(&DAT_00882bd4 + iVar7) = local_74;
                      puVar10 = local_48;
                      puVar11 = (undefined4 *)(&DAT_00882bec + iVar7);
                      for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
                        *puVar11 = *puVar10;
                        puVar10 = puVar10 + 1;
                        puVar11 = puVar11 + 1;
                      }
                      *(float *)(&DAT_00882bd8 + iVar7) = local_70;
                      *(undefined4 *)(&DAT_00882bdc + iVar7) = local_68;
                      *(float **)(&DAT_00882be8 + iVar7) = pfVar9;
                      *(undefined **)(&DAT_00882be8 + iVar8) = &DAT_00882bd0 + iVar7;
                      iVar3 = local_60._0_4_;
                    }
                    local_80 = (float)((int)local_80 + 1);
                    uVar4 = local_68;
                  } while ((int)local_80 < iVar3);
                }
              }
            }
            local_6c = _DAT_007fff64 + local_6c;
            fVar1 = _DAT_007fff50;
            fVar2 = _DAT_007fff64;
          } while (local_6c < _DAT_007fff50 != (local_6c == _DAT_007fff50));
        }
        local_7c = fVar2 + local_7c;
      } while (local_7c < fVar1 != (local_7c == fVar1));
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_84);
  return;
}

