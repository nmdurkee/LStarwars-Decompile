/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612ba0; label: FUN_00612ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00612ba0(int param_1)

{
  int in_ECX;
  
  if ((param_1 != 0) && (*(int *)(in_ECX + 0x3c + param_1 * 0x18) != 0)) {
    return in_ECX + (param_1 * 3 + 6) * 8;
  }
  return 0;
}

