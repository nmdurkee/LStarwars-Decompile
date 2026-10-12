/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60ec90; label: FUN_0060ec90
 */

void FUN_0060ec90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_LAB_0076a96c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  FUN_00633500();
  *in_ECX = &PTR_FUN_0076a9c0;
  in_ECX[4] = &PTR_LAB_0076a98c;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0x850] = 0;
  in_ECX[0x85b] = 0;
  in_ECX[0x85c] = 0;
  FUN_006178f0();
  FUN_00614820();
  in_ECX[0x855] = 0x3e99999a;
  in_ECX[0x85d] = 0;
  in_ECX[0x856] = 0xbe99999a;
  in_ECX[0x84f] = 0;
  in_ECX[0x854] = 0;
  in_ECX[0x857] = 0x3f000000;
  in_ECX[0x858] = 0x3e99999a;
  return;
}

