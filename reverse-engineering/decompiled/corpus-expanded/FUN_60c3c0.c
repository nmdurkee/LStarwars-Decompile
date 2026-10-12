/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c3c0; label: FUN_0060c3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060c3c0(byte param_1)

{
  undefined4 *in_ECX;
  
  FUN_005fb810();
  (&DAT_00986a88)[*(short *)(in_ECX + 0x50)] = 0;
  *in_ECX = &PTR_FUN_007642a4;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

