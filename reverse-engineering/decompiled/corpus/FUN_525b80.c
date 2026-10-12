/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x525b80; label: FUN_00525b80
 */

void FUN_00525b80(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
      for (iVar2 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18); iVar2 != 0;
          iVar2 = FUN_004f1460(*(int *)(DAT_009238e4 + 0x4868) + 0x18,iVar2)) {
        if (*(int *)(iVar2 + 0xb0) == unaff_EDI) {
          *(undefined4 *)(iVar2 + 0xb0) = 0;
          break;
        }
      }
    }
    FUN_004f1410(DAT_009238e4 + 0x31b8c);
    FUN_004f1310(DAT_009238e4 + 0x31b84);
  }
  return;
}

