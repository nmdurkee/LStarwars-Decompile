/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f660; label: FUN_0056f660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_0056f660(int *param_1)

{
  return *(byte *)(*param_1 + 0x17) >> 3 & 1;
}

