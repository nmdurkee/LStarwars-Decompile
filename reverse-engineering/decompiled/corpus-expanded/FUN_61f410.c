/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f410; label: FUN_0061f410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f410(void)

{
  if ((DAT_02912e8c != 0) &&
     (((*(int *)(DAT_02912e8c + 0x10) == 0 || (*(int *)(DAT_02912e8c + 0x14) == 0)) &&
      (*(int *)(DAT_02912e8c + 0x20) != 0)))) {
    DAT_02912e8c = 0;
  }
  return;
}

