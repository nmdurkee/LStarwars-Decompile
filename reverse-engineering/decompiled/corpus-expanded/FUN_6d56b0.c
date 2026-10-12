/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d56b0; label: FUN_006d56b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d56b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 1;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[0xf] = 1;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  DAT_029755a1 = 0;
  _memset(&DAT_029751a0,0,0x100);
  _memset(&DAT_029752a0,0,0x100);
  return;
}

