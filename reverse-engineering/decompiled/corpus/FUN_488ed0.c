/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x488ed0; label: FUN_00488ed0
 */

undefined4 FUN_00488ed0(void)

{
  short *psVar1;
  char cVar2;
  short sVar3;
  short *in_EAX;
  int iVar4;
  
  if (in_EAX != (short *)0x0) {
    sVar3 = *in_EAX;
    while (sVar3 != -1) {
      iVar4 = FUN_00594960((int)sVar3);
      if (iVar4 != 0) {
        sVar3 = *in_EAX;
        cVar2 = *(char *)(sVar3 * 0x120 + 0x116 + DAT_0093b284);
        if ((((cVar2 == '\x01') || (cVar2 == '\b')) || (sVar3 == DAT_007f199c)) ||
           (((sVar3 == DAT_007f19a0 || (sVar3 == DAT_007f1a4c)) ||
            ((sVar3 == DAT_007f1a48 || (sVar3 == DAT_007f1a44)))))) {
          return 1;
        }
      }
      psVar1 = in_EAX + 2;
      in_EAX = in_EAX + 2;
      sVar3 = *psVar1;
    }
  }
  return 0;
}

