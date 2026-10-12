/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43bc00; label: FUN_0043bc00
 */

uint FUN_0043bc00(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_004f8b10(param_1,"Everyone");
  if (iVar2 == 0) {
    return 0x40;
  }
  if (DAT_00951374 != (short *)0x0) {
    uVar3 = 0;
    sVar1 = *DAT_00951374;
    while ((sVar1 != -1 && ((int)uVar3 < 0x40))) {
      iVar2 = FUN_004f8b10(param_1,*(undefined4 *)
                                    (DAT_00951374[uVar3 * 2] * 0x4c + 0xc +
                                    *(int *)(DAT_029130e4 + 0x20)));
      if (iVar2 == 0) {
        return uVar3 & 0xff;
      }
      uVar3 = uVar3 + 1;
      sVar1 = DAT_00951374[uVar3 * 2];
    }
  }
  return 0xff;
}

