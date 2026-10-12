/* Ghidra pseudocode, not original source.
 * ev_caced9114db7b525920ea932437f3699003d04d9c8ef381ae63c0806c98720fa
 * Entry: 0x6b89e0; label: FUN_006b89e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006b89e0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) != 0;
}

