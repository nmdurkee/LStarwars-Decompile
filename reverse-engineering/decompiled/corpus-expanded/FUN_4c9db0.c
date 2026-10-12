/* Ghidra pseudocode, not original source.
 * ev_2c33bc1d2955cf32f461d40ab407fc477c117f7bb728ceb3ddb2ece88215ba87
 * Entry: 0x4c9db0; label: FUN_004c9db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c9db0(void)

{
  if (DAT_00876580 != 0) {
    FUN_0054b600("stuff\\text\\pc_font",&DAT_00924878,&DAT_0092487c);
    return;
  }
  if (DAT_007f39e4 != 0) {
    if (DAT_0080235c == 0) {
      FUN_0054b600("stuff\\text\\starwars_font_j",&DAT_00924878,&DAT_0092487c);
      return;
    }
    FUN_0054b600("stuff\\text\\starwars_font",&DAT_00924878,&DAT_0092487c);
    return;
  }
  FUN_0054b600("stuff\\text\\batman_font",&DAT_00924878,&DAT_0092487c);
  return;
}

