/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e320; label: FUN_0056e320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e320(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_008032cc == 0) {
    FUN_0054a910(0x3f333333,0,0,0);
    _DAT_00950d90 = _DAT_008032c8;
  }
  else {
    if (param_2 == 0) {
      return;
    }
    *(undefined4 *)(param_2 + 0xdec) = _DAT_008032c8;
    FUN_0054a850(**(undefined4 **)(param_2 + 0xca4),0x3f333333,0);
    FUN_00549fd0();
  }
  iVar1 = FUN_00560fa0(*(undefined4 *)(DAT_00926c20 + DAT_00950d94 * 4),param_1,0x3f000000,param_1,
                       0x3f400000,0xff,0xff,0xff,0x4023,0x3f800000);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xd4) = 0x3f400000;
  }
  iVar1 = FUN_00560fa0(*(undefined4 *)(DAT_00926c20 + DAT_00950d94 * 4),param_1,0x3f000000,param_1,
                       0x3e800000,0xff,0xff,0xff,0x4023,0x3f800000);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xd4) = 0x3f400000;
  }
  FUN_00547930(0x50,0,0,0);
  return;
}

