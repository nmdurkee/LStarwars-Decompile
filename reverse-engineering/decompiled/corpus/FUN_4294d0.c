/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x4294d0; label: FUN_004294d0
 */

void FUN_004294d0(int param_1,int param_2)

{
  uint uVar1;
  
  if ((*(short *)(param_1 + 0x1064) == DAT_007f1884) &&
     (((*(char *)(param_1 + 0x7b5) == '&' && (*(short *)(param_1 + 0x7aa) == 0x56)) ||
      (*(char *)(param_1 + 0x7b5) == '\r')))) {
    FUN_0054a910(0x3ecccccd,0,1,0);
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f333333,0);
    FUN_00549de0(PTR_DAT_008021b4,0x3e800000,0,param_1 + 0x80);
    FUN_00681f40("fs_gamorr_land",param_1 + 0x19c);
    return;
  }
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

