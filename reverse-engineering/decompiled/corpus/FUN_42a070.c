/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42a070; label: FUN_0042a070
 */

undefined4 FUN_0042a070(void)

{
  int iVar1;
  undefined1 local_44 [12];
  undefined1 local_38;
  char local_37;
  
  iVar1 = FUN_0055e340(local_44,&local_38);
  if (iVar1 != 0) {
    iVar1 = *(int *)(PTR_DAT_00802c54 + 0x128);
    if (iVar1 == DAT_00951b94) {
      iVar1 = FUN_004915c0();
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b10c) {
      iVar1 = FUN_004e2300();
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b110) {
      iVar1 = FUN_004e23a0();
      if (iVar1 != 0) {
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b114) {
      iVar1 = FUN_004e2300();
      if (iVar1 == 0) {
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b19c) {
      if (local_37 == '\x03') {
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b1d4) {
      iVar1 = FUN_004e5660();
      if (iVar1 != 0) {
        DAT_00876604 = 0x1e;
        return 1;
      }
      if (0 < DAT_00876604) {
        DAT_00876604 = DAT_00876604 + -1;
        return 1;
      }
    }
    else if (iVar1 == DAT_0087b208) {
      if (PTR_DAT_008021b4[1] == '\x04') {
        return 1;
      }
    }
    else if ((iVar1 == DAT_0087b270) && (iVar1 = FUN_004ec7b0(PTR_DAT_00802c54), iVar1 != 0)) {
      return 1;
    }
  }
  return 0;
}

