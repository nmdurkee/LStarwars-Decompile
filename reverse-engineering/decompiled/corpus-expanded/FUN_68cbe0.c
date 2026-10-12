/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68cbe0; label: FUN_0068cbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068cbe0(void)

{
  if ((DAT_00810ad8 != -1) && (*(int *)(DAT_0296209c + DAT_00810ad8 * 4) != 0)) {
    if (**(char **)(DAT_0296209c + DAT_00810ad8 * 4) == '\0') {
      FUN_00663aa0("Name Duplicate",0);
      return;
    }
    FUN_00624220(DAT_02924b30);
    DAT_02924b30 = 0;
  }
  return;
}

