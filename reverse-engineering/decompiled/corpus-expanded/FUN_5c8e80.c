/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8e80; label: FUN_005c8e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c8e80(void)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_007644dc;
  in_ECX[0xb7] = 0;
  in_ECX[0xb8] = 0;
  in_ECX[0xb9] = 0;
  in_ECX[0xba] = 0;
  in_ECX[0xbb] = 0;
  in_ECX[0xbc] = 0;
  in_ECX[0x12] = 0x3f000000;
  in_ECX[0xbd] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[3] = 4;
  in_ECX[0x11] = 0;
  return;
}

