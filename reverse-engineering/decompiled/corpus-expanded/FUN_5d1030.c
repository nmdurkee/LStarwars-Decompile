/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d1030; label: FUN_005d1030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d1030(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x48) + 0x10);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}

