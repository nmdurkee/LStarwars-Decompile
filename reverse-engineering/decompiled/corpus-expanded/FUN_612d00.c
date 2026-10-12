/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612d00; label: FUN_00612d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00612d00(int param_1)

{
  int in_ECX;
  
  if (param_1 - 1U < 0x800) {
    return *(undefined4 *)(in_ECX + 0x3c + param_1 * 0x18);
  }
  return 0;
}

