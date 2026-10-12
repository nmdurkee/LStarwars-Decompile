/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42daa0; label: FUN_0042daa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0042daa0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  if (param_1 == 0) {
    return -1;
  }
  if (param_2 == 0) {
    return -1;
  }
  if ((DAT_0087b014 == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) {
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) {
      if ((param_1 != DAT_008765f0) && (param_1 != DAT_008765f4)) {
        return -1;
      }
      if (DAT_007f1b2c == -1) {
        return -1;
      }
      iVar2 = FUN_004f8b10(*(undefined4 *)
                            (DAT_007f1b2c * 0x4c + 0xc + *(int *)(DAT_029130e4 + 0x20)),
                           *(undefined4 *)(param_2 + 0x40));
      if (iVar2 != 0) {
        return -1;
      }
      if (DAT_00951bdc == 0) {
        if (*(short *)(DAT_0093d810 + 0x1064) == DAT_007f1b30) {
          return (int)DAT_007f1b30;
        }
      }
      else {
        sVar3 = DAT_007f1b30;
        if (*(short *)(DAT_00951bdc + 0x1064) == DAT_007f1b30) goto LAB_0042db55;
      }
      return (int)DAT_007f1b2c;
    }
    if ((DAT_0087b01c == 0) ||
       (sVar3 = DAT_007f19fc, iVar2 = DAT_008765d8, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b01c
       )) {
      if ((DAT_0087af78 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af78)) {
        if (param_1 != DAT_008765d8) {
          return -1;
        }
        if ((DAT_00951bdc == 0) ||
           (sVar3 = DAT_007f1a04, *(short *)(DAT_00951bdc + 0x1064) != DAT_007f1a04)) {
          return (int)DAT_007f1a00;
        }
        goto LAB_0042db55;
      }
      if (DAT_0087af80 == 0) {
        return -1;
      }
      sVar3 = DAT_007f19e4;
      iVar2 = DAT_008765e4;
      if (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af80) {
        return -1;
      }
    }
    iVar1 = DAT_00951bdc;
    if (param_1 != iVar2) {
      return -1;
    }
joined_r0x0042dc88:
    iVar2 = iVar1;
    if (iVar1 == 0) {
      return -1;
    }
  }
  else {
    if (((param_1 != DAT_008765d0) && (param_1 != DAT_008765d4)) && (param_1 != DAT_008765e8)) {
      return -1;
    }
    if (DAT_007f1b14 == -1) {
      return -1;
    }
    iVar2 = FUN_004f8b10(*(undefined4 *)(DAT_007f1b14 * 0x4c + 0xc + *(int *)(DAT_029130e4 + 0x20)),
                         *(undefined4 *)(param_2 + 0x40));
    if (iVar2 != 0) {
      return -1;
    }
    iVar2 = DAT_00951bdc;
    sVar3 = DAT_007f1b18;
    iVar1 = DAT_0093d810;
    if (DAT_00951bdc == 0) goto joined_r0x0042dc88;
  }
  if (*(short *)(iVar2 + 0x1064) != sVar3) {
    return -1;
  }
LAB_0042db55:
  return (int)sVar3;
}

