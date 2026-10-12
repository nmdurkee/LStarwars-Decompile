/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x480760; label: FUN_00480760
 */

/* WARNING: Removing unreachable block (ram,0x00480831) */
/* WARNING: Removing unreachable block (ram,0x00480a60) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00480760(float param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  int iVar13;
  float10 fVar14;
  uint local_18;
  float local_c [3];
  
  iVar8 = (int)param_1;
  iVar10 = *param_2;
  iVar9 = *(int *)((int)param_1 + 0x15c);
  bVar11 = *(byte *)((int)param_1 + 0x160);
  uVar4 = *(uint *)(iVar9 + (uint)bVar11 * 4);
  uVar5 = *(uint *)((int)param_1 + 500);
  iVar13 = 0;
  iVar12 = 0;
  local_18 = 0;
  bVar7 = false;
  if ((*(byte *)((int)param_1 + 0x166) & 1) == 0) {
LAB_004808be:
    *(undefined1 *)((int)param_1 + 0x139) = 0;
LAB_004808c5:
    if (*(char *)((int)param_1 + 0x139) == '\0') {
      return 0;
    }
  }
  else {
    iVar13 = *(int *)(*(int *)((int)param_1 + 0x158) + 0x7c);
    iVar12 = (uint)*(byte *)(iVar9 + 0x10 + (uint)bVar11) * 0x5c + iVar13;
    bVar11 = *(byte *)((bVar11 == 0) + 0x10 + iVar9);
    local_18 = (uint)bVar11;
    iVar13 = local_18 * 0x5c + iVar13;
    fVar14 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar13 + 4,local_c);
    if ((float)fVar14 < *(float *)(iVar13 + 0x14)) goto LAB_004808be;
    iVar9 = *(int *)((int)param_1 + 0x15c);
    if ((((*(byte *)(iVar9 + (uint)*(byte *)((int)param_1 + 0x160) * 4) & 0x20) == 0) &&
        ((int)*(short *)((int)param_1 + 0x124) != local_18)) &&
       ((*(byte *)(((int)local_18 >> 3) + 0x38 + *(int *)((int)param_1 + 0x158)) &
        (byte)(1 << (bVar11 & 7))) != 0)) {
      iVar9 = FUN_0043c9a0(iVar10,iVar13,0);
      if (iVar9 != 0) {
        return 1;
      }
      *(undefined1 *)((int)param_1 + 0x139) = 1;
      goto LAB_004808c5;
    }
    if (*(char *)((int)param_1 + 0x139) == '\0') {
      fVar6 = *(float *)((int)param_1 + 0x168) * *(float *)(iVar9 + 0x1c);
      *(undefined1 *)((int)param_1 + 0x139) = 1;
      if (*(char *)((int)param_1 + 0x160) == '\0') {
        if (*(float *)(iVar9 + 0x1c) - *(float *)(iVar13 + 0x10) < fVar6) goto LAB_004808be;
      }
      else if (fVar6 < *(float *)(iVar12 + 0x10)) goto LAB_004808be;
      goto LAB_004808c5;
    }
  }
  local_c[0] = *(float *)(iVar13 + 4) - *(float *)(iVar12 + 4);
  local_c[1] = 0.0;
  local_c[2] = *(float *)(iVar13 + 0xc) - *(float *)(iVar12 + 0xc);
  param_1 = *(float *)(iVar12 + 0x10);
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  FUN_005b3830(local_c,local_c,param_1 / *(float *)(*(int *)(iVar8 + 0x15c) + 0x1c));
  piVar1 = (int *)(iVar8 + 0x104);
  FUN_005b37d0(piVar1,iVar12 + 4,local_c);
  fVar14 = (float10)FUN_005b3cf0(param_2 + 0x17,piVar1,local_c);
  if ((param_3 != 0) &&
     ((((float)fVar14 < _DAT_00801c6c * _DAT_00801c6c ||
       (_DAT_007f673c < *(float *)(iVar10 + 0x1d8))) || (*(char *)(iVar10 + 0x7b5) == 'D')))) {
    *piVar1 = param_2[0x17];
    *(int *)(iVar8 + 0x108) = param_2[0x18];
    bVar7 = true;
    *(int *)(iVar8 + 0x10c) = param_2[0x19];
  }
  *(undefined4 *)(iVar8 + 0x110) = 0;
  fVar6 = _DAT_007fa2a0;
  if ((uVar4 & uVar5 & 2) != 0) {
    fVar6 = _DAT_007fa2a4;
  }
  puVar2 = (uint *)(*(int *)(iVar8 + 0x15c) + (uint)*(byte *)(iVar8 + 0x160) * 4);
  if ((*(byte *)(*(int *)(iVar8 + 0x15c) + (uint)*(byte *)(iVar8 + 0x160) * 4) & 0x80) != 0) {
    *(uint *)(iVar8 + 0x1e8) = *(uint *)(iVar8 + 0x1e8) | 0x800000;
    *(undefined1 *)(iVar8 + 0x139) = 1;
  }
  switch(*(undefined1 *)(iVar8 + 0x139)) {
  case 1:
    if (!bVar7) goto switchD_00480a1a_default;
    uVar4 = *puVar2;
    if ((((uVar4 & 0x20) == 0) && ((int)*(short *)(iVar8 + 0x124) != local_18)) &&
       ((*(byte *)(*(int *)(iVar8 + 0x158) + 0x38 + ((int)local_18 >> 3)) &
        (byte)(1 << ((byte)local_18 & 7))) != 0)) {
      iVar10 = FUN_0043c9a0(iVar10,iVar13,0);
      if (iVar10 != 0) {
        return 1;
      }
      goto switchD_00480a1a_default;
    }
    if ((char)uVar4 < '\0') goto switchD_00480a1a_default;
    if ((((uVar4 & 0x40) == 0) && (((*(byte *)(iVar13 + 0x2b) | *(byte *)(iVar12 + 0x2b)) & 2) != 0)
        ) && (iVar10 = FUN_005d0450(iVar12 + 0x40,iVar13 + 0x40), iVar10 == 0)) {
      *(undefined1 *)(iVar8 + 0x139) = 2;
      goto switchD_00480a1a_default;
    }
    break;
  case 2:
    if ((*puVar2 & 0x40) == 0) {
      fVar14 = (float10)FUN_005becc0(param_2 + 0x17,iVar13 + 4,local_c);
      if ((((*(byte *)(iVar12 + 0x2b) | *(byte *)(iVar13 + 0x2b)) & 2) == 0) ||
         (fVar6 < (float)fVar14 - *(float *)(iVar13 + 0x10))) {
        *(undefined1 *)(iVar8 + 0x139) = 3;
        if ((*(byte *)(iVar13 + 0x2b) & 2) == 0) {
          *(float *)(iVar10 + 0xed0) = (float)fVar14;
        }
        else {
          *(undefined4 *)(iVar10 + 0xed0) = 0;
        }
      }
      goto switchD_00480a1a_default;
    }
    break;
  case 3:
    if ((*puVar2 & 0x40) == 0) {
      fVar14 = (float10)FUN_005becc0(param_2 + 0x17,iVar13 + 4,local_c);
      fVar3 = (float)fVar14;
      bVar11 = (*(byte *)(iVar13 + 0x2b) | *(byte *)(iVar12 + 0x2b)) & 2;
      if ((bVar11 == 0) || (fVar3 - *(float *)(iVar13 + 0x10) < fVar6)) {
        if (bVar11 == 0) {
          *(undefined4 *)(iVar10 + 0xed0) = 0;
        }
        if (*(float *)(iVar10 + 0xed0) < fVar3) {
          *(undefined1 *)(iVar8 + 0x139) = 4;
          fVar3 = 0.0;
        }
        *(float *)(iVar10 + 0xed0) = fVar3;
      }
      goto switchD_00480a1a_default;
    }
    break;
  case 4:
    if ((*puVar2 & 2) != 0) {
      if (*(float *)(iVar10 + 0xd28) <= 0.0) {
        *(undefined1 *)(iVar8 + 0x139) = 5;
        *(uint *)(iVar10 + 0xeec) = *(uint *)(iVar10 + 0xeec) | 0x1000;
      }
      goto switchD_00480a1a_default;
    }
    *(undefined1 *)(iVar8 + 0x139) = 5;
    *(uint *)(iVar10 + 0xeec) = *(uint *)(iVar10 + 0xeec) & 0xffffefff;
  case 5:
    iVar9 = FUN_0043c9a0(iVar10,iVar13,0);
    if (iVar9 != 0) {
      return 1;
    }
    if (((*(byte *)(*(int *)(iVar8 + 0x15c) + (uint)*(byte *)(iVar8 + 0x160) * 4) & 0x20) == 0) &&
       (iVar12 = 0, iVar9 = DAT_0093d504, 0 < DAT_0093d500)) {
      do {
        if ((((*(uint *)(iVar9 + 0x1fc) & 1) != 0) &&
            (((iVar9 != iVar10 && ((*(uint *)(iVar9 + 0x1fc) & 0x1000) != 0)) &&
             (*(char *)(iVar9 + 0x28b) == '\0')))) &&
           (((iVar9 == DAT_0093d810 || (*(int *)(iVar9 + 0x424) != *(int *)(iVar8 + 0x15c))) ||
            ((*(int *)(iVar9 + 0x44c) != 0 || (*(byte *)(iVar8 + 0x139) <= *(byte *)(iVar9 + 0x401))
             ))))) {
          fVar6 = *(float *)(iVar13 + 8) + _DAT_00801c6c * 0.5;
          if (*(float *)(iVar10 + 0x17c) <= fVar6) {
            fVar6 = *(float *)(iVar13 + 8) - _DAT_00801c6c * 0.5;
            if ((fVar6 <= *(float *)(iVar10 + 0x17c)) || (fVar6 <= *(float *)(iVar9 + 0x17c)))
            goto LAB_00480d2d;
          }
          else if (*(float *)(iVar9 + 0x17c) <= fVar6) {
LAB_00480d2d:
            fVar6 = *(float *)(iVar9 + 1000) + *(float *)(iVar9 + 1000) + *(float *)(iVar8 + 0x120);
            local_c[0] = *(float *)(iVar9 + 0x5c) - *(float *)(iVar13 + 4);
            if (((((local_c[0] < fVar6) && (-fVar6 < local_c[0])) &&
                 (local_c[2] = *(float *)(iVar9 + 100) - *(float *)(iVar13 + 0xc),
                 local_c[2] < fVar6)) &&
                ((-fVar6 < local_c[0] &&
                 (*(float *)(iVar13 + 8) < *(float *)(iVar9 + 0x188) !=
                  (*(float *)(iVar13 + 8) == *(float *)(iVar9 + 0x188)))))) &&
               ((*(float *)(iVar9 + 0x17c) <= *(float *)(iVar10 + 0xb4) + *(float *)(iVar13 + 8) &&
                (local_c[2] * local_c[2] + local_c[0] * local_c[0] < fVar6 * fVar6)))) {
              *(undefined1 *)(iVar8 + 0x139) = 1;
              goto switchD_00480a1a_default;
            }
          }
        }
        iVar12 = iVar12 + 1;
        iVar9 = iVar9 + 0x10d8;
      } while (iVar12 < DAT_0093d500);
    }
    FUN_0043cbb0(iVar10,iVar13,0,1);
    puVar2 = (uint *)(*(int *)(iVar10 + 0xca4) + 8);
    *puVar2 = *puVar2 | DAT_00802278;
  default:
    goto switchD_00480a1a_default;
  }
  *(undefined1 *)(iVar8 + 0x139) = 4;
switchD_00480a1a_default:
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

