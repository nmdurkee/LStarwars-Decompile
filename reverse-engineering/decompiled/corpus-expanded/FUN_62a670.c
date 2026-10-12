/* Ghidra pseudocode, not original source.
 * ev_ca5ea7f3b5788154105ce78c12a6b4d3dd45520787e3b427f0542ab309566885
 * Entry: 0x62a670; label: FUN_0062a670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0062a670(int param_1,int param_2)

{
  float10 fVar1;
  
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    fVar1 = (float10)FUN_005ca470(*(undefined4 *)(*(int *)(param_1 + 0xc) + param_2 * 4));
    return fVar1;
  }
  return (float10)0;
}

