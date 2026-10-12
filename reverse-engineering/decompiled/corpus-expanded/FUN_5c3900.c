/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c3900; label: FUN_005c3900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

