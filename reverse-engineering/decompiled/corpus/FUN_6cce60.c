/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cce60; label: FUN_006cce60
 */

void FUN_006cce60(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_LAB_0076ff70;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 1;
  in_ECX[7] = 0x80000000;
  in_ECX[8] = 0x80ff0000;
  in_ECX[9] = 0x80804040;
  in_ECX[10] = 0x80404040;
  in_ECX[0xb] = 0x80000000;
  in_ECX[0xc] = 0x80ff0000;
  in_ECX[0xd] = 0x80406080;
  in_ECX[0xe] = 0x80404040;
  in_ECX[0xf] = 0x80000000;
  in_ECX[0x10] = 0x80ff0000;
  in_ECX[0x11] = 0x80707080;
  in_ECX[0x12] = 0x80808080;
  return;
}

