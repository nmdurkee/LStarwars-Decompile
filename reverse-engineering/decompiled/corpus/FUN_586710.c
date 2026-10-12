/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x586710; label: FUN_00586710
 */

void FUN_00586710(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(DAT_00954404 + 0x10e);
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (iVar1 + 1U < 0x11) {
      *puVar2 = (char)iVar1;
    }
  }
  return;
}

