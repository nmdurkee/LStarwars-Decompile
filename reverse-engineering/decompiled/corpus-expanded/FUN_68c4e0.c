/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68c4e0; label: FUN_0068c4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068c4e0(void)

{
  int *piVar1;
  
  piVar1 = &DAT_02924b60;
  do {
    if (*piVar1 != -1) {
      if (*piVar1 != 99999) {
        FUN_00684400(piVar1);
      }
      DAT_02962a2c = DAT_02962a2c + -1;
      *piVar1 = -1;
    }
    piVar1 = piVar1 + 0x16;
  } while ((int)piVar1 < 0x292fb60);
  return;
}

