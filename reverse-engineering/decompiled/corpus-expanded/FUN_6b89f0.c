/* Ghidra pseudocode, not original source.
 * ev_caced9114db7b525920ea932437f3699003d04d9c8ef381ae63c0806c98720fa
 * Entry: 0x6b89f0; label: FUN_006b89f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b89f0(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == *(int *)(param_1 + 4)) &&
     (*(int *)(in_ECX + 8) == *(int *)(param_1 + 8))) {
    return 1;
  }
  return 0;
}

