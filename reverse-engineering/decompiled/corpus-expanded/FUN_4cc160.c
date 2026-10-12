/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4cc160; label: FUN_004cc160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004cc259) */
/* WARNING: Removing unreachable block (ram,0x004cc49d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004cc160(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  float local_20;
  uint local_1c;
  float local_c [3];
  
  iVar8 = *param_2;
  iVar12 = 0;
  iVar11 = 0;
  local_1c = 0;
  bVar5 = false;
  if ((*(uint *)(iVar8 + 0xef4) & 0x40000000) != 0) {
    uVar6 = FUN_004cb790(param_1,param_2,param_3);
    return uVar6;
  }
  bVar9 = *(byte *)(param_1 + 0x160);
  iVar7 = *(int *)(param_1 + 0x15c);
  uVar10 = *(uint *)(iVar7 + (uint)bVar9 * 4) & *(uint *)(param_1 + 500);
  if ((*(byte *)(param_1 + 0x166) & 1) == 0) {
LAB_004cc2e6:
    *(undefined1 *)(param_1 + 0x139) = 0;
LAB_004cc2ed:
    if (*(char *)(param_1 + 0x139) == '\0') {
      return 0;
    }
  }
  else {
    iVar12 = *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
    iVar11 = (uint)*(byte *)(iVar7 + 0x10 + (uint)bVar9) * 0x5c + iVar12;
    bVar9 = *(byte *)((bVar9 == 0) + 0x10 + iVar7);
    local_1c = (uint)bVar9;
    iVar12 = local_1c * 0x5c + iVar12;
    fVar13 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar12 + 4,local_c);
    if ((float)fVar13 < *(float *)(iVar12 + 0x14)) goto LAB_004cc2e6;
    iVar7 = *(int *)(param_1 + 0x15c);
    if ((((*(uint *)(iVar7 + (uint)*(byte *)(param_1 + 0x160) * 4) & 0x200) == 0) &&
        ((int)*(short *)(param_1 + 0x124) != local_1c)) &&
       ((*(byte *)(((int)local_1c >> 3) + 0x38 + *(int *)(param_1 + 0x158)) &
        (byte)(1 << (bVar9 & 7))) != 0)) {
      iVar7 = FUN_0043c9a0(iVar8,iVar12,0);
      if (iVar7 != 0) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0x139) = 1;
      goto LAB_004cc2ed;
    }
    if (*(char *)(param_1 + 0x139) == '\0') {
      fVar4 = *(float *)(param_1 + 0x168) * *(float *)(iVar7 + 0x1c);
      *(undefined1 *)(param_1 + 0x139) = 1;
      if (*(char *)(param_1 + 0x160) == '\0') {
        if (*(float *)(iVar7 + 0x1c) - *(float *)(iVar12 + 0x10) < fVar4) goto LAB_004cc2e6;
      }
      else if (fVar4 < *(float *)(iVar11 + 0x10)) goto LAB_004cc2e6;
      goto LAB_004cc2ed;
    }
  }
  local_c[0] = *(float *)(iVar12 + 4) - *(float *)(iVar11 + 4);
  local_c[1] = 0.0;
  local_c[2] = *(float *)(iVar12 + 0xc) - *(float *)(iVar11 + 0xc);
  local_20 = *(float *)(iVar11 + 0x10);
  if (local_20 < 0.0) {
    local_20 = 0.0;
  }
  FUN_005b3830(local_c,local_c,local_20 / *(float *)(*(int *)(param_1 + 0x15c) + 0x1c));
  piVar1 = (int *)(param_1 + 0x104);
  FUN_005b37d0(piVar1,iVar11 + 4,local_c);
  fVar13 = (float10)FUN_005b3cf0(param_2 + 0x17,piVar1,local_c);
  if ((param_3 != 0) &&
     ((((float)fVar13 < _DAT_00801c6c * _DAT_00801c6c || (_DAT_007f673c < *(float *)(iVar8 + 0x1d8))
       ) || (*(char *)(iVar8 + 0x7b5) == 'D')))) {
    *piVar1 = param_2[0x17];
    *(int *)(param_1 + 0x108) = param_2[0x18];
    bVar5 = true;
    *(int *)(param_1 + 0x10c) = param_2[0x19];
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  fVar4 = _DAT_007fcefc;
  if (((uVar10 & 0x20) == 0) && (fVar4 = _DAT_007fcef4, (uVar10 & 2) != 0)) {
    fVar4 = _DAT_007fcef8;
  }
  puVar2 = (uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4);
  if ((*(uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4) & 0x800) != 0) {
    *(uint *)(param_1 + 0x1e8) = *(uint *)(param_1 + 0x1e8) | 0x800000;
    *(undefined1 *)(param_1 + 0x139) = 1;
  }
  switch(*(undefined1 *)(param_1 + 0x139)) {
  case 1:
    if (!bVar5) goto switchD_004cc452_default;
    uVar10 = *puVar2;
    if ((((uVar10 & 0x200) == 0) && ((int)*(short *)(param_1 + 0x124) != local_1c)) &&
       ((*(byte *)(*(int *)(param_1 + 0x158) + 0x38 + ((int)local_1c >> 3)) &
        (byte)(1 << ((byte)local_1c & 7))) != 0)) {
      iVar8 = FUN_0043c9a0(iVar8,iVar12,0);
      if (iVar8 != 0) {
        return 1;
      }
      goto switchD_004cc452_default;
    }
    if ((uVar10 & 0x800) != 0) goto switchD_004cc452_default;
    if ((((uVar10 & 0x400) == 0) &&
        (((*(byte *)(iVar12 + 0x2b) | *(byte *)(iVar11 + 0x2b)) & 2) != 0)) &&
       (iVar8 = FUN_005d0450(iVar11 + 0x40,iVar12 + 0x40), iVar8 == 0)) {
      *(undefined1 *)(param_1 + 0x139) = 2;
      goto switchD_004cc452_default;
    }
    break;
  case 2:
    if ((*puVar2 & 0x400) == 0) {
      fVar13 = (float10)FUN_005becc0(param_2 + 0x17,iVar12 + 4,local_c);
      fVar3 = (float)fVar13;
      if ((((*(byte *)(iVar11 + 0x2b) | *(byte *)(iVar12 + 0x2b)) & 2) != 0) &&
         (fVar3 - *(float *)(iVar12 + 0x10) <= fVar4)) goto switchD_004cc452_default;
      *(undefined1 *)(param_1 + 0x139) = 3;
      if ((*(byte *)(iVar12 + 0x2b) & 2) != 0) {
        *(undefined4 *)(iVar8 + 0xed0) = 0;
        goto switchD_004cc452_default;
      }
LAB_004cc581:
      *(float *)(iVar8 + 0xed0) = fVar3;
      goto switchD_004cc452_default;
    }
    break;
  case 3:
    if ((*puVar2 & 0x400) == 0) {
      fVar13 = (float10)FUN_005becc0(param_2 + 0x17,iVar12 + 4,local_c);
      fVar3 = (float)fVar13;
      bVar9 = (*(byte *)(iVar12 + 0x2b) | *(byte *)(iVar11 + 0x2b)) & 2;
      if ((bVar9 != 0) && (fVar4 <= fVar3 - *(float *)(iVar12 + 0x10)))
      goto switchD_004cc452_default;
      if (bVar9 == 0) {
        *(undefined4 *)(iVar8 + 0xed0) = 0;
      }
      if (*(float *)(iVar8 + 0xed0) < fVar3) {
        *(undefined1 *)(param_1 + 0x139) = 4;
        *(undefined4 *)(iVar8 + 0xed0) = 0;
        goto switchD_004cc452_default;
      }
      goto LAB_004cc581;
    }
    break;
  case 4:
    if ((*puVar2 & 0x22) != 0) {
      if (*(float *)(iVar8 + 0xd28) <= 0.0) {
        *(undefined1 *)(param_1 + 0x139) = 5;
        *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) | 0x1000;
      }
      goto switchD_004cc452_default;
    }
    *(undefined1 *)(param_1 + 0x139) = 5;
    *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) & 0xffffefff;
  case 5:
    iVar11 = FUN_0043c9a0(iVar8,iVar12,0);
    if (iVar11 != 0) {
      return 1;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x15c) + (uint)*(byte *)(param_1 + 0x160) * 4) & 0x200) == 0)
       && (iVar7 = 0, iVar11 = DAT_0093d504, 0 < DAT_0093d500)) {
      do {
        if ((((*(uint *)(iVar11 + 0x1fc) & 1) != 0) &&
            (((iVar11 != iVar8 && ((*(uint *)(iVar11 + 0x1fc) & 0x1000) != 0)) &&
             (*(char *)(iVar11 + 0x28b) == '\0')))) &&
           ((((iVar11 == DAT_0093d810 || (*(int *)(iVar11 + 0x424) != *(int *)(param_1 + 0x15c))) ||
             (*(int *)(iVar11 + 0x44c) != 0)) ||
            (*(byte *)(param_1 + 0x139) <= *(byte *)(iVar11 + 0x401))))) {
          fVar4 = *(float *)(iVar12 + 8) + _DAT_00801c6c * 0.5;
          if (*(float *)(iVar8 + 0x17c) <= fVar4) {
            fVar4 = *(float *)(iVar12 + 8) - _DAT_00801c6c * 0.5;
            if ((fVar4 <= *(float *)(iVar8 + 0x17c)) || (fVar4 <= *(float *)(iVar11 + 0x17c)))
            goto LAB_004cc77f;
          }
          else if (*(float *)(iVar11 + 0x17c) <= fVar4) {
LAB_004cc77f:
            fVar4 = *(float *)(iVar11 + 1000) + *(float *)(iVar11 + 1000) +
                    *(float *)(param_1 + 0x120);
            local_c[0] = *(float *)(iVar11 + 0x5c) - *(float *)(iVar12 + 4);
            if (((((local_c[0] < fVar4) && (-fVar4 < local_c[0])) &&
                 (local_c[2] = *(float *)(iVar11 + 100) - *(float *)(iVar12 + 0xc),
                 local_c[2] < fVar4)) &&
                ((-fVar4 < local_c[0] &&
                 (*(float *)(iVar12 + 8) < *(float *)(iVar11 + 0x188) !=
                  (*(float *)(iVar12 + 8) == *(float *)(iVar11 + 0x188)))))) &&
               ((*(float *)(iVar11 + 0x17c) <= *(float *)(iVar8 + 0xb4) + *(float *)(iVar12 + 8) &&
                (local_c[2] * local_c[2] + local_c[0] * local_c[0] < fVar4 * fVar4)))) {
              *(undefined1 *)(param_1 + 0x139) = 1;
              goto switchD_004cc452_default;
            }
          }
        }
        iVar7 = iVar7 + 1;
        iVar11 = iVar11 + 0x10d8;
      } while (iVar7 < DAT_0093d500);
    }
    FUN_0043cbb0(iVar8,iVar12,0,1);
    puVar2 = (uint *)(*(int *)(iVar8 + 0xca4) + 8);
    *puVar2 = *puVar2 | DAT_00802278;
  default:
    goto switchD_004cc452_default;
  }
  *(undefined1 *)(param_1 + 0x139) = 4;
switchD_004cc452_default:
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

