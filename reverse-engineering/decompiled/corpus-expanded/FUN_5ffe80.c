/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x5ffe80; label: FUN_005ffe80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005ffe80(int param_1,undefined4 *param_2)

{
  *param_2 = 0xa4c;
  return param_1 + 0xfU & 0xfffffff0;
}

