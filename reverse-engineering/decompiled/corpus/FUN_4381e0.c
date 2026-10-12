/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x4381e0; label: FUN_004381e0
 */

void FUN_004381e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((*(short *)(param_1 + 0x1064) == DAT_007f187c) && (*(char *)(param_1 + 0x107f) < '\x02')) {
    uVar1 = 4;
  }
  else {
    uVar1 = 0xffffffff;
  }
  FUN_00437770(param_1,0xffffffff,uVar1,param_2,param_3,0,0);
  return;
}

