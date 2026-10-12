/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x5ffea0; label: FUN_005ffea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ffea0(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)(param_1 + -4 + param_2 * 4);
  *puVar1 = 0x52;
  *(undefined4 *)(puVar1 + 4) = 0;
  param_2 = param_2 + -2;
  while (-1 < param_2) {
    param_2 = param_2 + -1;
    puVar1 = *(undefined1 **)(param_1 + 4 + param_2 * 4);
    *puVar1 = 0x4e;
    *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_1 + 8 + param_2 * 4);
  }
  return;
}

