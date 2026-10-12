/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x5173b0; label: FUN_005173b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005173b0(int param_1,float *param_2)

{
  if ((((*(float *)(param_1 + 0x90) <= *param_2) && (*(float *)(param_1 + 0x94) <= param_2[1])) &&
      (*(float *)(param_1 + 0x98) <= param_2[2])) &&
     (((*param_2 <= *(float *)(param_1 + 0x9c) && (param_2[1] <= *(float *)(param_1 + 0xa0))) &&
      (param_2[2] <= *(float *)(param_1 + 0xa4))))) {
    return 1;
  }
  return 0;
}

