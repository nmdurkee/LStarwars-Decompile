/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x699770; label: FUN_00699770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00699770(void)

{
  int in_ECX;
  
  if ((in_ECX != 0) &&
     ((*(int *)(in_ECX + 0x1b8) != 0 || ((*(int *)(in_ECX + 8) != 0 && (*(int *)(in_ECX + 8) != 3)))
      ))) {
    return 0;
  }
  return 1;
}

