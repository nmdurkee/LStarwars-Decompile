/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51cbc0; label: FUN_0051cbc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051cbc0(int *param_1,int *param_2,int param_3,int param_4)

{
  byte bVar1;
  int *piVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  float10 fVar11;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18 [3];
  undefined1 local_c [12];
  
  if (param_2[1] == 0) {
    return 0;
  }
  uVar7 = (uint)*(byte *)(((char)param_2[2] == '\0') + 0x10 + param_2[1]);
  if (param_2[10] == 0) {
    uVar9 = uVar7;
    if (param_3 == 0) {
      if (*param_1 != 0) {
        iVar5 = *(int *)(*param_1 + 4);
        iVar6 = *param_2;
        if (*(int *)(iVar5 + 0x84) == iVar6) {
          if (*(float *)(iVar5 + 0x94) <= 0.5) {
            bVar1 = *(byte *)(*(int *)(iVar5 + 0x88) + 0x10);
          }
          else {
            bVar1 = *(byte *)(*(int *)(iVar5 + 0x88) + 0x11);
          }
          uVar9 = (uint)bVar1;
          uVar4 = (uint)*(byte *)(*(int *)(*(int *)(iVar6 + 0x84) + uVar7 * 4) + uVar9);
          if (uVar4 != 0xff) {
            iVar5 = *(int *)(*(int *)(*(int *)(iVar6 + 0x7c) + 0x34 + uVar7 * 0x5c) + uVar4 * 4);
            param_2[10] = iVar5;
            if (*(int *)(iVar5 + (uint)(*(byte *)(iVar5 + 0x10) != uVar7) * 4) != 0) {
              param_2[10] = 0;
            }
          }
        }
      }
    }
    else {
      iVar5 = *(int *)(param_3 + 4);
      if (param_2[1] == iVar5) {
        iVar5 = *(int *)(param_3 + 0x28);
      }
      param_2[10] = iVar5;
    }
    iVar5 = param_2[10];
    if ((iVar5 != 0) && (*(int *)(iVar5 + (uint)(*(byte *)(iVar5 + 0x10) != uVar9) * 4) == 0)) {
      if ((char)param_2[2] == '\0') {
        iVar5 = (int)*(short *)(param_2[1] + 0x12);
      }
      else {
        iVar5 = FUN_005be590(0x8000,(int)*(short *)(param_2[1] + 0x12));
      }
      if (*(char *)(((char)param_2[2] == '\0') + 0x10 + param_2[1]) == *(char *)(param_2[10] + 0x10)
         ) {
        *(undefined1 *)(param_2 + 0xb) = 0;
        iVar6 = (int)*(short *)(param_2[10] + 0x12);
      }
      else {
        *(undefined1 *)(param_2 + 0xb) = 1;
        iVar6 = FUN_005be590(0x8000,(int)*(short *)(param_2[10] + 0x12));
      }
      iVar5 = FUN_005be5b0(iVar6,iVar5);
      if (iVar5 < 0) {
        param_2[0xc] = param_2[0xc] | 1;
      }
      else {
        param_2[0xc] = param_2[0xc] & 0xfffffffe;
      }
    }
    if (param_2[10] == 0) {
      if ((char)param_2[2] == '\0') {
        if (1.0 < (float)param_2[4]) {
          return 1;
        }
      }
      else if ((float)param_2[4] < 0.0) {
        return 1;
      }
      iVar5 = (int)*(short *)(param_2[1] + 0x12);
      if ((char)param_2[2] != '\0') {
        iVar5 = FUN_005be590(iVar5,0x8000);
      }
      iVar6 = FUN_005be5b0(iVar5,param_2[9]);
      iVar8 = (int)(short)param_1[1];
      iVar5 = iVar8;
      if ((iVar8 < iVar6) || (iVar5 = -iVar8, iVar6 < -iVar8)) {
        iVar6 = iVar5;
      }
      iVar5 = FUN_005be590(iVar6,param_2[9]);
      local_24 = 0;
      local_20 = 0;
      param_2[9] = iVar5;
      local_1c = 0.0;
      if (DAT_009238c4 != (code *)0x0) {
        fVar11 = (float10)(*DAT_009238c4)(param_4);
        local_1c = (float)fVar11;
      }
      FUN_005b3620(&local_24,&local_24,param_2[9]);
      goto LAB_0051d112;
    }
  }
  local_18[1] = 0.0;
  local_18[2] = 0.0;
  local_18[0] = (float)param_1[0x49];
  if ((*(byte *)(param_2 + 0xc) & 1) != 0) {
    local_18[0] = -local_18[0];
  }
  FUN_005b3620(&local_24,local_18,param_2[9]);
  piVar10 = param_2 + 6;
  FUN_005b37d0(local_c,&local_24,piVar10);
  if ((*(byte *)(param_2 + 0xc) & 2) == 0) {
    iVar5 = param_2[10];
    if (param_2[1] == iVar5) {
      iVar5 = (uint)*(byte *)(((char)param_2[2] == '\0') + 0x10 + param_2[1]) * 0x5c +
              *(int *)(*param_2 + 0x7c);
      fVar11 = (float10)FUN_005b3cf0(piVar10,iVar5 + 4,&local_24);
      if ((float)fVar11 < *(float *)(iVar5 + 0x14)) {
        iVar5 = 0;
        if (*(char *)((int)param_1 + 6) != '\0') {
          piVar10 = param_1 + 0x1e;
          do {
            piVar10[1] = 0;
            iVar6 = FUN_005be590(*piVar10,0x8000);
            *piVar10 = iVar6;
            *(bool *)(piVar10 + -7) = (char)piVar10[-7] == '\0';
            iVar5 = iVar5 + 1;
            piVar10 = piVar10 + 0xd;
          } while (iVar5 < (int)(uint)*(byte *)((int)param_1 + 6));
        }
        uVar7 = param_1[0x14];
        param_1[0x14] = uVar7 ^ 4;
        *param_1 = 0;
        if (((uVar7 ^ 4) & 4) == 0) {
          iVar5 = 0;
          if (*(char *)((int)param_1 + 7) != '\0') {
            piVar10 = param_1 + 3;
            while ((((piVar2 = (int *)*piVar10, *piVar2 == 0 || ((piVar2[0x7f] & 1U) == 0)) ||
                    ((piVar2[0x7f] & 0x1000U) == 0)) || (*(char *)((int)piVar2 + 0x28b) != '\0'))) {
              iVar5 = iVar5 + 1;
              piVar10 = piVar10 + 1;
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
            piVar10 = param_1 + *(byte *)((int)param_1 + 7) + 2;
            while (((iVar6 = *piVar10, iVar6 == 0 || ((*(uint *)(iVar6 + 0x1fc) & 1) == 0)) ||
                   (((*(uint *)(iVar6 + 0x1fc) & 0x1000) == 0 || (*(char *)(iVar6 + 0x28b) != '\0'))
                   ))) {
              iVar5 = iVar5 + -1;
              piVar10 = piVar10 + -1;
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
      fVar11 = (float10)FUN_005bfc30((uint)*(byte *)(iVar5 + 0x10) * 0x5c +
                                     *(int *)(*param_2 + 0x7c) + 4,
                                     (uint)*(byte *)(iVar5 + 0x11) * 0x5c +
                                     *(int *)(*param_2 + 0x7c) + 4,local_c);
      fVar3 = (float)param_1[0x49] * (float)param_1[0x49];
      if ((float)fVar11 < fVar3 != ((float)fVar11 == fVar3)) {
        param_2[0xc] = param_2[0xc] | 2;
      }
    }
    if ((*(byte *)(param_2 + 0xc) & 2) == 0) {
      if ((*(byte *)(param_1 + 0x14) & 0x10) != 0) {
        return 0;
      }
      iVar5 = (int)*(short *)(param_2[1] + 0x12);
      if ((char)param_2[2] != '\0') {
        iVar5 = FUN_005be590(iVar5,0x8000);
      }
      iVar6 = FUN_005be5b0(iVar5,param_2[9]);
      iVar8 = (int)(short)param_1[1];
      iVar5 = iVar8;
      if ((iVar8 < iVar6) || (iVar5 = -iVar8, iVar6 < -iVar8)) {
        iVar6 = iVar5;
      }
      iVar5 = FUN_005be590(iVar6,param_2[9]);
      local_24 = 0;
      local_20 = 0;
      param_2[9] = iVar5;
      local_1c = 0.0;
      if (DAT_009238c4 != (code *)0x0) {
        fVar11 = (float10)(*DAT_009238c4)(param_4);
        local_1c = (float)fVar11;
      }
      FUN_005b3620(&local_24,&local_24,param_2[9]);
LAB_0051d112:
      FUN_005b37d0(param_2 + 6,param_2 + 6,&local_24);
      param_2[7] = *(int *)(param_4 + 0x60);
      return 0;
    }
  }
  iVar5 = (int)*(short *)(param_2[10] + 0x12);
  if ((char)param_2[0xb] != '\0') {
    iVar5 = FUN_005be590(iVar5,0x8000);
  }
  iVar6 = FUN_005be5b0(iVar5,param_2[9]);
  iVar5 = (int)(short)param_1[1];
  if ((iVar6 <= iVar5) && (iVar5 = -iVar5, iVar5 <= iVar6)) {
    param_2[0xc] = param_2[0xc] & 0xfffffffd;
    param_2[1] = param_2[10];
    *(char *)(param_2 + 2) = (char)param_2[0xb];
    param_2[10] = 0;
    iVar5 = iVar6;
  }
  iVar5 = FUN_005be590(iVar5,param_2[9]);
  param_2[9] = iVar5;
  FUN_005b3620(&local_24,local_18,iVar5);
  FUN_005b3800(piVar10,local_c,&local_24);
  return 0;
}

