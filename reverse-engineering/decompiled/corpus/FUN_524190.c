/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x524190; label: FUN_00524190
 */

void FUN_00524190(void)

{
  int iVar1;
  char cVar2;
  
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x31b8c); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x31b8c,iVar1)) {
    *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) & 0xfffe;
  }
  if (((byte)DAT_00921f50 & 2) == 0) {
    FUN_00523c40(*(undefined4 *)(DAT_009238e4 + 0x4868));
  }
  else {
    cVar2 = '\0';
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
      *(char *)(iVar1 + 0x38) = cVar2;
      cVar2 = cVar2 + '\x01';
    }
    if (*(int *)(DAT_009238e4 + 0x4868) != 0) {
      FUN_00523c40(*(undefined4 *)(DAT_009238e4 + 0x4868));
    }
    iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874);
    if (iVar1 != 0) {
      do {
        if (*(int *)(DAT_009238e4 + 0x4868) != iVar1) {
          FUN_00523c40(iVar1);
        }
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1);
      } while (iVar1 != 0);
      return;
    }
  }
  return;
}

