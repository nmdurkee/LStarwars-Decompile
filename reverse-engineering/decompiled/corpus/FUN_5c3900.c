/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c3900; label: FUN_005c3900
 */

void FUN_005c3900(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_00973904;
  uVar1 = DAT_00973900;
  if (DAT_009737e0 != 0) {
    FUN_005fb7e0(DAT_00973900,DAT_00973904);
  }
  if (DAT_009737f0 != 0) {
    FUN_005fbb30(uVar1,uVar2);
  }
  if (DAT_009737e4 != 0) {
    FUN_005fba70(uVar1,uVar2);
  }
  FUN_005fb450(uVar1,uVar2);
  return;
}

