/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x4890e0; label: FUN_004890e0
 */

undefined4 FUN_004890e0(void)

{
  int iVar1;
  int iVar2;
  int in_EDX;
  
  iVar1 = DAT_0087b2c4;
  if ((in_EDX != -1) && (DAT_0087b2c4 < 0x30)) {
    if (DAT_0087b2c4 < 2) {
      (&DAT_0093d590)[DAT_0087b2c4] = (short)in_EDX;
    }
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        if (*(short *)(&DAT_0087a840 + iVar2) == in_EDX) {
          return 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
    }
    *(short *)(&DAT_0087a840 + iVar1) = (short)in_EDX;
    *(undefined2 *)((int)&DAT_0087a840 + iVar1 * 4 + 2) = 1;
    DAT_0087b2c4 = iVar1 + 1;
    *(undefined2 *)(&DAT_0087a840 + DAT_0087b2c4) = 0xffff;
    return 1;
  }
  return 0;
}

