/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a04f0; label: FUN_005a04f0
 */

void FUN_005a04f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) && (-1 < param_2)) &&
     (param_2 < DAT_00956614)) {
    iVar1 = *(int *)(DAT_0095661c + param_2 * 4);
    iVar2 = 0;
    if (0 < DAT_00956618) {
      do {
        if (*(int *)(*(int *)(param_1 + 0xc) + iVar2 * 4) == 0) {
          return;
        }
        *(undefined1 *)(iVar2 + iVar1) =
             *(undefined1 *)(*(int *)(*(int *)(param_1 + 0xc) + iVar2 * 4) + 0xc);
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_00956618);
    }
  }
  return;
}

