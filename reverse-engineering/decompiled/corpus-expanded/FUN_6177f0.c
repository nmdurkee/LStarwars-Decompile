/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x6177f0; label: FUN_006177f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006177f0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  for (iVar2 = in_ECX + 4; iVar2 != in_ECX + 0x1604; iVar2 = iVar2 + 0xb0) {
    if (*(int *)(iVar2 + 0xac) != 0) {
      FUN_0060e450(iVar2,0xa0200001);
      if ((*(int *)(iVar2 + 0xac) != 0) && (iVar1 = *(int *)(iVar2 + 0xa0), iVar1 != 0)) {
        if (*(uint *)(iVar1 + 0x4b0) < 2) {
          *(undefined4 *)(iVar1 + 0x4b0) = 0;
        }
        else {
          *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
        }
      }
      *(undefined4 *)(iVar2 + 0xac) = 0;
    }
  }
  return;
}

