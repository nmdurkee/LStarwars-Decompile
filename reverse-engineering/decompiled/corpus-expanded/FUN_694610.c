/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694610; label: FUN_00694610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694610(void)

{
  uint *puVar1;
  int in_ECX;
  
  puVar1 = (uint *)(*(int *)(in_ECX + 0x20) + 0x38);
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}

