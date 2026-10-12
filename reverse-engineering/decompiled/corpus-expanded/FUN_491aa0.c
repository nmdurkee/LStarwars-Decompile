/* Ghidra pseudocode, not original source.
 * ev_f838318f8db109b6dcd3b75a6a424a1459b1413cbbc9987106adb019bff4cb04
 * Entry: 0x491aa0; label: FUN_00491aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00491aa0(undefined4 param_1)

{
  if (DAT_007f23a8 != -1) {
    FUN_004bde10(param_1);
    DAT_007f23a8 = -1;
  }
  if (DAT_00951b50 == 0) {
    if ((DAT_0087b460 == -1) && (FUN_00491840(param_1), DAT_00951b50 != 0)) {
      return;
    }
    if (DAT_0087a908 != 0) {
      if (DAT_0087684a != '\0') {
        *(uint *)(DAT_0087a908 + 0x9c) = *(uint *)(DAT_0087a908 + 0x9c) | 4;
        *(uint *)(DAT_0087a908 + 0x9c) = *(uint *)(DAT_0087a908 + 0x9c) & 0xfffffff7;
        return;
      }
      *(uint *)(DAT_0087a908 + 0x9c) = *(uint *)(DAT_0087a908 + 0x9c) & 0xfffffffb;
      *(uint *)(DAT_0087a908 + 0x9c) = *(uint *)(DAT_0087a908 + 0x9c) | 8;
    }
  }
  return;
}

