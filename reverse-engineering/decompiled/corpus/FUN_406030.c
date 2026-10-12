/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x406030; label: FUN_00406030
 */

/* WARNING: Removing unreachable block (ram,0x00406104) */
/* WARNING: Removing unreachable block (ram,0x00406352) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00406030(float param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  uint local_14;
  float local_c [3];
  
  iVar6 = (int)param_1;
  iVar8 = *param_2;
  iVar7 = *(int *)((int)param_1 + 0x15c);
  bVar9 = *(byte *)((int)param_1 + 0x160);
  uVar10 = *(uint *)(iVar7 + (uint)bVar9 * 4) & *(uint *)((int)param_1 + 500);
  iVar12 = 0;
  iVar11 = 0;
  local_14 = 0;
  if ((*(byte *)((int)param_1 + 0x166) & 1) == 0) {
LAB_00406191:
    *(undefined1 *)((int)param_1 + 0x139) = 0;
LAB_00406198:
    if (*(char *)((int)param_1 + 0x139) == '\0') {
      return 0;
    }
  }
  else {
    iVar12 = *(int *)(*(int *)((int)param_1 + 0x158) + 0x7c);
    iVar11 = (uint)*(byte *)(iVar7 + 0x10 + (uint)bVar9) * 0x5c + iVar12;
    bVar9 = *(byte *)((bVar9 == 0) + 0x10 + iVar7);
    local_14 = (uint)bVar9;
    iVar12 = local_14 * 0x5c + iVar12;
    fVar13 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar12 + 4,local_c);
    if ((float)fVar13 < *(float *)(iVar12 + 0x14)) goto LAB_00406191;
    iVar7 = *(int *)((int)param_1 + 0x15c);
    if ((((*(uint *)(iVar7 + (uint)*(byte *)((int)param_1 + 0x160) * 4) & 0x200) == 0) &&
        ((int)*(short *)((int)param_1 + 0x124) != local_14)) &&
       ((*(byte *)(((int)local_14 >> 3) + 0x38 + *(int *)((int)param_1 + 0x158)) &
        (byte)(1 << (bVar9 & 7))) != 0)) {
      iVar7 = FUN_0043c9a0(iVar8,iVar12,0);
      if (iVar7 != 0) {
        return 1;
      }
      *(undefined1 *)((int)param_1 + 0x139) = 1;
      goto LAB_00406198;
    }
    if (*(char *)((int)param_1 + 0x139) == '\0') {
      fVar4 = *(float *)((int)param_1 + 0x168) * *(float *)(iVar7 + 0x1c);
      *(undefined1 *)((int)param_1 + 0x139) = 1;
      if (*(char *)((int)param_1 + 0x160) == '\0') {
        if (*(float *)(iVar7 + 0x1c) - *(float *)(iVar12 + 0x10) < fVar4) goto LAB_00406191;
      }
      else if (fVar4 < *(float *)(iVar11 + 0x10)) goto LAB_00406191;
      goto LAB_00406198;
    }
  }
  local_c[0] = *(float *)(iVar12 + 4) - *(float *)(iVar11 + 4);
  local_c[1] = 0.0;
  local_c[2] = *(float *)(iVar12 + 0xc) - *(float *)(iVar11 + 0xc);
  param_1 = *(float *)(iVar11 + 0x10);
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  FUN_005b3830(local_c,local_c,param_1 / *(float *)(*(int *)(iVar6 + 0x15c) + 0x1c));
  piVar1 = (int *)(iVar6 + 0x104);
  FUN_005b37d0(piVar1,iVar11 + 4,local_c);
  fVar13 = (float10)FUN_005b3cf0(param_2 + 0x17,piVar1,local_c);
  if ((param_3 == 0) ||
     (((_DAT_00801c6c * _DAT_00801c6c <= (float)fVar13 &&
       (*(float *)(iVar8 + 0x1d8) <= _DAT_007f673c)) && (*(char *)(iVar8 + 0x7b5) != 'D')))) {
    bVar5 = false;
  }
  else {
    *piVar1 = param_2[0x17];
    *(int *)(iVar6 + 0x108) = param_2[0x18];
    bVar5 = true;
    *(int *)(iVar6 + 0x10c) = param_2[0x19];
  }
  *(undefined4 *)(iVar6 + 0x110) = 0;
  fVar4 = _DAT_007ef29c;
  if ((((uVar10 & 4) == 0) && (fVar4 = _DAT_007ef298, (uVar10 & 2) == 0)) &&
     (fVar4 = _DAT_007ef294, (uVar10 & 0x20) != 0)) {
    fVar4 = _DAT_007ef298;
  }
  puVar2 = (uint *)(*(int *)(iVar6 + 0x15c) + (uint)*(byte *)(iVar6 + 0x160) * 4);
  if ((*(uint *)(*(int *)(iVar6 + 0x15c) + (uint)*(byte *)(iVar6 + 0x160) * 4) & 0x800) != 0) {
    *(uint *)(iVar6 + 0x1e8) = *(uint *)(iVar6 + 0x1e8) | 0x800000;
    *(undefined1 *)(iVar6 + 0x139) = 1;
  }
  switch(*(undefined1 *)(iVar6 + 0x139)) {
  case 1:
    if (!bVar5) goto switchD_0040630c_default;
    uVar10 = *puVar2;
    if ((((uVar10 & 0x200) == 0) && ((int)*(short *)(iVar6 + 0x124) != local_14)) &&
       ((*(byte *)(*(int *)(iVar6 + 0x158) + 0x38 + ((int)local_14 >> 3)) &
        (byte)(1 << ((byte)local_14 & 7))) != 0)) {
      iVar8 = FUN_0043c9a0(iVar8,iVar12,0);
      if (iVar8 != 0) {
        return 1;
      }
      goto switchD_0040630c_default;
    }
    if ((uVar10 & 0x800) != 0) goto switchD_0040630c_default;
    if ((((uVar10 & 0x400) == 0) &&
        (((*(byte *)(iVar12 + 0x2b) | *(byte *)(iVar11 + 0x2b)) & 2) != 0)) &&
       (iVar8 = FUN_005d0450(iVar11 + 0x40,iVar12 + 0x40), iVar8 == 0)) {
      *(undefined1 *)(iVar6 + 0x139) = 2;
      goto switchD_0040630c_default;
    }
    break;
  case 2:
    if ((*puVar2 & 0x400) == 0) {
      fVar13 = (float10)FUN_005becc0(param_2 + 0x17,iVar12 + 4,local_c);
      fVar3 = (float)fVar13;
      if ((((*(byte *)(iVar11 + 0x2b) | *(byte *)(iVar12 + 0x2b)) & 2) != 0) &&
         (fVar3 - *(float *)(iVar12 + 0x10) <= fVar4)) goto switchD_0040630c_default;
      *(undefined1 *)(iVar6 + 0x139) = 3;
      if ((*(byte *)(iVar12 + 0x2b) & 2) != 0) {
        *(undefined4 *)(iVar8 + 0xed0) = 0;
        goto switchD_0040630c_default;
      }
LAB_00406436:
      *(float *)(iVar8 + 0xed0) = fVar3;
      goto switchD_0040630c_default;
    }
    break;
  case 3:
    if ((*puVar2 & 0x400) == 0) {
      fVar13 = (float10)FUN_005becc0(param_2 + 0x17,iVar12 + 4,local_c);
      fVar3 = (float)fVar13;
      bVar9 = (*(byte *)(iVar12 + 0x2b) | *(byte *)(iVar11 + 0x2b)) & 2;
      if ((bVar9 != 0) && (fVar4 <= fVar3 - *(float *)(iVar12 + 0x10)))
      goto switchD_0040630c_default;
      if (bVar9 == 0) {
        *(undefined4 *)(iVar8 + 0xed0) = 0;
      }
      if (*(float *)(iVar8 + 0xed0) < fVar3) {
        *(undefined1 *)(iVar6 + 0x139) = 4;
        *(undefined4 *)(iVar8 + 0xed0) = 0;
        goto switchD_0040630c_default;
      }
      goto LAB_00406436;
    }
    break;
  case 4:
    if ((*puVar2 & 0x26) != 0) {
      if (*(float *)(iVar8 + 0xd28) <= 0.0) {
        *(undefined1 *)(iVar6 + 0x139) = 5;
        *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) | 0x1000;
      }
      goto switchD_0040630c_default;
    }
    *(undefined1 *)(iVar6 + 0x139) = 5;
    *(uint *)(iVar8 + 0xeec) = *(uint *)(iVar8 + 0xeec) & 0xffffefff;
  case 5:
    iVar7 = FUN_0043c9a0(iVar8,iVar12,0);
    if (iVar7 != 0) {
      return 1;
    }
    if (((*(uint *)(*(int *)(iVar6 + 0x15c) + (uint)*(byte *)(iVar6 + 0x160) * 4) & 0x200) == 0) &&
       (iVar11 = 0, iVar7 = DAT_0093d504, 0 < DAT_0093d500)) {
      do {
        if ((((*(uint *)(iVar7 + 0x1fc) & 1) != 0) &&
            (((iVar7 != iVar8 && ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) &&
             (*(char *)(iVar7 + 0x28b) == '\0')))) &&
           ((((iVar7 == DAT_0093d810 || (*(int *)(iVar7 + 0x424) != *(int *)(iVar6 + 0x15c))) ||
             (*(int *)(iVar7 + 0x44c) != 0)) ||
            (*(byte *)(iVar6 + 0x139) <= *(byte *)(iVar7 + 0x401))))) {
          fVar4 = *(float *)(iVar12 + 8) + _DAT_00801c6c * 0.5;
          if (*(float *)(iVar8 + 0x17c) <= fVar4) {
            fVar4 = *(float *)(iVar12 + 8) - _DAT_00801c6c * 0.5;
            if ((fVar4 <= *(float *)(iVar8 + 0x17c)) || (fVar4 <= *(float *)(iVar7 + 0x17c)))
            goto LAB_00406634;
          }
          else if (*(float *)(iVar7 + 0x17c) <= fVar4) {
LAB_00406634:
            fVar4 = *(float *)(iVar7 + 1000) + *(float *)(iVar7 + 1000) + *(float *)(iVar6 + 0x120);
            local_c[0] = *(float *)(iVar7 + 0x5c) - *(float *)(iVar12 + 4);
            if (((((local_c[0] < fVar4) && (-fVar4 < local_c[0])) &&
                 (local_c[2] = *(float *)(iVar7 + 100) - *(float *)(iVar12 + 0xc),
                 local_c[2] < fVar4)) &&
                ((-fVar4 < local_c[0] &&
                 (*(float *)(iVar12 + 8) < *(float *)(iVar7 + 0x188) !=
                  (*(float *)(iVar12 + 8) == *(float *)(iVar7 + 0x188)))))) &&
               ((*(float *)(iVar7 + 0x17c) <= *(float *)(iVar8 + 0xb4) + *(float *)(iVar12 + 8) &&
                (local_c[2] * local_c[2] + local_c[0] * local_c[0] < fVar4 * fVar4)))) {
              *(undefined1 *)(iVar6 + 0x139) = 1;
              goto switchD_0040630c_default;
            }
          }
        }
        iVar11 = iVar11 + 1;
        iVar7 = iVar7 + 0x10d8;
      } while (iVar11 < DAT_0093d500);
    }
    FUN_0043cbb0(iVar8,iVar12,0,1);
    puVar2 = (uint *)(*(int *)(iVar8 + 0xca4) + 8);
    *puVar2 = *puVar2 | DAT_00802278;
  default:
    goto switchD_0040630c_default;
  }
  *(undefined1 *)(iVar6 + 0x139) = 4;
switchD_0040630c_default:
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

