/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56c7a0; label: FUN_0056c7a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056c7a0(int param_1)

{
  char cVar1;
  float fVar2;
  undefined1 uVar3;
  short sVar4;
  int iVar5;
  
  if (_DAT_00802834 != -1) {
    if (*(char *)(param_1 + 0x7b5) == _DAT_00802834) {
      if (((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) &&
         (*(char *)(param_1 + 0x7b6) != '\x05')) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        return;
      }
      if (*(char *)(param_1 + 0x281) != '\0') {
LAB_0056c886:
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if (*(char *)(param_1 + 0x284) != *(char *)(param_1 + 0x7b6)) {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        return;
      }
      if ((*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) ||
         (sVar4 = DAT_00804c40, DAT_00804c40 == -1)) {
        sVar4 = DAT_00804c3c;
      }
      *(short *)(param_1 + 0x7aa) = sVar4;
      if ((*(char *)(param_1 + 0x1078) == '\0') ||
         (*(char *)(param_1 + 0x6c0) != *(char *)(param_1 + 0x7b6))) {
        fVar2 = *(float *)(param_1 + 0x784) - _DAT_00925018;
        *(float *)(param_1 + 0x784) = fVar2;
        if (fVar2 < 0.0 == (fVar2 == 0.0)) {
          return;
        }
        goto LAB_0056c886;
      }
      *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
    }
    else {
      if (*(char *)(param_1 + 0x281) != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x1078) == '\0') {
        return;
      }
      iVar5 = FUN_0056bfb0(param_1,(int)*(char *)(param_1 + 0x6c0));
      if (iVar5 == 0) {
        return;
      }
      if (-DAT_029959a0 <= *(float *)(param_1 + 0x6b8)) {
        return;
      }
      cVar1 = *(char *)(param_1 + 0x7b5);
      if ((cVar1 != -1) && ((DAT_00802830 == -1 || (cVar1 != DAT_00802830)))) {
        if (DAT_00802838 == -1) {
          return;
        }
        if (cVar1 != DAT_00802838) {
          return;
        }
        if (*(float *)(param_1 + 0x77c) < 0.1) {
          return;
        }
      }
      uVar3 = DAT_00802834;
      *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
      *(undefined1 *)(param_1 + 0x7b5) = uVar3;
      *(short *)(param_1 + 0x7aa) = DAT_00804c3c;
      *(undefined1 *)(param_1 + 0x7b6) = *(undefined1 *)(param_1 + 0x6c0);
    }
    *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x6b4);
    *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x6b8);
    *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 0x6bc);
  }
  return;
}

