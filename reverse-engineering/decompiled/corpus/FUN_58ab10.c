/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58ab10; label: FUN_0058ab10
 */

void FUN_0058ab10(undefined2 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_ESI;
  undefined2 *unaff_EDI;
  
  iVar3 = FUN_004f7fb0();
  while (iVar3 != 0) {
    iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"character");
    if (iVar3 == 0) {
      iVar3 = FUN_004f7fb0();
      if (iVar3 != 0) {
        uVar2 = FUN_0055b1c0(*(undefined4 *)(unaff_ESI + 0x510));
        *param_1 = uVar2;
      }
    }
    else {
      iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"variant");
      if (iVar3 == 0) {
        iVar3 = FUN_004f7fb0();
        if (iVar3 != 0) {
          uVar1 = FUN_0055c0a0(*(undefined4 *)(unaff_ESI + 0x510));
          *param_2 = uVar1;
        }
      }
      else {
        iVar3 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),"action");
        if ((iVar3 == 0) && (iVar3 = FUN_004f7fb0(), iVar3 != 0)) {
          uVar2 = FUN_00630740(*(undefined4 *)(unaff_ESI + 0x510));
          *unaff_EDI = uVar2;
        }
      }
    }
    iVar3 = FUN_004f7fb0();
  }
  return;
}

