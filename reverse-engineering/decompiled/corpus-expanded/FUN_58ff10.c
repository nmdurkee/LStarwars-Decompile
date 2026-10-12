/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ff10; label: FUN_0058ff10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058ff10(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((_DAT_00802860 != -1) && (*(char *)(param_1 + 0x7b5) == _DAT_00802860)) {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x3f19999a;
    }
    FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,uVar1,1);
  }
  return;
}

