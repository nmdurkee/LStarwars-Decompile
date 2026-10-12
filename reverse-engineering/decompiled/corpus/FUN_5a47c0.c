/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a47c0; label: FUN_005a47c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_005a47c0(int param_1,int param_2,float param_3)

{
  ushort uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  ushort uVar11;
  float fVar12;
  int iVar13;
  ushort uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  float local_70;
  undefined4 local_6c;
  float local_58;
  int local_54;
  int local_50;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if ((((param_1 == 0) || (*(int *)(param_1 + 0x46bc) == 0)) || (*(int *)(param_1 + 0x46c0) == 0))
     || ((DAT_0080284c == -1 || (*(char *)(param_2 + 0x7b5) != DAT_0080284c)))) {
    return 0;
  }
  uVar1 = *(ushort *)(param_2 + 0x5a);
  fVar8 = (*(float *)(param_2 + 0x194) - *(float *)(param_2 + 0x1a0)) * 0.25;
  fVar7 = *(float *)(param_2 + 0x194) - fVar8;
  fVar8 = *(float *)(param_2 + 0x1a0) + fVar8;
  if (uVar1 != 0) {
    uVar17 = (uint)DAT_00805b00;
    uVar18 = (uint)uVar1;
    if (((int)uVar18 <= (int)(0x10000 - uVar17)) && ((uVar1 == 0 || (DAT_00805b00 <= uVar1)))) {
      if ((uVar1 == 0x4000) ||
         (((int)(0x4000 - uVar17) < (int)uVar18 && (uVar18 < uVar17 + 0x4000)))) {
        local_6c = 0;
      }
      else if ((uVar1 == 0x8000) ||
              (((int)(0x8000 - uVar17) < (int)uVar18 && (uVar18 < uVar17 + 0x8000)))) {
        local_6c = 3;
      }
      else {
        if ((uVar1 != 0xc000) &&
           (((int)uVar18 <= (int)(0xc000 - uVar17) || (uVar17 + 0xc000 <= uVar18)))) {
          return 0;
        }
        local_6c = 1;
      }
      goto LAB_005a4910;
    }
  }
  local_6c = 2;
LAB_005a4910:
  iVar19 = 0;
  local_58 = 1e+09;
  local_50 = 0;
  local_54 = 0;
  local_70 = 0.0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    do {
      iVar20 = *(int *)(param_1 + 0x46bc) + iVar19;
      iVar16 = iVar20 + 0x24;
      iVar15 = FUN_005cfac0(iVar16);
      fVar12 = local_58;
      iVar13 = local_50;
      if (((iVar15 == 0) ||
          ((iVar15 = FUN_005cfe70(iVar16), iVar15 != 0 &&
           (iVar16 = FUN_005cfd60(iVar16), iVar16 != 0)))) &&
         ((*(uint *)(iVar20 + 200) & 0x6000100) == 0)) {
        fVar2 = *(float *)(iVar20 + 0xb0);
        fVar3 = *(float *)(iVar20 + 0xb8);
        fVar4 = *(float *)(iVar20 + 0xbc);
        fVar9 = *(float *)(*(int *)(iVar20 + 0x58) + 4) + ABS(*(float *)(iVar20 + 0xc0));
        fVar5 = *(float *)(iVar20 + 0xc4);
        fVar10 = *(float *)(*(int *)(iVar20 + 0x58) + 4) - ABS(*(float *)(iVar20 + 0xb4));
        if ((fVar7 < fVar9) && (fVar7 < fVar10)) goto LAB_005a4e09;
        if ((fVar9 < fVar8) && (fVar10 < fVar8)) goto LAB_005a4e0b;
        pfVar6 = *(float **)(iVar20 + 0x58);
        local_c = *pfVar6;
        local_8 = pfVar6[1];
        local_4 = pfVar6[2];
        fVar9 = local_c - *(float *)(param_2 + 0x80);
        local_14 = local_8 - *(float *)(param_2 + 0x84);
        fVar10 = local_4 - *(float *)(param_2 + 0x88);
        local_18 = fVar9;
        local_10 = fVar10;
        switch(local_6c) {
        case 0:
          local_70 = fVar9 - ABS(fVar2);
          if (((((fVar3 + local_4) - _DAT_00805a74 < *(float *)(param_2 + 0x88)) &&
               (fVar2 = (fVar5 + local_4) - _DAT_00805a74,
               fVar2 < *(float *)(param_2 + 0x88) == (fVar2 == *(float *)(param_2 + 0x88)))) &&
              (uVar17 = *(uint *)(iVar20 + 200), (uVar17 & 0x200000) == 0)) &&
             (((uVar17 & 0x100000) == 0 || ((uVar17 & 0x800000) == 0)))) break;
          goto LAB_005a4e09;
        case 1:
          local_70 = ABS(fVar9) - fVar4;
          fVar2 = (fVar5 + local_4) - _DAT_00805a74;
          if (((fVar2 < *(float *)(param_2 + 0x88) != (fVar2 == *(float *)(param_2 + 0x88))) ||
              (*(float *)(param_2 + 0x88) <= (fVar3 + local_4) - _DAT_00805a74)) ||
             (uVar17 = *(uint *)(iVar20 + 200), (uVar17 & 0x200000) != 0)) goto LAB_005a4e09;
          if ((uVar17 & 0x100000) != 0) {
            uVar17 = uVar17 & 0x400000;
joined_r0x005a4c77:
            if (uVar17 != 0) goto LAB_005a4e09;
          }
          break;
        case 2:
          local_70 = fVar10 - ABS(fVar3);
          fVar3 = (fVar4 + local_c) - _DAT_00805a74;
          if (((fVar3 < *(float *)(param_2 + 0x80) != (fVar3 == *(float *)(param_2 + 0x80))) ||
              (*(float *)(param_2 + 0x80) <= (fVar2 + local_c) - _DAT_00805a74)) ||
             (uVar17 = *(uint *)(iVar20 + 200), (uVar17 & 0x100000) != 0)) goto LAB_005a4e09;
          if ((uVar17 & 0x200000) != 0) {
            uVar17 = uVar17 & 0x800000;
            goto joined_r0x005a4c77;
          }
          break;
        case 3:
          local_70 = ABS(fVar10) - fVar5;
          if (((*(float *)(param_2 + 0x80) <= (fVar2 + local_c) - _DAT_00805a74) ||
              (fVar2 = (fVar4 + local_c) - _DAT_00805a74,
              fVar2 < *(float *)(param_2 + 0x80) != (fVar2 == *(float *)(param_2 + 0x80)))) ||
             (uVar17 = *(uint *)(iVar20 + 200), (uVar17 & 0x100000) != 0)) goto LAB_005a4e09;
          if ((uVar17 & 0x200000) != 0) {
            uVar17 = uVar17 & 0x400000;
            goto joined_r0x005a4c77;
          }
        }
        fVar2 = *(float *)(param_2 + 0x1dc) + _DAT_00805a74;
        if (local_70 <= fVar2 + fVar2) {
          uVar14 = FUN_005be2d0(fVar9,fVar10);
          FUN_005b3620(&local_18,&local_18,0x4000 - (uint)uVar14);
          uVar17 = FUN_005be2d0(local_18,local_14);
          uVar14 = uVar14 - *(short *)(param_2 + 0x5a);
          iVar16 = 0x4000 - (uVar17 & 0xffff);
          uVar11 = (ushort)(iVar16 >> 0x1f);
          uVar1 = (short)uVar14 >> 0xf;
          if (((0x2000 < (ushort)((uVar14 ^ uVar1) - uVar1)) ||
              (0x4000 < (ushort)(((ushort)iVar16 ^ uVar11) - uVar11))) ||
             ((local_70 = fVar9 * fVar9 + fVar10 * fVar10, local_70 < param_3 &&
              (fVar12 = local_70, iVar13 = iVar20, local_70 < local_58)))) goto LAB_005a4e0b;
        }
LAB_005a4e09:
        fVar12 = local_58;
        iVar13 = local_50;
      }
LAB_005a4e0b:
      local_50 = iVar13;
      local_58 = fVar12;
      local_54 = local_54 + 1;
      iVar19 = iVar19 + 0xd4;
    } while (local_54 < *(int *)(param_1 + 0x46c0));
  }
  return local_50;
}

