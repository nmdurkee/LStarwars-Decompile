/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a230; label: FUN_0069a230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069a230(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x2c);
    return 0;
  }
  return 0x80004005;
}

