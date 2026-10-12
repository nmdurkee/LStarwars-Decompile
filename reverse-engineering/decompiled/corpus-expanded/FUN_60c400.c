/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c400; label: FUN_0060c400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060c400(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x89) != '\0') {
    FUN_0060a910();
    return;
  }
  return;
}

