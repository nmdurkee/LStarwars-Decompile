/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54b6d0; label: FUN_0054b6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

