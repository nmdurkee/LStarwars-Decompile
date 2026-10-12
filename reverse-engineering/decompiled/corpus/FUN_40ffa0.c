/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40ffa0; label: FUN_0040ffa0
 */

void FUN_0040ffa0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int in_EDX;
  
  if (0 < in_EDX) {
    puVar1 = in_ECX + 0xe;
    do {
      *(undefined2 *)((int)puVar1 + 10) = 0;
      *in_ECX = 0x42a00000;
      in_ECX = in_ECX + 0x14;
      in_EDX = in_EDX + -1;
      puVar1[-0xd] = 0x425c0000;
      puVar1[-0xc] = 0x43480000;
      puVar1[-0xb] = 0x3f800000;
      puVar1[1] = 0x3f800000;
      puVar1[-2] = 0;
      puVar1[-1] = 0;
      *puVar1 = 0;
      puVar1[-10] = 0;
      puVar1[-9] = 0;
      puVar1[-8] = 0;
      puVar1[-7] = 0x3f800000;
      puVar1[-3] = 0x3f800000;
      puVar1[-6] = 0;
      puVar1[-5] = 0;
      puVar1[-4] = 0;
      puVar1[4] = 0xffffff;
      *(undefined2 *)(puVar1 + 2) = 0;
      puVar1[-8] = puVar1[-0xc];
      puVar1[5] = 0x40a00000;
      puVar1 = puVar1 + 0x14;
    } while (in_EDX != 0);
  }
  return;
}

