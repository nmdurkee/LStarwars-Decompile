/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52e9c0; label: FUN_0052e9c0
 */

/* WARNING: Removing unreachable block (ram,0x0052f6da) */
/* WARNING: Removing unreachable block (ram,0x0052f2ff) */
/* WARNING: Removing unreachable block (ram,0x0052eb81) */
/* WARNING: Removing unreachable block (ram,0x0052ebc1) */
/* WARNING: Removing unreachable block (ram,0x0052f65c) */
/* WARNING: Removing unreachable block (ram,0x0052f094) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0052e9c0(undefined4 param_1,int param_2,uint *param_3,int param_4,float *param_5)

{
  undefined4 *puVar1;
  float *pfVar2;
  byte *pbVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  byte bVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  ushort uVar11;
  short sVar12;
  uint uVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  int iVar18;
  int unaff_ESI;
  int iVar19;
  bool bVar20;
  bool bVar21;
  float10 fVar22;
  float local_5c;
  float local_58;
  float fStack_40;
  float local_30;
  undefined4 uStack_2c;
  float local_28;
  float fStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  puVar10 = param_3;
  iVar8 = *(int *)(unaff_ESI + 0x158);
  if (((*(char *)((int)param_3 + 0x17) == *(char *)(iVar8 + 0x78)) || (*(int *)(iVar8 + 0x7c) == 0))
     || ((((*(char *)((int)param_3 + 0x17) = *(char *)(iVar8 + 0x78), *(int *)(param_2 + 0x54) != 0
           && (uVar13 = param_3[1] | *param_3, uVar13 != 0)) &&
          ((param_4 == -1 || (uVar13 = param_3[param_4], uVar13 != 0)))) &&
         (((*(uint *)(unaff_ESI + 500) & uVar13) == 0 || ((uVar13 & 0x98000000) != 0)))))) {
    return 0;
  }
  if ((((*(byte *)(param_2 + 0x1fc) & 0x80) == 0) && (*(char *)(unaff_ESI + 0x13c) != -1)) &&
     (uVar11 = __allshl(), ((ushort)param_3[5] & uVar11) == 0)) {
    puVar9 = *(uint **)(unaff_ESI + 0x15c);
    if (puVar9 == (uint *)0x0) {
      return 0;
    }
    if (puVar9 == param_3) {
      return 0;
    }
    bVar7 = (byte)puVar9[4];
    if (bVar7 == (byte)param_3[4]) {
      iVar14 = (uint)bVar7 * 0x5c + *(int *)(iVar8 + 0x7c);
    }
    else {
      if (bVar7 != *(byte *)((int)param_3 + 0x11)) {
        bVar7 = *(byte *)((int)puVar9 + 0x11);
        if (bVar7 == (byte)param_3[4]) {
          iVar14 = (uint)bVar7 * 0x5c + *(int *)(iVar8 + 0x7c);
          goto LAB_0052eac1;
        }
        if (bVar7 != *(byte *)((int)param_3 + 0x11)) {
          return 0;
        }
      }
      iVar14 = (uint)bVar7 * 0x5c + *(int *)(iVar8 + 0x7c);
    }
LAB_0052eac1:
    if (iVar14 == 0) {
      return 0;
    }
    if ((*(ushort *)(iVar14 + 0x5a) & uVar11) == 0) {
      return 0;
    }
  }
  bVar7 = (byte)param_3[4];
  iVar14 = *(int *)(iVar8 + 0x7c);
  fVar4 = _DAT_00801c88 + *(float *)(param_2 + 0xac);
  iVar18 = (uint)bVar7 * 0x5c + iVar14;
  iVar19 = (uint)*(byte *)((int)param_3 + 0x11) * 0x5c + iVar14;
  bVar20 = *(float *)((uint)bVar7 * 0x5c + 0x10 + iVar14) <= fVar4;
  if (bVar20) {
    local_5c = *(float *)(iVar18 + 0x10);
  }
  else {
    local_5c = *(float *)(iVar18 + 0x10) - *(float *)(param_2 + 0xac);
  }
  bVar21 = *(float *)(iVar19 + 0x10) <= fVar4;
  if (bVar21) {
    fVar4 = *(float *)(iVar19 + 0x10);
  }
  else {
    fVar4 = *(float *)(iVar19 + 0x10) - *(float *)(param_2 + 0xac);
  }
  bVar21 = bVar21 || bVar20;
  if ((*(char *)(iVar18 + 0x2a) != '\0') &&
     ((*(byte *)((bVar7 >> 3) + 0x18 + iVar8) & (byte)(1 << (bVar7 & 7))) == 0)) {
    FUN_0051af40(param_1,iVar8,iVar18);
  }
  if ((*(char *)(iVar19 + 0x2a) != '\0') &&
     ((*(byte *)((*(byte *)((int)param_3 + 0x11) >> 3) + 0x18 + iVar8) &
      (byte)(1 << (*(byte *)((int)param_3 + 0x11) & 7))) == 0)) {
    FUN_0051af40(param_1,iVar8,iVar19);
  }
  puVar1 = (undefined4 *)(param_2 + 0x5c);
  local_c[0] = *(float *)(param_2 + 0x5c) - *(float *)(iVar18 + 4);
  pfVar2 = (float *)(iVar18 + 4);
  local_4 = *(float *)(param_2 + 100) - *(float *)(iVar18 + 0xc);
  FUN_005b3620(&local_30,local_c,-(int)*(short *)((int)param_3 + 0x12));
  if (ABS(fVar4 - local_5c) <= (float)param_3[7]) {
    sVar12 = FUN_00512900((fVar4 - local_5c) / (float)param_3[7]);
    iVar14 = (int)sVar12;
    uStack_20 = uStack_2c;
    fStack_24 = local_30;
    fStack_1c = local_28;
    if (local_30 < 0.0) {
      fStack_24 = -local_30;
    }
    FUN_005b3620(&fStack_24,&fStack_24,-iVar14);
    fVar5 = (float)(&DAT_029899a0)[iVar14 + 0x4000 >> 1 & 0x7fff] * (float)param_3[7];
    if (fStack_1c < 0.0) {
      fVar15 = ABS(*(float *)(iVar18 + 8) - *(float *)(unaff_ESI + 0x150));
      fVar22 = (float10)FUN_005bed80(puVar1,pfVar2,local_18);
      fVar16 = (float)fVar22;
      if ((*(float *)(unaff_ESI + 0x150) < *(float *)(iVar18 + 0x18)) ||
         (*(float *)(iVar18 + 0x20) < *(float *)(unaff_ESI + 0x150))) {
        param_3 = (uint *)(fVar16 - local_5c);
        if ((float)param_3 < fVar15) {
          param_3 = (uint *)fVar15;
        }
      }
      else {
        if (fVar16 <= local_5c) {
          *(ushort *)(unaff_ESI + 0x166) =
               (byte)(bVar21 * '\b' ^ *(byte *)(unaff_ESI + 0x166)) & 8 ^
               *(ushort *)(unaff_ESI + 0x166) | 1;
          FUN_0051b890();
          *(float *)(unaff_ESI + 0x168) = local_28 / (float)param_3[7];
          *(float *)(unaff_ESI + 0x16c) = local_30;
          *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
          *(undefined4 *)(unaff_ESI + 0x174) = *(undefined4 *)(param_2 + 0x60);
          *(undefined4 *)(unaff_ESI + 0x178) = *(undefined4 *)(param_2 + 100);
          pbVar3 = (byte *)((byte)((byte)param_3[4] >> 3) + 0x58 + iVar8);
          *pbVar3 = *pbVar3 | '\x01' << ((byte)param_3[4] & 7);
          *(ushort *)(unaff_ESI + 0x124) = (ushort)(byte)param_3[4];
          return 1;
        }
        param_3 = (uint *)(fVar16 - local_5c);
      }
      if ((float)param_3 < *param_5) {
        *param_5 = (float)param_3;
        FUN_0051b890();
        *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
        *(float *)(unaff_ESI + 0x16c) = local_30;
        if (local_5c < fVar16) {
          fVar15 = (local_18[0] * local_5c) / fVar16;
          *(float *)(unaff_ESI + 0x170) = fVar15;
          *(float *)(unaff_ESI + 0x170) = fVar15 + *pfVar2;
          fVar16 = (local_10 * local_5c) / fVar16;
          *(float *)(unaff_ESI + 0x178) = fVar16;
          fVar16 = fVar16 + *(float *)(iVar18 + 0xc);
        }
        else {
          *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
          fVar16 = *(float *)(param_2 + 100);
        }
        *(float *)(unaff_ESI + 0x178) = fVar16;
        uVar6 = *(undefined4 *)(iVar18 + 8);
        *(undefined2 *)(unaff_ESI + 0x124) = 0xffff;
        *(undefined4 *)(unaff_ESI + 0x174) = uVar6;
      }
      if (fStack_1c <= fVar5) {
        return 0;
      }
    }
    if (fStack_1c <= fVar5) {
      if (local_5c <= local_28) {
        if (local_28 <= (float)puVar10[7] - fVar4) {
          fVar22 = (float10)FUN_005128a0(local_28 - local_5c,(float)puVar10[7] - (local_5c + fVar4))
          ;
          fVar16 = (float)fVar22;
          fVar15 = 1.0 - fVar16;
          fStack_40 = *(float *)(iVar18 + 8) * fVar15 + *(float *)(iVar19 + 8) * fVar16;
          param_3 = (uint *)(*(float *)(iVar18 + 0x18) * fVar15 + *(float *)(iVar19 + 0x18) * fVar16
                            );
          local_58 = fVar15 * *(float *)(iVar18 + 0x20) + *(float *)(iVar19 + 0x20) * fVar16;
        }
        else {
          fStack_40 = *(float *)(iVar19 + 8);
          param_3 = *(uint **)(iVar19 + 0x18);
          local_58 = *(float *)(iVar19 + 0x20);
        }
      }
      else {
        fStack_40 = *(float *)(iVar18 + 8);
        param_3 = *(uint **)(iVar18 + 0x18);
        local_58 = *(float *)(iVar18 + 0x20);
        if ((float)puVar10[7] - fVar4 < local_28) {
          if (*(float *)(iVar19 + 0x18) < (float)param_3) {
            param_3 = *(uint **)(iVar19 + 0x18);
          }
          if (local_58 < *(float *)(iVar19 + 0x20)) {
            local_58 = *(float *)(iVar19 + 0x20);
          }
        }
      }
      fVar16 = ABS(fStack_40 - *(float *)(unaff_ESI + 0x150));
      if ((fVar16 <= 0.0) ||
         (((float)param_3 <= *(float *)(unaff_ESI + 0x150) &&
          (*(float *)(unaff_ESI + 0x150) <= local_58)))) {
        if (fStack_24 < local_5c) {
          *(ushort *)(unaff_ESI + 0x166) =
               (byte)(bVar21 * '\b' ^ *(byte *)(unaff_ESI + 0x166)) & 8 ^
               *(ushort *)(unaff_ESI + 0x166) | 1;
          FUN_0051b890();
          *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
          *(float *)(unaff_ESI + 0x16c) = local_30;
          *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
          *(undefined4 *)(unaff_ESI + 0x174) = *(undefined4 *)(param_2 + 0x60);
          *(undefined4 *)(unaff_ESI + 0x178) = *(undefined4 *)(param_2 + 100);
          *(undefined2 *)(unaff_ESI + 0x124) = 0xffff;
          if (local_5c <= local_28) {
            if ((fVar5 - fVar4 < local_28) &&
               (fVar22 = (float10)FUN_005b3cf0(puVar1,iVar19 + 4,local_18),
               fVar22 <= (float10)fVar4 * (float10)fVar4)) {
              pbVar3 = (byte *)((*(byte *)((int)puVar10 + 0x11) >> 3) + 0x58 + iVar8);
              *pbVar3 = *pbVar3 | '\x01' << (*(byte *)((int)puVar10 + 0x11) & 7);
              *(ushort *)(unaff_ESI + 0x124) = (ushort)*(byte *)((int)puVar10 + 0x11);
              return 1;
            }
          }
          else {
            fVar22 = (float10)FUN_005b3cf0(puVar1,pfVar2,local_18);
            if (fVar22 <= (float10)local_5c * (float10)local_5c) {
              pbVar3 = (byte *)((byte)((byte)puVar10[4] >> 3) + 0x58 + iVar8);
              *pbVar3 = *pbVar3 | '\x01' << ((byte)puVar10[4] & 7);
              *(ushort *)(unaff_ESI + 0x124) = (ushort)(byte)puVar10[4];
              return 1;
            }
          }
          return 1;
        }
        param_3 = (uint *)(fStack_24 - local_5c);
      }
      else {
        param_3 = (uint *)(fStack_24 - local_5c);
        if ((float)param_3 < fVar16) {
          param_3 = (uint *)fVar16;
        }
      }
      if (*param_5 <= (float)param_3) {
        return 0;
      }
      *param_5 = (float)param_3;
      FUN_0051b890();
      *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
      *(float *)(unaff_ESI + 0x16c) = local_30;
      if (local_5c <= fStack_24) {
        fStack_24 = local_5c;
        FUN_005b3620(&fStack_24,&fStack_24,iVar14);
        if (local_30 < 0.0) {
          fStack_24 = -fStack_24;
        }
        FUN_005b3620(&fStack_24,&fStack_24,(int)*(short *)((int)puVar10 + 0x12));
        *(float *)(unaff_ESI + 0x170) = fStack_24 + *pfVar2;
        fStack_1c = *(float *)(iVar18 + 0xc) + fStack_1c;
      }
      else {
        *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
        fStack_1c = *(float *)(param_2 + 100);
      }
      goto LAB_0052f7dc;
    }
    fVar16 = ABS(*(float *)(iVar19 + 8) - *(float *)(unaff_ESI + 0x150));
    fVar22 = (float10)FUN_005bed80(puVar1,iVar19 + 4,local_18);
    fVar5 = (float)fVar22;
    if ((*(float *)(unaff_ESI + 0x150) < *(float *)(iVar19 + 0x18)) ||
       (*(float *)(iVar19 + 0x20) < *(float *)(unaff_ESI + 0x150))) {
      param_3 = (uint *)(fVar5 - fVar4);
      if ((float)param_3 < fVar16) {
        param_3 = (uint *)fVar16;
      }
    }
    else {
      if (fVar5 <= fVar4) {
        *(ushort *)(unaff_ESI + 0x166) =
             (byte)(bVar21 * '\b' ^ *(byte *)(unaff_ESI + 0x166)) & 8 ^
             *(ushort *)(unaff_ESI + 0x166) | 1;
        FUN_0051b890();
        *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
        *(float *)(unaff_ESI + 0x16c) = local_30;
        *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
        *(undefined4 *)(unaff_ESI + 0x174) = *(undefined4 *)(param_2 + 0x60);
        *(undefined4 *)(unaff_ESI + 0x178) = *(undefined4 *)(param_2 + 100);
        pbVar3 = (byte *)((*(byte *)((int)puVar10 + 0x11) >> 3) + 0x58 + iVar8);
        *pbVar3 = *pbVar3 | '\x01' << (*(byte *)((int)puVar10 + 0x11) & 7);
        *(ushort *)(unaff_ESI + 0x124) = (ushort)*(byte *)((int)puVar10 + 0x11);
        return 1;
      }
      param_3 = (uint *)(fVar5 - fVar4);
    }
    if (*param_5 <= (float)param_3) {
      return 0;
    }
    *param_5 = (float)param_3;
    FUN_0051b890();
    *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
    *(float *)(unaff_ESI + 0x16c) = local_30;
    if (fVar4 < fVar5) {
      fVar16 = (local_18[0] * fVar4) / fVar5;
      *(float *)(unaff_ESI + 0x170) = fVar16;
      *(float *)(unaff_ESI + 0x170) = fVar16 + *(float *)(iVar19 + 4);
      fStack_1c = (fVar4 * local_10) / fVar5;
      *(float *)(unaff_ESI + 0x178) = fStack_1c;
      fStack_1c = fStack_1c + *(float *)(iVar19 + 0xc);
      iVar18 = iVar19;
      goto LAB_0052f7dc;
    }
  }
  else {
    if (local_5c < fVar4) {
      iVar18 = iVar19;
      local_5c = fVar4;
    }
    fVar16 = ABS(*(float *)(iVar18 + 8) - *(float *)(unaff_ESI + 0x150));
    fVar22 = (float10)FUN_005bed80(puVar1,iVar18 + 4,local_18);
    fVar5 = (float)fVar22;
    if ((*(float *)(unaff_ESI + 0x150) < *(float *)(iVar18 + 0x18)) ||
       (*(float *)(iVar18 + 0x20) < *(float *)(unaff_ESI + 0x150))) {
      param_3 = (uint *)(fVar5 - local_5c);
      if ((float)param_3 < fVar16) {
        param_3 = (uint *)fVar16;
      }
    }
    else {
      if (fVar5 <= local_5c) {
        *(ushort *)(unaff_ESI + 0x166) =
             (byte)(bVar21 * '\b' ^ *(byte *)(unaff_ESI + 0x166)) & 8 ^
             *(ushort *)(unaff_ESI + 0x166) | 1;
        FUN_0051b890();
        *(float *)(unaff_ESI + 0x168) = local_28 / (float)param_3[7];
        *(float *)(unaff_ESI + 0x16c) = local_30;
        *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
        *(undefined4 *)(unaff_ESI + 0x174) = *(undefined4 *)(param_2 + 0x60);
        *(undefined4 *)(unaff_ESI + 0x178) = *(undefined4 *)(param_2 + 100);
        uVar13 = (iVar18 - *(int *)(iVar8 + 0x7c)) / 0x5c;
        pbVar3 = (byte *)(((int)(uVar13 + ((int)uVar13 >> 0x1f & 7U)) >> 3) + 0x58 + iVar8);
        uVar17 = uVar13 & 0x80000007;
        if ((int)uVar17 < 0) {
          uVar17 = (uVar17 - 1 | 0xfffffff8) + 1;
        }
        *pbVar3 = *pbVar3 | '\x01' << ((byte)uVar17 & 0x1f);
        *(short *)(unaff_ESI + 0x124) = (short)uVar13;
        fVar22 = (float10)FUN_005b3cf0(puVar1,iVar19 + 4,local_18);
        if (fVar22 <= (float10)fVar4 * (float10)fVar4) {
          uVar13 = (iVar19 - *(int *)(iVar8 + 0x7c)) / 0x5c;
          uVar17 = uVar13 & 0x80000007;
          pbVar3 = (byte *)(((int)(uVar13 + ((int)uVar13 >> 0x1f & 7U)) >> 3) + 0x58 + iVar8);
          if ((int)uVar17 < 0) {
            uVar17 = (uVar17 - 1 | 0xfffffff8) + 1;
          }
          *pbVar3 = *pbVar3 | '\x01' << ((byte)uVar17 & 0x1f);
          *(short *)(unaff_ESI + 0x124) = (short)uVar13;
        }
        return 1;
      }
      param_3 = (uint *)(fVar5 - local_5c);
    }
    if (*param_5 <= (float)param_3) {
      return 0;
    }
    *param_5 = (float)param_3;
    FUN_0051b890();
    *(float *)(unaff_ESI + 0x168) = local_28 / (float)puVar10[7];
    *(float *)(unaff_ESI + 0x16c) = local_30;
    iVar19 = iVar18;
    if (local_5c < fVar5) {
      fVar4 = (local_18[0] * local_5c) / fVar5;
      *(float *)(unaff_ESI + 0x170) = fVar4;
      *(float *)(unaff_ESI + 0x170) = fVar4 + *(float *)(iVar18 + 4);
      fVar5 = (local_5c * local_10) / fVar5;
      *(float *)(unaff_ESI + 0x178) = fVar5;
      fStack_1c = fVar5 + *(float *)(iVar18 + 0xc);
      goto LAB_0052f7dc;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x170) = *puVar1;
  fStack_1c = *(float *)(param_2 + 100);
  iVar18 = iVar19;
LAB_0052f7dc:
  *(float *)(unaff_ESI + 0x178) = fStack_1c;
  *(undefined4 *)(unaff_ESI + 0x174) = *(undefined4 *)(iVar18 + 8);
  *(undefined2 *)(unaff_ESI + 0x124) = 0xffff;
  return 0;
}

