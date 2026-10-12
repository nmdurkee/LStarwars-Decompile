/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642ab0; label: FUN_00642ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00642ab0(int param_1)

{
  if (((&DAT_0291f7f0)[param_1 * 0x1b] != -1) && ((&DAT_0291f7f0)[param_1 * 0x1b] != 99999)) {
    FUN_00684400(&DAT_0291f7f0 + param_1 * 0x1b);
    (&DAT_0291f7f0)[param_1 * 0x1b] = 99999;
  }
  return;
}

