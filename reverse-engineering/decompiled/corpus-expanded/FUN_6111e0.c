/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x6111e0; label: FUN_006111e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006111e0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  FUN_0060df50("EmuRaw");
  FUN_0060df50("EmuPack");
  in_ECX[0x67b] = &PTR_FUN_0076ab00;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0x5ef] = 0;
  in_ECX[0x5ec] = 0;
  in_ECX[0x5ed] = 0;
  in_ECX[0x5ee] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[0xe] = 800;
  in_ECX[0xf] = 0x32;
  in_ECX[0x5f0] = 0x1800;
  in_ECX[0x5f1] = 0x2800;
  in_ECX[0x5f2] = 0x80;
  *in_ECX = 0x200;
  return;
}

