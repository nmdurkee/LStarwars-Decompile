/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642af0; label: FUN_00642af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00642af0(int param_1,undefined4 *param_2)

{
  (&DAT_0291f7a8)[param_1 * 0x1b] = *param_2;
  (&DAT_0291f7ac)[param_1 * 0x1b] = param_2[1];
  (&DAT_0291f7b0)[param_1 * 0x1b] = param_2[2];
  (&DAT_0291f7d4)[param_1 * 0x36] = (undefined2)DAT_02920a40;
  (&DAT_0291f7d6)[param_1 * 0x36] = (undefined2)DAT_02920a44;
  (&DAT_0291f7d8)[param_1 * 0x36] = (undefined2)DAT_02920a48;
  return;
}

