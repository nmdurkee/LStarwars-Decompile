/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cce60; label: FUN_006cce60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cce60(void)

{
  undefined4 *in_ECX;
  
  if (in_ECX + 1 != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    in_ECX[2] = 0;
  }
  *in_ECX = &PTR_FUN_0076ff70;
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

