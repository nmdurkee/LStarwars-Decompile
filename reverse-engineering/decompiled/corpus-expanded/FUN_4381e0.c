/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x4381e0; label: FUN_004381e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

