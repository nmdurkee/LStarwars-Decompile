/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513730; label: FUN_00513730
 */

void FUN_00513730(int param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_004f1ff0(*(undefined4 *)(param_1 + 0x510));
  if (0x1e < iVar1) {
    FUN_00512850(*(undefined4 *)(param_1 + 0x510));
  }
  FUN_004f7fb0(param_1);
  FUN_004f1f40(&DAT_009220f0 + DAT_00922244 * 0x24,*(undefined4 *)(param_1 + 0x510),0x20);
  fVar2 = (float10)FUN_004f8100(param_1);
  (&DAT_00922110)[DAT_00922244 * 9] = (float)fVar2;
  DAT_00922244 = DAT_00922244 + 1;
  return;
}

