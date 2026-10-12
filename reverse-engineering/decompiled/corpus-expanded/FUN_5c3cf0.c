/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c3cf0; label: FUN_005c3cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3cf0(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_005f8bf0(param_3);
  FUN_005c2760();
  if (param_1 != 0) {
    piVar1 = (int *)FUN_005f8460(param_1);
    if ((DAT_0097f9b8 != *piVar1) || (DAT_0097f9bc != piVar1[1])) {
      uVar2 = FUN_005f8460(param_1);
      FUN_005fa540(0,uVar2);
    }
  }
  FUN_005f8550(param_1,0);
  if (param_2 != 0) {
    piVar1 = (int *)FUN_005f8460(param_2);
    if ((DAT_0097f9c0 != *piVar1) || (DAT_0097f9c4 != piVar1[1])) {
      uVar2 = FUN_005f8460(param_2);
      FUN_005fa540(1,uVar2);
    }
  }
  FUN_005f8550(param_2,1);
  FUN_005fb550();
  return;
}

