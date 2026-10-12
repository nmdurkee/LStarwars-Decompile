/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c760; label: FUN_0060c760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060c760(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    FUN_006e85b0(*(undefined4 *)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}

