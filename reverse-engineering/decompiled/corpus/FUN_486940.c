/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x486940; label: FUN_00486940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486940(int param_1)

{
  int iVar1;
  undefined4 uStack_4;
  
  if ((DAT_0087b02c != 0) && (DAT_0087a6c8 == *(byte *)(DAT_0087b02c + 0x7c))) {
    if (DAT_0087a6c4 == DAT_007f17d0) {
      DAT_0087a6c4 = DAT_007f17d4;
    }
    else if (DAT_0087a6c6 == DAT_007f17d0) {
      DAT_0087a6c6 = DAT_007f17d4;
    }
  }
  FUN_0055e1b0(1,(int)DAT_0087a6c4,(int)DAT_0087a6c6);
  iVar1 = (*DAT_0087a630)(PTR_DAT_00802c54,&DAT_0087a628,param_1);
  if (iVar1 != 0) {
    return;
  }
  DAT_00951b80 = DAT_00951b94;
  if (param_1 == 0) {
    if (((DAT_0087a6d8 & 0x100) != 0) ||
       ((DAT_007f39e4 != 0 && ((DAT_0087a6ce != '\0' || (DAT_0087a6cf != '\0')))))) {
      DAT_00951b80 = FUN_005735a0((int)*(short *)((uint)*(byte *)(DAT_0087a63c + 0x7c) * 0x9c + 0x60
                                                 + DAT_00951354));
      _DAT_0093b2ac = 0xffffffbf;
      DAT_00951368 = 1;
      uStack_4 = 2;
      FUN_005b1220(&uStack_4,0);
      FUN_00565be0(1);
      FUN_00565ba0();
      if (DAT_0087a6ce != '\0') {
        FUN_0042b4c0(*(undefined1 *)(DAT_0087a63c + 0x7c));
      }
      if (DAT_0087a6cf != '\0') {
        FUN_00497720(DAT_009553d4,(int)*(char *)(*(int *)(DAT_009553d4 + 4) + 0x12));
        DAT_00951b80 = *(short *)(*(int *)(DAT_009553d4 + 4) + 2) * 0x130 + DAT_00951b78;
      }
      goto LAB_00486b5f;
    }
    if (DAT_0087a740 != -1) {
      iVar1 = DAT_0087a740 * 0x9c + DAT_00951354;
      DAT_00951b80 = *(short *)(iVar1 + 0x60) * 0x130 + DAT_00951b78;
      if ((*(byte *)(iVar1 + 0x7a) & 2) == 0) {
        DAT_0087b2c0 = 1;
        if ((DAT_0087a6d8 & 0x400) != 0) {
          DAT_00950750 = 1;
        }
      }
      else {
        DAT_00950770 = 1;
      }
      goto LAB_00486b5f;
    }
  }
  if ((DAT_007f39e4 != 0) &&
     (((DAT_0087a6d8 & 0x400) != 0 ||
      (((*(byte *)(DAT_0087a63c + 0x7a) & 4) != 0 && ((DAT_0087a6d8 & 0x40) == 0)))))) {
    DAT_00951b80 = DAT_00951b9c;
  }
LAB_00486b5f:
  if ((DAT_0087a6d8 & 0x800) != 0) {
    DAT_00951b80 = DAT_00951b94;
  }
  if ((((*(char *)(DAT_00951b80 + 0xa3) != -1) &&
       ((*(byte *)(*(char *)(DAT_00951b80 + 0xa3) * 0x9c + 0x7a + DAT_00951354) & 0x40) != 0)) &&
      (DAT_0087a6cf != '\0')) && (*(int *)(DAT_009553d4 + 4) != 0)) {
    DAT_008059f8 = (int)*(char *)(*(int *)(DAT_009553d4 + 4) + 0x12);
  }
  if (DAT_00951b80 != DAT_00951b94) {
    DAT_00856bf0 = DAT_0086e714;
    DAT_00856bf4 = DAT_0086e718;
    FUN_00698910();
    return;
  }
  DAT_00856bf0 = 0;
  DAT_00856bf4 = 0;
  FUN_00698910();
  return;
}

