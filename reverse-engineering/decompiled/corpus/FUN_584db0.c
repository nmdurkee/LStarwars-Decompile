/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x584db0; label: FUN_00584db0
 */

void FUN_00584db0(int param_1)

{
  uint in_EAX;
  int iVar1;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 4) = *(uint *)(unaff_ESI + 4) | in_EAX;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(unaff_ESI + 4) = *(uint *)(unaff_ESI + 4) & ~in_EAX;
    }
  }
  return;
}

