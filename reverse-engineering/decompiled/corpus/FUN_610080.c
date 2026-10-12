/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x610080; label: FUN_00610080
 */

uint FUN_00610080(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (0 < param_3) {
    param_2 = param_2 - (int)param_1;
    do {
      uVar1 = FUN_004f3730(*param_1,*(undefined4 *)(param_2 + (int)param_1),param_4);
      uVar2 = uVar2 | uVar1;
      param_1 = param_1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar2;
}

