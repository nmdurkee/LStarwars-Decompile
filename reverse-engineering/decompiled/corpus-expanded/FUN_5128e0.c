/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x5128e0; label: FUN_005128e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005128e0(int param_1)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX - param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

