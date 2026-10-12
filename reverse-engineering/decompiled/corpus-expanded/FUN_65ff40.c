/* Ghidra pseudocode, not original source.
 * ev_3c91a6b80548833a29ecc2d389e89e55b74ab0261b3e94a742c4850371a9aab1
 * Entry: 0x65ff40; label: FUN_0065ff40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ff40(void)

{
  int iVar1;
  float *pfVar2;
  
  FUN_00621140();
  FUN_0065f8f0();
  if (DAT_02921884 != -1) {
    iVar1 = DAT_02921884 * 0x50 + DAT_02962a14;
    if (*(char *)(iVar1 + 0x27) == '\x03') {
      if (DAT_029629f8 == 1) {
        FUN_0065bf70(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                     *(undefined4 *)(iVar1 + 0x10),0x3e000000,0xffff0000,DAT_02961ffc);
        if (DAT_02920ab4 != -1) {
          iVar1 = DAT_02921884 * 0x50 + DAT_02962a14;
          pfVar2 = (float *)(DAT_02962a18 +
                            (*(short *)(iVar1 + 0x40) * DAT_02962a10 + DAT_02920ab4) * 0x20);
          FUN_0065c050(*(float *)(iVar1 + 8) + *pfVar2,pfVar2[1] + *(float *)(iVar1 + 0xc),
                       pfVar2[2] + *(float *)(iVar1 + 0x10),0x3e000000,0xff80ffff,DAT_02961ffc);
        }
      }
      else {
        FUN_0065bf70(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                     *(undefined4 *)(iVar1 + 0x10),0x3e000000,0xff80ffff,DAT_02961ffc);
      }
    }
    else {
      FUN_0065bf70(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                   *(undefined4 *)(iVar1 + 0x10),0x3e000000,0xff80ffff,DAT_02961ffc);
      iVar1 = DAT_02921884 * 0x50 + DAT_02962a14;
      if ((*(char *)(iVar1 + 0x25) == '\x03') || (*(char *)(iVar1 + 0x25) == '\x04')) {
        FUN_0065bb50(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                     *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),0,
                     *(undefined4 *)(iVar1 + 0x14),0,0,0,(int)*(short *)(iVar1 + 0x34),
                     (int)*(short *)(iVar1 + 0x36),0xff80ffff,DAT_02961ffc);
      }
      else {
        FUN_0065c2f0(iVar1 + 8,*(undefined4 *)(iVar1 + 0x14),0xff80ffff,DAT_02961ffc,
                     (int)*(short *)(iVar1 + 0x34),(int)*(short *)(iVar1 + 0x36));
      }
    }
  }
  if (DAT_02962988 != 0) {
    FUN_00626b50(DAT_02962988);
  }
  return;
}

