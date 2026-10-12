/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x611120; label: FUN_00611120
 */

void FUN_00611120(byte param_1)

{
  int in_ECX;
  
  FUN_006334d0(*(undefined4 *)(in_ECX + 0xc),3000);
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x24);
  }
  return;
}

