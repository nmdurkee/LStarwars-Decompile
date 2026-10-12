/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0930; label: FUN_004f0930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f0930(int param_1)

{
  if (param_1 != DAT_0091eea8) {
    if (DAT_0091eeac != 0) {
      FUN_004ef280(DAT_0091eeac,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0xa58);
    }
    if (DAT_0091eeb0 != 0) {
      FUN_004ef280(DAT_0091eeb0,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0xa59);
    }
    DAT_0091eea8 = param_1;
    DAT_0091eeac = FUN_004eef40(param_1 << 4,
                                "d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0xa5d);
    DAT_0091eeb0 = FUN_004eef40(DAT_0091eea8 << 4,
                                "d:\\projects\\legosagapc\\nu2api.saga\\nucore\\nufile.c",0xa5e);
  }
  DAT_0091ce64 = 0;
  DAT_0091ee80 = 0;
  return;
}

