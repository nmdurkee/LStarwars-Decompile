/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f030; label: FUN_0061f030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f030(void)

{
  if ((DAT_02912eac != 0) && (*(int *)(DAT_02912eac + 0x40) != 0)) {
    FUN_0061f010(*(int *)(DAT_02912eac + 0x40));
  }
  return;
}

