/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a6a0; label: FUN_0062a6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 FUN_0062a6a0(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x48);
  }
  return 0;
}

