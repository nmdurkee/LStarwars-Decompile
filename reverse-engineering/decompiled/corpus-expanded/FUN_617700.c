/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617700; label: FUN_00617700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617700(byte param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xa0);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x4b0) < 2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
    }
  }
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

