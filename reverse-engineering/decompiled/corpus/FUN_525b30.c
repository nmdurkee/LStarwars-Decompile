/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x525b30; label: FUN_00525b30
 */

int FUN_00525b30(void)

{
  int iVar1;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x31b84);
  if (iVar1 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x31b84,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x31b8c,iVar1);
  }
  return iVar1;
}

