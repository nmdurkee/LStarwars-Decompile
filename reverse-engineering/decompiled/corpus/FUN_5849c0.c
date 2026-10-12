/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x5849c0; label: FUN_005849c0
 */

void FUN_005849c0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_004f7fb0(param_1);
  if (iVar2 != 0) {
    uVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    *(undefined1 *)(DAT_00954404 + 0x11c) = uVar1;
  }
  return;
}

