/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53d180; label: FUN_0053d180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0053d180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8);
}

