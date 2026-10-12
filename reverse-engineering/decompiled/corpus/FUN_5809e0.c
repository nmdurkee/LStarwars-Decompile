/* Ghidra analysis pseudocode, not original source.
 * ev_3e16aee96b5c171402e12d8d72b6e11f18095176631c571f841ebea9bce6f324
 * Entry: 0x5809e0; label: FUN_005809e0
 */

undefined4 FUN_005809e0(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    cVar1 = *(char *)(*(int *)(param_1 + 4) + 0x280);
    if (cVar1 == '\0') {
      return 4;
    }
    if (cVar1 == '\x01') {
      return 5;
    }
  }
  return 3;
}

