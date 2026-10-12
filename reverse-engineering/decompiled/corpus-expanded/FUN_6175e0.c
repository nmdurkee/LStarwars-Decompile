/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x6175e0; label: FUN_006175e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006175e0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 != 0) {
    if (*(uint *)(iVar2 + 0x4b0) < 2) {
      *(undefined4 *)(iVar2 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
    }
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  if (*(int *)(in_ECX + 4) != 0) {
    piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x4b0);
    *piVar1 = *piVar1 + 1;
  }
  return;
}

