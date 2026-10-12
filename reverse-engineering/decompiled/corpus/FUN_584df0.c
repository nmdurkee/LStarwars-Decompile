/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x584df0; label: FUN_00584df0
 */

void FUN_00584df0(int param_1)

{
  ushort in_AX;
  int iVar1;
  int unaff_ESI;
  
  *(ushort *)(unaff_ESI + 0x48) = *(ushort *)(unaff_ESI + 0x48) | in_AX;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(ushort *)(unaff_ESI + 0x48) = *(ushort *)(unaff_ESI + 0x48) & ~in_AX;
    }
  }
  return;
}

