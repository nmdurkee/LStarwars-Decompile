/* Ghidra analysis pseudocode, not original source.
 * ev_798b10c68707b8e82eaac4021b8b987befb8ed65c6c28839f1f848362e912a18
 * Entry: 0x584d50; label: FUN_00584d50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00584d50(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
    if (iVar1 == 0) {
      _DAT_0095440c = _DAT_0095440c | 1;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      _DAT_0095440c = _DAT_0095440c & 0xfffffffe;
    }
  }
  return;
}

