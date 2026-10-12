/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a87c0; label: FUN_006a87c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a87c0(void *param_1)

{
  if (*(int *)((int)param_1 + 0x30) != 0) {
    FUN_006a86f0(param_1);
    _free(param_1);
  }
  return;
}

