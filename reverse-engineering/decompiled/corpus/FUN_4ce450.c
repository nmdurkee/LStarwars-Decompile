/* Ghidra analysis pseudocode, not original source.
 * ev_074dd20869da91b1b05b19bd1efa0509a9d09e9660d7c7c0c7ca47d053bd121c
 * Entry: 0x4ce450; label: FUN_004ce450
 */

void FUN_004ce450(int param_1)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  if ((*(byte *)(*(int *)(param_1 + 0x798) + 0x4c) & 4) != 0) {
    if ((*(uint *)(param_1 + 0x7bc) & 0x400) != 0) {
      *in_ECX = 0;
      *in_EAX = 3;
      return;
    }
    *in_ECX = 3;
    *in_EAX = 0;
    return;
  }
  if ((*(uint *)(param_1 + 0x7bc) & 0x400) == 0) {
    if (*(char *)(param_1 + 0x7b4) != '\0') {
      *in_ECX = 1;
      *in_EAX = 0;
      return;
    }
    *in_ECX = 3;
    *in_EAX = 2;
    return;
  }
  if (*(char *)(param_1 + 0x7b4) != '\0') {
    *in_ECX = 2;
    *in_EAX = 3;
    return;
  }
  *in_ECX = 0;
  *in_EAX = 1;
  return;
}

