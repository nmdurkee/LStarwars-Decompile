/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x690f60; label: FUN_00690f60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00690f60(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  float10 fVar11;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int *local_1c;
  undefined1 local_18 [20];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_40;
  local_28 = param_2;
  local_30 = 0;
  local_1c = param_4;
  while ((&DAT_02920acc)[local_30] != 0) {
    local_30 = local_30 + 1;
    if (7 < local_30) {
      __security_check_cookie(local_4 ^ (uint)&local_40);
      return;
    }
  }
  if (local_30 == -1) {
    __security_check_cookie(local_4 ^ (uint)&local_40);
    return;
  }
  if ((DAT_02962928 != 1) || (iVar5 = DAT_02962a00, DAT_02962a00 == 0)) {
    iVar5 = *param_4;
  }
  local_34 = local_30 * 4;
  uVar9 = iVar5 + 0xfU & 0xfffffff0;
  *(uint *)(&DAT_0292fce8 + local_34) = uVar9;
  FUN_006211c0(1);
  iVar5 = FUN_00621270(param_1,0);
  if (iVar5 == 0) {
    __security_check_cookie(local_4 ^ (uint)&local_40);
    return;
  }
  FUN_006211b0(1);
  iVar5 = FUN_006217e0();
  local_2c = iVar5;
  if ((9 < iVar5) || (iVar5 < 1)) {
    FUN_006211b0(0);
    FUN_006213e0();
    __security_check_cookie(local_4 ^ (uint)&local_40);
    return;
  }
  if (iVar5 < 9) {
    _DAT_00810a98 = 15.0;
    fVar11 = (float10)25.0;
  }
  else {
    fVar11 = (float10)FUN_006217a0();
    _DAT_00810a98 = (float)fVar11;
    fVar11 = (float10)FUN_006217a0();
  }
  _DAT_00810a9c = (float)fVar11;
  iVar6 = FUN_006217e0();
  if (DAT_02962a08 < DAT_029629e0 + iVar6) {
    iVar6 = DAT_02962a08 - DAT_029629e0;
  }
  local_20 = iVar6;
  if (iVar5 < 8) {
    iVar5 = 0x3000;
  }
  else {
    iVar5 = FUN_006217e0();
  }
  if ((DAT_02962928 == 1) && (DAT_02962a04 != 0)) {
    local_40 = DAT_02962a04;
  }
  else {
    local_40 = iVar5 * 0x40 + uVar9;
  }
  local_3c = 0;
  local_24 = 0;
  if (0 < iVar6) {
    do {
      piVar10 = (int *)(local_3c * 0x50 + 4 + DAT_02962a14);
      iVar5 = *piVar10;
      for (; (iVar5 != 0 && (local_3c < DAT_02962a08)); local_3c = local_3c + 1) {
        piVar10 = piVar10 + 0x14;
        iVar5 = *piVar10;
      }
      piVar10 = (int *)(local_3c * 0x50 + DAT_02962a14);
      FUN_006216f0(local_18,0x14);
      iVar5 = FUN_0065c620(local_18,local_28);
      *piVar10 = iVar5;
      iVar5 = FUN_006217e0();
      piVar10[1] = iVar5;
      fVar11 = (float10)FUN_006217a0();
      piVar10[2] = (int)(float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      piVar10[3] = (int)(float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      piVar10[4] = (int)(float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      piVar10[5] = (int)(float)fVar11;
      fVar11 = (float10)FUN_006217a0();
      iVar5 = local_2c;
      piVar10[6] = (int)(float)fVar11;
      if (local_2c < 2) {
        piVar10[7] = 1;
      }
      else {
        iVar6 = FUN_006217e0();
        piVar10[7] = iVar6;
      }
      if (iVar5 < 3) {
        fVar11 = (float10)1;
      }
      else {
        fVar11 = (float10)FUN_006217a0();
      }
      piVar10[8] = (int)(float)fVar11;
      *(undefined1 *)(piVar10 + 9) = (undefined1)local_30;
      if (iVar5 < 5) {
        *(undefined1 *)((int)piVar10 + 0x25) = 1;
        *(undefined1 *)((int)piVar10 + 0x26) = 1;
      }
      else {
        uVar3 = FUN_006218c0();
        *(undefined1 *)((int)piVar10 + 0x25) = uVar3;
        uVar3 = FUN_006218c0();
        *(undefined1 *)((int)piVar10 + 0x26) = uVar3;
      }
      if (iVar5 < 6) {
        *(undefined1 *)((int)piVar10 + 0x27) = 1;
      }
      else {
        uVar3 = FUN_006218c0();
        *(undefined1 *)((int)piVar10 + 0x27) = uVar3;
      }
      if (iVar5 < 4) {
        piVar10[10] = 0;
        piVar10[0xb] = 0x3e4ccccd;
        fVar11 = (float10)1.7625;
      }
      else {
        iVar6 = FUN_006217e0();
        piVar10[10] = iVar6;
        fVar11 = (float10)FUN_006217a0();
        piVar10[0xb] = (int)(float)fVar11;
        fVar11 = (float10)FUN_006217a0();
      }
      piVar10[0xc] = (int)(float)fVar11;
      if (iVar5 < 5) {
        *(undefined2 *)(piVar10 + 0xd) = 0;
        *(undefined2 *)((int)piVar10 + 0x36) = 0;
      }
      else {
        uVar4 = FUN_00621860();
        *(undefined2 *)(piVar10 + 0xd) = uVar4;
        uVar4 = FUN_00621860();
        *(undefined2 *)((int)piVar10 + 0x36) = uVar4;
      }
      if (iVar5 < 6) {
        piVar10[0xe] = 0x41700000;
        fVar11 = (float10)25.0;
      }
      else {
        fVar11 = (float10)FUN_006217a0();
        piVar10[0xe] = (int)(float)fVar11;
        fVar11 = (float10)FUN_006217a0();
      }
      piVar10[0xf] = (int)(float)fVar11;
      if (iVar5 < 7) {
        cVar1 = *(char *)((int)piVar10 + 0x27);
        if (cVar1 != '\x01') {
          if (cVar1 == '\x02') {
            fVar11 = (float10)0.05;
            *(undefined1 *)((int)piVar10 + 0x42) = 1;
            *(undefined1 *)((int)piVar10 + 0x43) = 1;
          }
          else {
            if (cVar1 != '\x03') goto LAB_006912a9;
            fVar11 = (float10)0;
            *(undefined1 *)((int)piVar10 + 0x42) = 0;
            *(undefined1 *)((int)piVar10 + 0x43) = 0;
          }
          goto LAB_006912a6;
        }
        *(undefined1 *)((int)piVar10 + 0x42) = 0;
        piVar10[0x11] = 0;
        *(undefined1 *)((int)piVar10 + 0x43) = 0;
        piVar10[0xe] = 0x41a00000;
        piVar10[0xf] = 0x41a00000;
      }
      else {
        uVar3 = FUN_006218c0();
        *(undefined1 *)((int)piVar10 + 0x42) = uVar3;
        uVar3 = FUN_006218c0();
        *(undefined1 *)((int)piVar10 + 0x43) = uVar3;
        fVar11 = (float10)FUN_006217a0();
LAB_006912a6:
        piVar10[0x11] = (int)(float)fVar11;
      }
LAB_006912a9:
      if ((5 < iVar5) && (*(char *)((int)piVar10 + 0x27) == '\x03')) {
        iVar6 = 0;
        iVar5 = 0;
        local_38 = 0;
        if (DAT_02962a20 == DAT_02962a0c) {
          local_38 = piVar10[1];
          piVar10[1] = 0;
        }
        else {
          iVar8 = *DAT_02962a1c;
          while (iVar8 != 0) {
            iVar5 = iVar5 + 1;
            iVar8 = DAT_02962a1c[iVar5];
          }
          *(short *)(piVar10 + 0x10) = (short)iVar5;
          DAT_02962a1c[iVar5] = 1;
          if (DAT_02962a10 < piVar10[1]) {
            local_38 = piVar10[1] - DAT_02962a10;
            piVar10[1] = DAT_02962a10;
          }
        }
        if (0 < piVar10[1]) {
          do {
            pfVar7 = (float *)((DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18);
            fVar11 = (float10)FUN_006217a0();
            *pfVar7 = (float)fVar11;
            iVar8 = (DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18;
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar8 + 4) = (float)fVar11;
            iVar8 = (DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18;
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar8 + 8) = (float)fVar11;
            iVar8 = (DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18;
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar8 + 0xc) = (float)fVar11;
            iVar8 = (DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18;
            uVar4 = FUN_00621860();
            *(undefined2 *)(iVar8 + 0x10) = uVar4;
            iVar8 = (DAT_02962a10 * iVar5 + iVar6) * 0x20 + DAT_02962a18;
            uVar4 = FUN_00621860();
            iVar6 = iVar6 + 1;
            *(undefined2 *)(iVar8 + 0x12) = uVar4;
          } while (iVar6 < piVar10[1]);
        }
        iVar5 = local_38;
        if (0 < local_38) {
          do {
            FUN_006217a0();
            FUN_006217a0();
            FUN_006217a0();
            FUN_006217a0();
            FUN_00621860();
            FUN_00621860();
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      piVar10[0x13] = local_40;
      if (local_2c < 8) {
        *(undefined4 *)((int)&DAT_0292fd10 + local_34) = 0;
      }
      else {
        *(undefined4 *)((int)&DAT_0292fd10 + local_34) = 1;
        iVar5 = 0;
        if (0 < piVar10[1]) {
          iVar6 = 0;
          do {
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar6 + piVar10[0x13]) = (float)fVar11;
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar6 + 4 + piVar10[0x13]) = (float)fVar11;
            fVar11 = (float10)FUN_006217a0();
            *(float *)(iVar6 + 8 + piVar10[0x13]) = (float)fVar11;
            iVar5 = iVar5 + 1;
            iVar6 = iVar6 + 0xc;
          } while (iVar5 < piVar10[1]);
        }
      }
      if (piVar10[1] < 4) {
        piVar10[1] = 4;
      }
      if (*piVar10 == -1) {
        piVar10[1] = 0;
      }
      if ((local_24 % DAT_00810a70 == 0) || (DAT_02962928 != 0)) {
        if ((DAT_00810a74 != 1) && (DAT_02962928 == 0)) {
          piVar10[1] = (DAT_00810a74 + -1 + piVar10[1]) / DAT_00810a74;
        }
      }
      else {
        piVar10[1] = 0;
      }
      if (0 < piVar10[1]) {
        DAT_029629e0 = DAT_029629e0 + 1;
        DAT_029629fc = local_40 + piVar10[1] * 0xc;
        DAT_00810a8c = local_3c;
        local_40 = DAT_029629fc;
      }
      local_24 = local_24 + 1;
    } while (local_24 < local_20);
  }
  FUN_006211b0(0);
  FUN_006213e0();
  DAT_02921884 = 0xffffffff;
  FUN_00690e40(0x3f800000);
  *(undefined4 *)(&DAT_02961f54 + local_34) = local_28;
  *(undefined4 *)((int)&DAT_02920acc + local_34) = 1;
  *(undefined4 *)(&DAT_02921844 + local_34) = param_3;
  uVar2 = DAT_0292fc68;
  if (*(int *)((int)&DAT_0292fd10 + local_34) != 0) {
    DAT_0292fc68 = param_3;
    FUN_0065e0e0(local_30,0);
  }
  DAT_0292fc68 = uVar2;
  if ((DAT_02962928 != 1) || (DAT_02962a04 == 0)) {
    *local_1c = local_40;
  }
  __security_check_cookie(local_4 ^ (uint)&local_40);
  return;
}

