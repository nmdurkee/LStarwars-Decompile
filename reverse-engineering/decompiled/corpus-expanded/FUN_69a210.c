/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a210; label: FUN_0069a210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069a210(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    return (*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c)) * (uint)*(ushort *)(in_ECX + 0x24);
  }
  return 0;
}

