/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51b1f0; label: FUN_0051b1f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0051b31d) */
/* WARNING: Removing unreachable block (ram,0x0051b357) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0051b1f0(undefined4 param_1,float *param_2,int param_3,int param_4,undefined4 param_5,
            int param_6,int param_7,undefined4 param_8,int param_9,float param_10,float param_11)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  float fVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  float10 fVar13;
  float local_30;
  undefined4 uStack_2c;
  float local_28;
  float fStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float local_18 [2];
  float local_10;
  undefined1 auStack_c [12];
  
  if (param_11 != 0.0) {
    if (*(char *)(param_4 + 0x17) == *(char *)(param_3 + 0x78)) {
      return 0;
    }
    *(char *)(param_4 + 0x17) = *(char *)(param_3 + 0x78);
  }
  if (((param_7 != 0xff) && (param_6 != 0)) &&
     (uVar5 = __allshl(), (*(ushort *)(param_4 + 0x14) & uVar5) == 0)) {
    bVar3 = *(byte *)(param_6 + 0x10);
    uVar7 = (uint)bVar3;
    if ((bVar3 != *(byte *)(param_4 + 0x10)) && (bVar3 != *(byte *)(param_4 + 0x11))) {
      bVar3 = *(byte *)(param_6 + 0x11);
      uVar7 = (uint)bVar3;
      if ((bVar3 != *(byte *)(param_4 + 0x10)) && (bVar3 != *(byte *)(param_4 + 0x11))) {
        return 0;
      }
    }
    iVar8 = uVar7 * 0x5c + *(int *)(param_3 + 0x7c);
    if (iVar8 == 0) {
      return 0;
    }
    if ((*(ushort *)(iVar8 + 0x5a) & uVar5) == 0) {
      return 0;
    }
  }
  bVar3 = *(byte *)(param_4 + 0x10);
  fVar2 = param_10 + _DAT_00801c88;
  iVar8 = *(int *)(param_3 + 0x7c);
  iVar10 = (uint)bVar3 * 0x5c + iVar8;
  iVar9 = (uint)*(byte *)(param_4 + 0x11) * 0x5c + iVar8;
  bVar11 = *(float *)((uint)bVar3 * 0x5c + 0x10 + iVar8) <= fVar2;
  if (bVar11) {
    fVar1 = *(float *)(iVar10 + 0x10);
  }
  else {
    fVar1 = *(float *)(iVar10 + 0x10) - param_10;
  }
  bVar12 = *(float *)(iVar9 + 0x10) <= fVar2;
  if (bVar12) {
    param_10 = *(float *)(iVar9 + 0x10);
  }
  else {
    param_10 = *(float *)(iVar9 + 0x10) - param_10;
  }
  bVar12 = bVar12 || bVar11;
  if ((*(char *)(iVar10 + 0x2a) != '\0') &&
     ((*(byte *)((bVar3 >> 3) + 0x18 + param_3) & (byte)(1 << (bVar3 & 7))) == 0)) {
    FUN_0051af40(param_1,param_3,iVar10);
  }
  if ((*(char *)(iVar9 + 0x2a) != '\0') &&
     ((*(byte *)((*(byte *)(param_4 + 0x11) >> 3) + 0x18 + param_3) &
      (byte)(1 << (*(byte *)(param_4 + 0x11) & 7))) == 0)) {
    FUN_0051af40(param_1,param_3,iVar9);
  }
  local_18[0] = *param_2 - *(float *)(iVar10 + 4);
  local_10 = param_2[2] - *(float *)(iVar10 + 0xc);
  FUN_005b3620(&local_30,local_18,-(int)*(short *)(param_4 + 0x12));
  if (ABS(param_10 - fVar1) <= *(float *)(param_4 + 0x1c)) {
    fVar2 = local_30;
    if (local_30 < 0.0) {
      fVar2 = -local_30;
    }
    if (((fVar1 < fVar2) && (param_10 < fVar2)) || (local_28 < -fVar1)) {
      return 0;
    }
    if (local_28 <= *(float *)(param_4 + 0x1c) + param_10) {
      sVar6 = FUN_00512900((param_10 - fVar1) / *(float *)(param_4 + 0x1c));
      fStack_24 = local_30;
      fStack_1c = local_28;
      uStack_20 = uStack_2c;
      if (local_30 < 0.0) {
        fStack_24 = -local_30;
      }
      FUN_005b3620(&fStack_24,&fStack_24,-(int)sVar6);
      if (fStack_1c < 0.0) {
        if (((*(float *)(iVar10 + 0x18) <= param_2[1]) && (param_2[1] <= *(float *)(iVar10 + 0x20)))
           && (fVar13 = (float10)FUN_005b3cf0(param_2,iVar10 + 4,auStack_c),
              fVar13 <= (float10)fVar1 * (float10)fVar1)) {
          if (param_9 != 0) {
            *(undefined1 *)(param_9 + 8) = 0;
            *(int *)(param_9 + 4) = param_4;
            *(ushort *)(param_9 + 0xe) =
                 (byte)(bVar12 * '\b' ^ *(byte *)(param_9 + 0xe)) & 8 ^ *(ushort *)(param_9 + 0xe) |
                 1;
            *(float *)(param_9 + 0x10) = local_28 / *(float *)(param_4 + 0x1c);
            *(float *)(param_9 + 0x14) = local_30;
          }
          return 1;
        }
      }
      else if ((float)(&DAT_029899a0)[sVar6 + 0x4000 >> 1 & 0x7fff] * *(float *)(param_4 + 0x1c) <
               fStack_1c) {
        if (((*(float *)(iVar9 + 0x18) <= param_2[1]) && (param_2[1] <= *(float *)(iVar9 + 0x20)))
           && (fVar13 = (float10)FUN_005b3cf0(param_2,iVar9 + 4,auStack_c),
              fVar13 <= (float10)param_10 * (float10)param_10)) goto LAB_0051b681;
      }
      else {
        if (fVar1 <= local_28) {
          if (local_28 <= *(float *)(param_4 + 0x1c) - param_10) {
            fVar2 = (local_28 - fVar1) / (*(float *)(param_4 + 0x1c) - (fVar1 + param_10));
            param_11 = *(float *)(iVar10 + 0x18) * (1.0 - fVar2) + *(float *)(iVar9 + 0x18) * fVar2;
            fVar2 = (1.0 - fVar2) * *(float *)(iVar10 + 0x20) + *(float *)(iVar9 + 0x20) * fVar2;
          }
          else {
            param_11 = *(float *)(iVar9 + 0x18);
            fVar2 = *(float *)(iVar9 + 0x20);
          }
        }
        else {
          param_11 = *(float *)(iVar10 + 0x18);
          fVar2 = *(float *)(iVar10 + 0x20);
        }
        if (((param_11 <= param_2[1]) && (param_2[1] <= fVar2)) && (fStack_24 < fVar1)) {
          if (param_9 == 0) {
            return 1;
          }
          *(int *)(param_9 + 4) = param_4;
          *(undefined1 *)(param_9 + 8) = 0;
          *(ushort *)(param_9 + 0xe) =
               (byte)(bVar12 * '\b' ^ *(byte *)(param_9 + 0xe)) & 8 ^ *(ushort *)(param_9 + 0xe) | 1
          ;
          *(float *)(param_9 + 0x10) = local_28 / *(float *)(param_4 + 0x1c);
          *(float *)(param_9 + 0x14) = local_30;
          return 1;
        }
      }
    }
  }
  else {
    if (fVar1 < param_10) {
      iVar10 = iVar9;
      fVar1 = param_10;
    }
    if (((*(float *)(iVar10 + 0x18) <= param_2[1]) && (param_2[1] <= *(float *)(iVar10 + 0x20))) &&
       (fVar2 = *param_2 - *(float *)(iVar10 + 4), fVar4 = param_2[2] - *(float *)(iVar10 + 0xc),
       fVar2 = fVar2 * fVar2 + fVar4 * fVar4, fVar2 < fVar1 * fVar1 != (fVar2 == fVar1 * fVar1))) {
LAB_0051b681:
      if (param_9 != 0) {
        *(undefined1 *)(param_9 + 8) = 0;
        *(int *)(param_9 + 4) = param_4;
        *(ushort *)(param_9 + 0xe) =
             (byte)(bVar12 * '\b' ^ *(byte *)(param_9 + 0xe)) & 8 ^ *(ushort *)(param_9 + 0xe) | 1;
        *(float *)(param_9 + 0x10) = local_28 / *(float *)(param_4 + 0x1c);
        *(float *)(param_9 + 0x14) = local_30;
      }
      return 1;
    }
  }
  return 0;
}

