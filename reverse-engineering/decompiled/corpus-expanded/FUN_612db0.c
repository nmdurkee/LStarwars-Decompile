/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x612db0; label: FUN_00612db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612db0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) < 3) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  return;
}

