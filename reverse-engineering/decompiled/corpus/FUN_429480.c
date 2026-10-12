/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x429480; label: FUN_00429480
 */

void FUN_00429480(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0062a6a0(*(undefined4 *)(param_1 + 0x50),(int)*(short *)(param_1 + 0x7aa));
  if ((uVar1 & 4) != 0) {
    if (param_2 != 0) {
      FUN_00681f40();
      return;
    }
    FUN_00681f40("WhipNowt",param_1 + 0x80);
  }
  return;
}

