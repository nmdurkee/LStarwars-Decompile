/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x449e10; label: FUN_00449e10
 */

undefined4 FUN_00449e10(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if (((*(byte *)(iVar1 + 0x144) & 1) != 0) && (*(code **)(iVar1 + 0x1c0) == FUN_0042d000)) {
        FUN_0064ac90(iVar1,0);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x220;
    } while (iVar2 < DAT_0081020c);
  }
  return 1;
}

