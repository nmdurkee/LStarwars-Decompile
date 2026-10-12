/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0570; label: FUN_005a0570
 */

void FUN_005a0570(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < DAT_00956614)) {
    iVar1 = *(int *)(DAT_0095661c + param_1 * 4);
    iVar2 = 0;
    if (0 < DAT_00956618) {
      do {
        *(undefined1 *)(iVar2 + iVar1) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_00956618);
    }
  }
  return;
}

