/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53d300; label: FUN_0053d300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d300(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004ef660(param_1,*(int *)(in_ECX + 8) + *(int *)(in_ECX + 4),1);
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  }
  return;
}

