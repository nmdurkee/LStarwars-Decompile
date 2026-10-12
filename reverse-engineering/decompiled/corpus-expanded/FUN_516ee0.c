/* Ghidra pseudocode, not original source.
 * ev_8db479debe006dcb1d0ae53ec943fbf75b60233db5d397d4c7fbd4646b77bfb6
 * Entry: 0x516ee0; label: FUN_00516ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00516ee0(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 0xc0) != 0)) {
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0xc0);
    *(undefined4 *)(param_2 + 0xc0) = 0;
  }
  return 1;
}

