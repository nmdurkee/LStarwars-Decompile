/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68bbe0; label: FUN_0068bbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068bbe0(int param_1)

{
  if ((&DAT_02924b60)[param_1 * 0x16] != -1) {
    if ((&DAT_02924b60)[param_1 * 0x16] != 99999) {
      FUN_00684400(&DAT_02924b60 + param_1 * 0x16);
    }
    DAT_02962a2c = DAT_02962a2c + -1;
    (&DAT_02924b60)[param_1 * 0x16] = 0xffffffff;
  }
  return;
}

