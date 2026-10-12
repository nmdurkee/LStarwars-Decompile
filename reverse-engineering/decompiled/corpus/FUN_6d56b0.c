/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d56b0; label: FUN_006d56b0
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

