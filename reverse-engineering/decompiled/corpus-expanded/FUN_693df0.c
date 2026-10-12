/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x693df0; label: FUN_00693df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00693df0(int param_1)

{
  int in_ECX;
  
  if (param_1 != *(int *)(in_ECX + 0x18)) {
    *(int *)(in_ECX + 0x18) = param_1;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  return;
}

