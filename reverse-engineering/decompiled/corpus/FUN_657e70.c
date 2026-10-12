/* Ghidra analysis pseudocode, not original source.
 * ev_f0b2ce2d5885583ae7420409f057ba3a395d2cbd12cd318b48692f86b50c0045
 * Entry: 0x657e70; label: FUN_00657e70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00657e70(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float local_8;
  float local_4;
  
  local_4 = 0.0;
  iVar4 = 0;
  iVar2 = 1;
  if (3 < DAT_02962098 + -1) {
    piVar3 = (int *)(DAT_0296209c + 0xc);
    do {
      if ((piVar3[-2] != 0) && (iVar1 = piVar3[-2], *(int *)(iVar1 + 0x2a8) != 0)) {
        if (*(char *)(iVar1 + 0x2f1) == '\x04') {
          local_8 = _DAT_02962060;
        }
        else {
          local_8 = _DAT_0296205c;
        }
        local_8 = local_8 - *(float *)(iVar1 + 0x2ac);
        if (local_4 < local_8) {
          iVar4 = iVar2;
          local_4 = local_8;
        }
      }
      if ((piVar3[-1] != 0) && (iVar1 = piVar3[-1], *(int *)(iVar1 + 0x2a8) != 0)) {
        if (*(char *)(iVar1 + 0x2f1) == '\x04') {
          local_8 = _DAT_02962060;
        }
        else {
          local_8 = _DAT_0296205c;
        }
        local_8 = local_8 - *(float *)(iVar1 + 0x2ac);
        if (local_4 < local_8) {
          iVar4 = iVar2 + 1;
          local_4 = local_8;
        }
      }
      if ((*piVar3 != 0) && (iVar1 = *piVar3, *(int *)(iVar1 + 0x2a8) != 0)) {
        if (*(char *)(iVar1 + 0x2f1) == '\x04') {
          local_8 = _DAT_02962060;
        }
        else {
          local_8 = _DAT_0296205c;
        }
        local_8 = local_8 - *(float *)(iVar1 + 0x2ac);
        if (local_4 < local_8) {
          iVar4 = iVar2 + 2;
          local_4 = local_8;
        }
      }
      if ((piVar3[1] != 0) && (iVar1 = piVar3[1], *(int *)(iVar1 + 0x2a8) != 0)) {
        if (*(char *)(iVar1 + 0x2f1) == '\x04') {
          local_8 = _DAT_02962060;
        }
        else {
          local_8 = _DAT_0296205c;
        }
        local_8 = local_8 - *(float *)(iVar1 + 0x2ac);
        if (local_4 < local_8) {
          iVar4 = iVar2 + 3;
          local_4 = local_8;
        }
      }
      iVar2 = iVar2 + 4;
      piVar3 = piVar3 + 4;
    } while (iVar2 < DAT_02962098 + -3);
  }
  for (; iVar2 < DAT_02962098; iVar2 = iVar2 + 1) {
    if ((*(int *)(DAT_0296209c + iVar2 * 4) != 0) &&
       (iVar1 = *(int *)(DAT_0296209c + iVar2 * 4), *(int *)(iVar1 + 0x2a8) != 0)) {
      if (*(char *)(iVar1 + 0x2f1) == '\x04') {
        local_8 = _DAT_02962060;
      }
      else {
        local_8 = _DAT_0296205c;
      }
      local_8 = local_8 - *(float *)(iVar1 + 0x2ac);
      if (local_4 < local_8) {
        iVar4 = iVar2;
        local_4 = local_8;
      }
    }
  }
  if (iVar4 != 0) {
    DAT_02924b44 = DAT_02924b44 + -1;
    *(undefined4 *)(DAT_02962090 + DAT_02924b44 * 4) =
         *(undefined4 *)(*(int *)(DAT_0296209c + iVar4 * 4) + 0x2a8);
    *(undefined4 *)(*(int *)(DAT_0296209c + iVar4 * 4) + 0x2a8) = 0;
  }
  return;
}

