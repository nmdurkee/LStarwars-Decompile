/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ccee0; label: FUN_006ccee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ccee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f690;
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

