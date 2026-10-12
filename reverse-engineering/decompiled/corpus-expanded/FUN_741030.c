/* Ghidra pseudocode, not original source.
 * ev_d0ee5b940732101f19a6f5ed1cc5d22784960ef3dbbb4fefd6b0cd8a13c6d459
 * Entry: 0x741030; label: FUN_00741030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00741030(int *param_1)

{
  int *in_ECX;
  
  return CONCAT31((int3)((uint)*in_ECX >> 8),*in_ECX == *param_1);
}

