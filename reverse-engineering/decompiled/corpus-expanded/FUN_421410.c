/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421410; label: FUN_00421410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00421410(int param_1)

{
  if (param_1 < 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(&DAT_007f295c + param_1 * 4);
}

