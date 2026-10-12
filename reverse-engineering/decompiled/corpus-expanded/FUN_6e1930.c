/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1930; label: FUN_006e1930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e1930(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  in_ECX[0x18a] = 0x3faaaaab;
  in_ECX[0x18c] = 0x3faaaaab;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x17c] = 1;
  in_ECX[0x17d] = 0;
  *(undefined1 *)(in_ECX + 0x17e) = 0;
  *(undefined1 *)((int)in_ECX + 0x5f9) = 0;
  *(undefined1 *)((int)in_ECX + 0x5fa) = 1;
  in_ECX[0x17f] = 0;
  in_ECX[0x180] = 1;
  in_ECX[0x181] = 1;
  in_ECX[0x186] = 0;
  in_ECX[0x187] = 0;
  in_ECX[0x188] = 0;
  in_ECX[0x189] = 0;
  in_ECX[0x18b] = 0;
  *(undefined1 *)(in_ECX + 0x18d) = 0;
  in_ECX[0x18e] = 0;
  *(undefined1 *)(in_ECX + 399) = 0;
  in_ECX[0x195] = 0;
  *(undefined1 *)(in_ECX + 0x197) = 1;
  in_ECX[0x198] = 0;
  *(undefined1 *)(in_ECX + 0x199) = 0;
  in_ECX[0x19a] = 0;
  *(undefined2 *)(in_ECX + 0x19b) = 1;
  in_ECX[0x1a1] = 0;
  in_ECX[0x1a2] = 0;
  in_ECX[0x1a3] = 0;
  in_ECX[0x1a4] = 0;
  in_ECX[0x1a5] = 0;
  in_ECX[0x1a6] = 0;
  in_ECX[0x1a7] = 1;
  in_ECX[0x1a8] = 1;
  in_ECX[0x1a9] = 0;
  in_ECX[0x1aa] = 0;
  in_ECX[0x1ab] = 0;
  in_ECX[0x1ac] = 0;
  *(undefined2 *)(in_ECX + 0x1b9) = 1;
  in_ECX[0x1ba] = 0;
  in_ECX[0x1bb] = 0;
  _memset(in_ECX + 0x69,0,0x44c);
  _memset(in_ECX + 2,0,0x130);
  _memset(in_ECX + 0x4e,0,0x38);
  in_ECX[0x5c] = 0;
  in_ECX[0x5d] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x60] = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x182] = 0;
  in_ECX[0x183] = 0;
  in_ECX[0x184] = 0;
  in_ECX[0x185] = 0;
  in_ECX[0x56] = (uint)*(byte *)(in_ECX + 0x197);
  in_ECX[0x191] = 0xffffffff;
  in_ECX[0x192] = 0xffffffff;
  in_ECX[0x193] = 0xffffffff;
  in_ECX[0x194] = 0xffffffff;
  in_ECX[400] = 0;
  in_ECX[0x196] = 0;
  puVar1 = in_ECX + 0x1b1;
  iVar2 = 4;
  do {
    puVar1[-4] = 0;
    *puVar1 = 0;
    puVar1[4] = 0xffffffff;
    puVar1[0xb] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

