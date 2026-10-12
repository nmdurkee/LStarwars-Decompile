/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x6240b0; label: FUN_006240b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006240b0(undefined4 *param_1)

{
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    if (param_1[2] == 0) {
      *(byte *)((int)param_1 + 0x11) = *(byte *)((int)param_1 + 0x11) & 0xfe;
    }
  }
  return;
}

