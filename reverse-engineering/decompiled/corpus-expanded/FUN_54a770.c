/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a770; label: FUN_0054a770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0054a770(int param_1)

{
  uint uVar1;
  
  if (((*(float *)(param_1 + 0x28) == 0.0) ||
      (uVar1 = FUN_00550040(*(undefined2 *)(param_1 + 0x58),*(undefined2 *)(param_1 + 0x26)),
      (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 0x2001)) &&
     ((*(float *)(param_1 + 0x28) == 0.0 || (*(float *)(param_1 + 0x38) != 0.0)))) {
    if ((*(float *)(param_1 + 0x28) == 0.0) && (*(float *)(param_1 + 0x38) != 0.0)) {
      return 1;
    }
    return 0;
  }
  return 1;
}

