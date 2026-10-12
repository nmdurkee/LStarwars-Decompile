/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a7b0; label: FUN_0069a7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069a7b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076efac;
  if ((HANDLE)in_ECX[2] != (HANDLE)0x0) {
    CloseHandle((HANDLE)in_ECX[2]);
    in_ECX[2] = 0;
  }
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

