/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617660; label: FUN_00617660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617660(void)

{
  undefined4 uVar1;
  int in_ECX;
  int local_c;
  
  if ((((*(int *)(in_ECX + 4) == 1) && (*(int *)(in_ECX + 0xa0) != 0)) &&
      (*(int *)(*(int *)(in_ECX + 0xa0) + 0x4b0) == 1)) && (*(int *)(in_ECX + 8) == 1)) {
    uVar1 = FUN_0053d5d0(0xc);
    FUN_006175e0(uVar1);
    if (local_c != 0) {
      if (1 < *(uint *)(local_c + 0x4b0)) {
        *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(local_c + 0x4b0) = 0;
    }
  }
  return;
}

