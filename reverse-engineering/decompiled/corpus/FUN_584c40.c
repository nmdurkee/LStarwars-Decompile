/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x584c40; label: FUN_00584c40
 */

void FUN_00584c40(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00954410 == '\0') {
    iVar1 = FUN_00584a70(param_1);
  }
  else {
    iVar1 = FUN_00584ad0(param_1);
  }
  if (iVar1 != 0) {
    *(undefined4 *)(DAT_00954404 + 0xa8) = *(undefined4 *)(DAT_00954404 + 0xa4);
  }
  return;
}

