/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49c080; label: FUN_0049c080
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c080(int param_1)

{
  char cVar1;
  short sVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  float10 fVar8;
  
  sVar2 = *(short *)(param_1 + 0x7aa);
  bVar3 = false;
  if ((sVar2 != -1) &&
     ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + sVar2 * 4) == 0 ||
      (iVar5 = FUN_0062f150(param_1 + 8,(int)sVar2,1,0), iVar5 != 0)))) {
    bVar3 = true;
  }
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (cVar1 == '\x15') {
    if (!bVar3) {
      return;
    }
    fVar4 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar4;
    if (0.0 < fVar4) {
      return;
    }
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    return;
  }
  if (cVar1 == 'Z') {
    if (!bVar3) {
      return;
    }
    fVar4 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar4;
    if (0.0 < fVar4) {
      return;
    }
    if (*(char *)(param_1 + 0x7b3) != '\0') {
      if (*(char *)(param_1 + 0x7b3) != '\x01') {
        return;
      }
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      return;
    }
    sVar2 = *(short *)(param_1 + 0x7aa);
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x8000;
    if (sVar2 != 0xb9) {
      if (sVar2 == 0x3d) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if (sVar2 == 0xa7) {
        *(undefined2 *)(param_1 + 0x7aa) = 0xaa;
      }
      else if (sVar2 == 0xa8) {
        *(undefined2 *)(param_1 + 0x7aa) = 0xab;
      }
      else {
        *(ushort *)(param_1 + 0x7aa) = (-(ushort)(sVar2 != 0xa9) & 0xff55) + 0xac;
      }
      iVar5 = (int)*(short *)(param_1 + 0x7aa);
      *(undefined1 *)(param_1 + 0x7b3) = 1;
      if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + iVar5 * 4) != 0) &&
         ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + iVar5 * 4) + 4) & 2) == 0)) {
        fVar8 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar5,0,0,1);
        *(float *)(param_1 + 0x77c) = (float)fVar8;
        return;
      }
      *(undefined4 *)(param_1 + 0x77c) = *(undefined4 *)(param_1 + 0x778);
      return;
    }
    iVar5 = 1;
  }
  else {
    if (cVar1 != '_') {
      return;
    }
    if (!bVar3) {
      return;
    }
    fVar4 = *(float *)(param_1 + 0x77c) + _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar4;
    if (*(float *)(param_1 + 0x784) < fVar4 == (*(float *)(param_1 + 0x784) == fVar4)) {
      if (fVar4 <= 0.5) {
        return;
      }
      if ((0.0 <= *(float *)(param_1 + 0xdfc)) || (*(char *)(param_1 + 0x281) == '\0')) {
        if (*(char *)(param_1 + 0x1078) == '\0') {
          return;
        }
        if (*(float *)(param_1 + 0x1030) <= (fVar4 / *(float *)(param_1 + 0x784)) * -0.8 + 0.8) {
          return;
        }
      }
    }
    iVar5 = 2;
    if ((DAT_0093b324 != 0) &&
       ((cVar1 = *(char *)(param_1 + 0x7bb), cVar1 == '\0' || (cVar1 == '\x01')))) {
      FUN_00476250((int)cVar1,(int)*(char *)(param_1 + 0x280));
    }
  }
  FUN_00437770(param_1,0xffffffff,0xffffffff,1,0,iVar5 == 2,0);
  FUN_004364e0(param_1,2,0);
  uVar7 = 0;
  if (*(char *)(param_1 + 0x280) == -1) {
    if (DAT_00951154 == 0) {
      iVar5 = FUN_0056e160(0x10);
      if (iVar5 != 0) {
        uVar7 = 0x15e;
      }
    }
    else {
      uVar7 = *(ushort *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xee);
    }
    iVar5 = FUN_0046c4f0();
    if ((uVar7 != 0) || (iVar5 != 0)) {
      if ((DAT_00951154 == 0) && (uVar7 < 0x9c4)) {
        uVar6 = 1;
      }
      else {
        uVar6 = 0;
      }
      FUN_0046d270(uVar7,iVar5,0,0,param_1 + 0x80,0,0x40000000,0xffffffff,0x3f800000,0x49f42400,0,
                   uVar6,DAT_00951154 != 0);
      return;
    }
  }
  return;
}

