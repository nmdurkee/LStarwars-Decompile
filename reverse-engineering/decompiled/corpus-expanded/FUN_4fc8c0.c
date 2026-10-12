/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fc8c0; label: FUN_004fc8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004fc8c0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = FUN_004fc750(param_2);
    if (iVar1 != 0) {
      FUN_004f1f10(iVar1 + 8,param_1);
      return iVar1;
    }
    FUN_004f99e0(param_2);
  }
  return 0;
}

