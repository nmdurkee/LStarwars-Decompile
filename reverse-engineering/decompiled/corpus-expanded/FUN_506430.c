/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x506430; label: FUN_00506430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00506430(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) | 0x80;
  puVar2 = (undefined4 *)(param_1 + 0x18);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_00500b90();
  return;
}

