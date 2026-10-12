/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e5770; label: FUN_004e5770
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5770(int param_1)

{
  float *pfVar1;
  char cVar2;
  float fVar3;
  undefined2 uVar4;
  int iVar5;
  float10 fVar6;
  float local_8;
  
  *(undefined4 *)(param_1 + 0x218) = *(undefined4 *)(param_1 + 0x21c);
  iVar5 = *(int *)(param_1 + 0xca4);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x5c);
  pfVar1 = (float *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0x88);
  *(undefined1 *)(param_1 + 0x282) = *(undefined1 *)(param_1 + 0x281);
  *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar5 + 0x28);
  *(undefined2 *)(iVar5 + 0x58) = *(undefined2 *)(iVar5 + 0x26);
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffffbfff;
  *(undefined2 *)(param_1 + 0x1060) = *(undefined2 *)(param_1 + 0x27a);
  *(undefined1 *)(param_1 + 0x107a) = 0;
  if (*(char *)(param_1 + 0x288) == '\0') {
    fVar3 = _DAT_00925018 + *(float *)(param_1 + 0xf10);
  }
  else {
    fVar3 = 0.0;
  }
  cVar2 = *(char *)(param_1 + 0x7b5);
  *(float *)(param_1 + 0xf10) = fVar3;
  if (cVar2 == '+') {
    *(float *)(param_1 + 0xd98) = *(float *)(param_1 + 0xd98) + _DAT_00925018;
  }
  if (cVar2 != '*') {
    if (0x8000 < *(ushort *)(param_1 + 0x5a) == 0x8000 < *(ushort *)(DAT_0093d810 + 0x5a)) {
      if ((*(char *)(DAT_0093d810 + 0x7b5) != '*') ||
         (_DAT_007fc040 * 0.5 <= *(float *)(DAT_0093d810 + 0x77c))) {
        if ((cVar2 != '6') &&
           ((*(char *)(DAT_0093d810 + 0x7b5) == '6' &&
            (*(float *)(DAT_0093d810 + 0x77c) < _DAT_007fc044 * 0.75)))) {
          *(undefined1 *)(param_1 + 0x7b5) = 0x36;
          *(undefined2 *)(param_1 + 0x7aa) = 1;
          *(float *)(param_1 + 0x784) = _DAT_007fc044;
          *(float *)(param_1 + 0x77c) = _DAT_007fc044;
        }
      }
      else {
        FUN_0049ad40(param_1);
      }
    }
    else {
      FUN_0049ad40(param_1);
    }
  }
  if (*(char *)(param_1 + 0x7b5) == '*') {
    fVar3 = *(float *)(param_1 + 0x77c) / _DAT_007fc040;
    if (*(ushort *)(param_1 + 0x5a) < 0x8001) {
      fVar3 = _DAT_00889624 + -_DAT_00800148 * fVar3 + _DAT_00800148 * (1.0 - fVar3);
    }
    else {
      fVar3 = _DAT_00889624 + _DAT_00800148 * fVar3 + -_DAT_00800148 * (1.0 - fVar3);
    }
  }
  else if (*(ushort *)(param_1 + 0x5a) < 0x8001) {
    fVar3 = _DAT_00889624 - _DAT_00800148;
  }
  else {
    fVar3 = _DAT_00889624 + _DAT_00800148;
  }
  fVar6 = (float10)FUN_0054fb40(*pfVar1,fVar3,_DAT_00800158);
  *pfVar1 = (float)fVar6;
  fVar6 = (float10)FUN_00498320(param_1);
  local_8 = (float)((float10)*(float *)(param_1 + 0xe88) + (float10)_DAT_00889628 + fVar6);
  if (_DAT_00800170 < local_8 - *(float *)(param_1 + 0x60)) {
    local_8 = _DAT_00800170 + *(float *)(param_1 + 0x60);
  }
  fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x60),local_8,_DAT_0080015c);
  *(float *)(param_1 + 0x60) = (float)fVar6;
  fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 100),
                                *(float *)(param_1 + 0xe8c) + _DAT_0088962c,_DAT_00800160);
  *(float *)(param_1 + 100) = (float)fVar6;
  iVar5 = param_1 + 0x68;
  FUN_005b3800(iVar5,pfVar1,param_1 + 0x8c);
  FUN_005b3830(iVar5,iVar5,1.0 / _DAT_00925018);
  if ((*(byte *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 1) != 0) {
    cVar2 = *(char *)(param_1 + 0x7b5);
    if (((cVar2 == '*') || (cVar2 == '6')) || (cVar2 == ':')) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_006e6b90();
    }
    if (*(ushort *)(DAT_0093d810 + 0x5a) < 0x8000) {
      iVar5 = -iVar5;
    }
    if (iVar5 < -0x10000) {
      iVar5 = -0x10000;
    }
    else if (0x10000 < iVar5) {
      iVar5 = 0x10000;
    }
    iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
    if (iVar5 < -0x2000) {
      iVar5 = -0x2000;
    }
    else if (0x2000 < iVar5) {
      iVar5 = 0x2000;
    }
    uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0xe18),iVar5,0x41000000);
    *(undefined2 *)(param_1 + 0xe18) = uVar4;
  }
  FUN_0062b040(param_1);
  FUN_0055d2b0(param_1);
  return;
}

