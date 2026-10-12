/* Ghidra pseudocode, not original source.
 * ev_caced9114db7b525920ea932437f3699003d04d9c8ef381ae63c0806c98720fa
 * Entry: 0x6b8a20; label: FUN_006b8a20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006b8a20(int param_1)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(int *)(in_ECX + 4) != *(int *)(param_1 + 4));
}

