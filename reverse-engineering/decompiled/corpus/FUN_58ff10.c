/* Ghidra analysis pseudocode, not original source.
 * ev_68255797e05c391b0c48c6127d78744e61aebbc693d80e8fac47ab97a0430b58
 * Entry: 0x58ff10; label: FUN_0058ff10
 */

void FUN_0058ff10(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((DAT_00802860 != -1) && (*(char *)(param_1 + 0x7b5) == DAT_00802860)) {
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

