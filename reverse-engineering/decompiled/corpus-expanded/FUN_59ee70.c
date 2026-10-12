/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59ee70; label: FUN_0059ee70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0059ee70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (unaff_EDI != 0) {
    iVar1 = FUN_004f1ff0();
    if (iVar1 != 0) {
      uVar2 = FUN_00559610(param_1,param_2,iVar1 + 1);
      FUN_004f1f10(uVar2);
    }
  }
  return uVar2;
}

