/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b6d0; label: FUN_0054b6d0
 */

undefined4 FUN_0054b6d0(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_007616a8);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_007616a4);
    if (iVar1 != 0) {
      iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_007616a0);
      if (iVar1 != 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_0076169c);
        if (iVar1 != 0) {
          iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_00761698);
          if (iVar1 != 0) {
            iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_00761694);
            if (iVar1 == 0) {
              FUN_004f7fb0();
              return 0;
            }
            iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&PTR_LAB_0075f78c);
            if (iVar1 != 0) {
              iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_0076168c);
              if (iVar1 != 0) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

