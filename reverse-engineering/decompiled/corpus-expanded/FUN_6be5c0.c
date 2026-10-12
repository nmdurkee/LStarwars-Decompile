/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be5c0; label: FUN_006be5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006be5c0(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x24);
  *(int *)(in_ECX + 0x24) = iVar2 + 1;
  puVar1 = (undefined4 *)(*(int *)(in_ECX + 8) + iVar2 * 0x18);
  *puVar1 = param_1;
  puVar1[5] = param_2;
  puVar1[1] = param_3;
  if (param_2 != 0) {
    *(undefined4 **)(param_2 + 4) = puVar1;
  }
  return;
}

