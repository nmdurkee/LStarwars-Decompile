/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513730; label: FUN_00513730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

