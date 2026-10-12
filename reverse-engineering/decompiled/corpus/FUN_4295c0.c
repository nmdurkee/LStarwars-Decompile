/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x4295c0; label: FUN_004295c0
 */

undefined4 FUN_004295c0(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\a') &&
     (iVar1 = FUN_0056e160(0xc), iVar1 != 0)) {
    if (param_2 != 0) {
      param_1 = param_2;
    }
    FUN_00547930(0x4a,param_1 + 0x80,0,0);
    FUN_00549bb0(0,0x3f400000,0x3f400000,0x3f800000);
    return 0xffffffff;
  }
  if (((param_2 != 0) &&
      ((*(short *)(param_2 + 0x1064) == DAT_007f1878 ||
       (*(short *)(param_2 + 0x1064) == DAT_007f1884)))) &&
     ((*(char *)(param_2 + 0x7b5) == '\f' || (*(char *)(param_2 + 0x7b5) == '\x18')))) {
    FUN_00547930(0x4a,param_2 + 0x80,0,0);
  }
  return 1;
}

