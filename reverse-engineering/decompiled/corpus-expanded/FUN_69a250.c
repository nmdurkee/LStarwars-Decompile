/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a250; label: FUN_0069a250
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069a250(void)

{
  int in_ECX;
  
  if (*(HANDLE *)(in_ECX + 8) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
    return 0;
  }
  return 0x80004005;
}

