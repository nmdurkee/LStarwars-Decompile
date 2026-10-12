/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ebbe0; label: FUN_004ebbe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ebbe0(void)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0xbc764064;
  local_8 = 0x3f3dcc64;
  local_4 = 0x41395183;
  iVar1 = FUN_005cfac0(&DAT_0087aad8);
  if (iVar1 != 0) {
    iVar1 = FUN_005cfd60(&DAT_0087aad8);
    if (iVar1 == 0) {
      iVar1 = FUN_005185e0(&local_c,0x3f800000);
      if (iVar1 != 0) {
        *(undefined1 *)(iVar1 + 0x4a) = 2;
        *(undefined4 *)(iVar1 + 0x40) = 0x3f530dd8;
        *(undefined4 *)(iVar1 + 0x44) = 0x3f800000;
      }
    }
  }
  return;
}

