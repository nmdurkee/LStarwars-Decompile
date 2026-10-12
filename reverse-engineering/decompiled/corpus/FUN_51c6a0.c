/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51c6a0; label: FUN_0051c6a0
 */

undefined4 FUN_0051c6a0(undefined4 *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  float fVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  float10 fVar13;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18 [3];
  undefined1 local_c [12];
  
  piVar11 = param_2;
  iVar5 = param_2[1];
  if (iVar5 == 0) {
    return 0;
  }
  uVar8 = (uint)*(byte *)(((char)param_2[2] == '\0') + 0x10 + iVar5);
  iVar9 = uVar8 * 0x5c + *(int *)(*param_2 + 0x7c);
  if (param_2[10] != 0) goto LAB_0051c888;
  if (param_3 == 0) {
    uVar12 = (uint)*(byte *)(iVar9 + 0x28);
    uVar4 = FUN_005b9e30();
    uVar4 = uVar4 % uVar12;
    param_2 = (int *)0x0;
    if (uVar12 != 0) {
      do {
        iVar5 = *(int *)(*(int *)(iVar9 + 0x34) + ((int)((int)param_2 + uVar4) % (int)uVar12) * 4);
        piVar11[10] = iVar5;
        if ((iVar5 != piVar11[1]) &&
           ((((*(char *)(*(int *)(param_4 + 4) + 0x13c) == -1 ||
              (uVar3 = __allshl(), (*(ushort *)(iVar5 + 0x14) & uVar3) != 0)) ||
             ((*(ushort *)(iVar9 + 0x5a) & uVar3) != 0)) &&
            ((uVar12 = (uint)(*(byte *)(iVar5 + 0x10) != uVar8),
             (float)param_1[0x49] <
             *(float *)((uint)*(byte *)((uVar12 == 0) + 0x10 + iVar5) * 0x5c + 0x10 +
                       *(int *)(*piVar11 + 0x7c)) && (*(int *)(iVar5 + uVar12 * 4) == 0)))))) break;
        piVar11[10] = 0;
        uVar12 = (uint)*(byte *)(iVar9 + 0x28);
        param_2 = (int *)((int)param_2 + 1);
      } while ((int)param_2 < (int)uVar12);
    }
    if (piVar11[10] == 0) {
      iVar5 = piVar11[1];
      goto LAB_0051c7e4;
    }
  }
  else if (iVar5 == *(int *)(param_3 + 4)) {
    iVar5 = *(int *)(param_3 + 0x28);
LAB_0051c7e4:
    piVar11[10] = iVar5;
  }
  else {
    param_2[10] = *(int *)(param_3 + 4);
  }
  iVar5 = piVar11[10];
  if ((iVar5 != 0) && (*(int *)(iVar5 + (uint)(*(byte *)(iVar5 + 0x10) != uVar8) * 4) == 0)) {
    if ((char)piVar11[2] == '\0') {
      iVar5 = (int)*(short *)(piVar11[1] + 0x12);
    }
    else {
      iVar5 = FUN_005be590(0x8000,(int)*(short *)(piVar11[1] + 0x12));
    }
    iVar9 = piVar11[10];
    if (*(char *)(((char)piVar11[2] == '\0') + 0x10 + piVar11[1]) == *(char *)(iVar9 + 0x10)) {
      *(undefined1 *)(piVar11 + 0xb) = 0;
      iVar9 = (int)*(short *)(iVar9 + 0x12);
    }
    else {
      *(undefined1 *)(piVar11 + 0xb) = 1;
      iVar9 = FUN_005be590(0x8000,(int)*(short *)(iVar9 + 0x12));
    }
    iVar5 = FUN_005be5b0(iVar9,iVar5);
    if (iVar5 < 0) {
      piVar11[0xc] = piVar11[0xc] | 1;
    }
    else {
      piVar11[0xc] = piVar11[0xc] & 0xfffffffe;
    }
  }
  if (piVar11[10] == 0) {
    return 0;
  }
LAB_0051c888:
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  local_18[0] = (float)param_1[0x49];
  if ((*(byte *)(piVar11 + 0xc) & 1) != 0) {
    local_18[0] = -local_18[0];
  }
  FUN_005b3620(&local_24,local_18,piVar11[9]);
  piVar1 = piVar11 + 6;
  FUN_005b37d0(local_c,&local_24,piVar1);
  if ((*(byte *)(piVar11 + 0xc) & 2) == 0) {
    iVar5 = piVar11[10];
    if (piVar11[1] == iVar5) {
      iVar5 = (uint)*(byte *)(((char)piVar11[2] == '\0') + 0x10 + piVar11[1]) * 0x5c +
              *(int *)(*piVar11 + 0x7c);
      fVar13 = (float10)FUN_005b3cf0(piVar1,iVar5 + 4,&local_24);
      if ((float)fVar13 < *(float *)(iVar5 + 0x14)) {
        iVar5 = 0;
        if (*(char *)((int)param_1 + 6) != '\0') {
          puVar10 = param_1 + 0x1e;
          do {
            puVar10[1] = 0;
            uVar6 = FUN_005be590(*puVar10,0x8000);
            *puVar10 = uVar6;
            *(bool *)(puVar10 + -7) = *(char *)(puVar10 + -7) == '\0';
            iVar5 = iVar5 + 1;
            puVar10 = puVar10 + 0xd;
          } while (iVar5 < (int)(uint)*(byte *)((int)param_1 + 6));
        }
        uVar8 = param_1[0x14];
        param_1[0x14] = uVar8 ^ 4;
        *param_1 = 0;
        if (((uVar8 ^ 4) & 4) == 0) {
          iVar5 = 0;
          if (*(char *)((int)param_1 + 7) != '\0') {
            piVar11 = param_1 + 3;
            while ((((piVar1 = (int *)*piVar11, *piVar1 == 0 || ((piVar1[0x7f] & 1U) == 0)) ||
                    ((piVar1[0x7f] & 0x1000U) == 0)) || (*(char *)((int)piVar1 + 0x28b) != '\0'))) {
              iVar5 = iVar5 + 1;
              piVar11 = piVar11 + 1;
              if ((int)(uint)*(byte *)((int)param_1 + 7) <= iVar5) {
                return 1;
              }
            }
            *param_1 = param_1[iVar5 + 3];
          }
        }
        else {
          iVar5 = *(byte *)((int)param_1 + 7) - 1;
          if (-1 < iVar5) {
            piVar11 = param_1 + *(byte *)((int)param_1 + 7) + 2;
            while (((iVar9 = *piVar11, iVar9 == 0 || ((*(uint *)(iVar9 + 0x1fc) & 1) == 0)) ||
                   (((*(uint *)(iVar9 + 0x1fc) & 0x1000) == 0 || (*(char *)(iVar9 + 0x28b) != '\0'))
                   ))) {
              iVar5 = iVar5 + -1;
              piVar11 = piVar11 + -1;
              if (iVar5 < 0) {
                return 1;
              }
            }
            *param_1 = param_1[iVar5 + 3];
            return 1;
          }
        }
        return 1;
      }
    }
    else {
      iVar9 = *(int *)(*piVar11 + 0x7c);
      fVar13 = (float10)FUN_005bfc30((uint)*(byte *)(iVar5 + 0x10) * 0x5c + iVar9 + 4,
                                     (uint)*(byte *)(iVar5 + 0x11) * 0x5c + iVar9 + 4,local_c);
      fVar2 = (float)param_1[0x49] * (float)param_1[0x49];
      if ((float)fVar13 < fVar2 != ((float)fVar13 == fVar2)) {
        piVar11[0xc] = piVar11[0xc] | 2;
      }
    }
    if ((*(byte *)(piVar11 + 0xc) & 2) == 0) {
      if ((*(byte *)(param_1 + 0x14) & 0x10) == 0) {
        iVar5 = (int)*(short *)(piVar11[1] + 0x12);
        if ((char)piVar11[2] != '\0') {
          iVar5 = FUN_005be590(iVar5,0x8000);
        }
        iVar9 = FUN_005be5b0(iVar5,piVar11[9]);
        iVar7 = (int)*(short *)(param_1 + 1);
        iVar5 = iVar7;
        if ((iVar7 < iVar9) || (iVar5 = -iVar7, iVar9 < -iVar7)) {
          iVar9 = iVar5;
        }
        iVar5 = FUN_005be590(iVar9,piVar11[9]);
        local_24 = 0;
        piVar11[9] = iVar5;
        local_20 = 0;
        local_1c = 0.0;
        if (DAT_009238c4 != (code *)0x0) {
          fVar13 = (float10)(*DAT_009238c4)(param_4);
          local_1c = (float)fVar13;
        }
        FUN_005b3620(&local_24,&local_24,piVar11[9]);
        FUN_005b37d0(piVar1,piVar1,&local_24);
        piVar11[7] = *(int *)(param_4 + 0x60);
      }
      return 0;
    }
  }
  iVar5 = (int)*(short *)(piVar11[10] + 0x12);
  if ((char)piVar11[0xb] != '\0') {
    iVar5 = FUN_005be590(iVar5,0x8000);
  }
  iVar9 = FUN_005be5b0(iVar5,piVar11[9]);
  iVar5 = (int)*(short *)(param_1 + 1);
  if ((iVar9 <= iVar5) && (iVar5 = -iVar5, iVar5 <= iVar9)) {
    piVar11[0xc] = piVar11[0xc] & 0xfffffffd;
    piVar11[1] = piVar11[10];
    *(char *)(piVar11 + 2) = (char)piVar11[0xb];
    piVar11[10] = 0;
    iVar5 = iVar9;
  }
  iVar5 = FUN_005be590(iVar5,piVar11[9]);
  piVar11[9] = iVar5;
  FUN_005b3620(&local_24,local_18,iVar5);
  FUN_005b3800(piVar1,local_c,&local_24);
  return 0;
}

