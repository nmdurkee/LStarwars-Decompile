/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fc860; label: FUN_004fc860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004fc860(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = thunk_FUN_004fa610(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004fa3f0(param_1,0,DAT_0091ee88,0);
    if (iVar1 != 0) {
      iVar2 = FUN_004fc750(iVar1);
      if (iVar2 != 0) {
        FUN_004f1f10(iVar2 + 8,param_1);
        return iVar2;
      }
      FUN_004f99e0(iVar1);
    }
  }
  return 0;
}

