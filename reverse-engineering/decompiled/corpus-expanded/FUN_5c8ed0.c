/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8ed0; label: FUN_005c8ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c8ed0(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) != '\0') &&
     ((0 < *(int *)(in_ECX + 0x54) || (0 < *(int *)(in_ECX + 0xd8))))) {
    return 1;
  }
  return 0;
}

