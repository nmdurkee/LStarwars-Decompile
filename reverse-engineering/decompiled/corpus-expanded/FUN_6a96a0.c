/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a96a0; label: FUN_006a96a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a96a0(int param_1,int param_2,undefined4 param_3)

{
  if (-1 < param_2) {
    if (param_2 < *(int *)(*(int *)(param_1 + 0xc) + 4)) {
      FUN_006a3570(param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 4),
                   *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2 * 4));
      return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 8) + param_2 * 4);
    }
  }
  return 0;
}

