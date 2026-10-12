/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617750; label: FUN_00617750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617750(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xac) != 0) && (iVar1 = *(int *)(in_ECX + 0xa0), iVar1 != 0)) {
    if (1 < *(uint *)(iVar1 + 0x4b0)) {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
      *(undefined4 *)(in_ECX + 0xac) = 0;
      return;
    }
    *(undefined4 *)(iVar1 + 0x4b0) = 0;
  }
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}

