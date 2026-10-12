/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e8d20; label: FUN_004e8d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e8d20(undefined1 *param_1)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    param_1[1] = 0;
    param_1[2] = 1;
    param_1[4] = 0xff;
  }
  return;
}

