/* Ghidra analysis pseudocode, not original source.
 * ev_7393eb289fae971e4c9d676939847dbe45fbc997f5b4ac5470a7ef95c2a601ec
 * Entry: 0x6db0c0; label: FUN_006db0c0
 */

void FUN_006db0c0(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = 0xffffffff;
  uVar1 = DAT_02976bd0;
  if (0x400 < DAT_02976bd0) {
    uVar1 = 0x400;
  }
  in_ECX[0x101] = uVar1;
  uVar2 = 0x300;
  if (DAT_02976bd0 < 0x401) {
    uVar2 = DAT_02976bd4;
  }
  in_ECX[0x103] = 0x400;
  in_ECX[0x102] = uVar2;
  in_ECX[0x104] = 0x300;
  in_ECX[0x105] = 0;
  in_ECX[0x106] = 0;
  in_ECX[0x107] = DAT_02976bd8;
  in_ECX[0x10a] = 10;
  in_ECX[0x10e] = 10;
  in_ECX[0x10b] = 8;
  in_ECX[0x10c] = 8;
  in_ECX[0x110] = 2;
  in_ECX[0x111] = 2;
  in_ECX[0x113] = 2;
  in_ECX[0x114] = 2;
  in_ECX[0x108] = 0;
  in_ECX[0x109] = 3;
  *(undefined1 *)(in_ECX + 0x10d) = 1;
  *(undefined1 *)(in_ECX + 0x10f) = 0;
  *(undefined1 *)((int)in_ECX + 0x43d) = 0;
  *(undefined1 *)(in_ECX + 0x112) = 1;
  *(undefined1 *)(in_ECX + 0x115) = 1;
  *(undefined1 *)((int)in_ECX + 0x455) = 1;
  *(undefined1 *)((int)in_ECX + 0x456) = 1;
  *(undefined1 *)((int)in_ECX + 0x457) = 1;
  *(undefined1 *)(in_ECX + 0x116) = 1;
  *(undefined1 *)((int)in_ECX + 0x459) = 1;
  in_ECX[0x117] = 0;
  return;
}

