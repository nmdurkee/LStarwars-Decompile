/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64b860; label: FUN_0064b860
 */

void FUN_0064b860(int param_1)

{
  if ((&DAT_0291f7b4)[param_1 * 0x1b] != -1) {
    DAT_02920a98 = DAT_02920a98 + -1;
    (&DAT_0291f7b4)[param_1 * 0x1b] = 0xffffffff;
  }
  return;
}

