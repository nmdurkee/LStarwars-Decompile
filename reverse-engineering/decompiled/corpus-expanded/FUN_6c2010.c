/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c2010; label: FUN_006c2010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c2010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076f800;
  if (in_ECX[4] != 0) {
    *(undefined4 *)(in_ECX[4] + 0xc) = 0;
  }
  if (in_ECX[5] != 0) {
    *(undefined4 *)(in_ECX[5] + 0xc) = 0;
  }
  if (in_ECX[6] != 0) {
    *(undefined4 *)(in_ECX[6] + 0xc) = 0;
  }
  *in_ECX = &PTR_FUN_0076b630;
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x1c);
  }
  return;
}

