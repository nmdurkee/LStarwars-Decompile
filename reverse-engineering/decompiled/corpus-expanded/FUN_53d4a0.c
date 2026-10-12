/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d4a0; label: FUN_0053d4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d4a0(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = FUN_004f1ff0(param_1);
    puVar2 = (undefined1 *)(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 4));
    *puVar2 = (char)iVar1;
    FUN_004ef660(puVar2 + 1,param_1,iVar1);
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + iVar1 + 1;
  }
  return;
}

