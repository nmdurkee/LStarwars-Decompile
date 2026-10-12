/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4ce450; label: FUN_004ce450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

