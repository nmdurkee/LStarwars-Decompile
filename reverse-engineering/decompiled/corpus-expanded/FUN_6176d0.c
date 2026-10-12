/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x6176d0; label: FUN_006176d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006176d0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xa0);
  if (iVar1 != 0) {
    if (1 < *(uint *)(iVar1 + 0x4b0)) {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
      return;
    }
    *(undefined4 *)(iVar1 + 0x4b0) = 0;
  }
  return;
}

