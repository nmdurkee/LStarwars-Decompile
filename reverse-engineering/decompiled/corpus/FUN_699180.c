/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x699180; label: FUN_00699180
 */

bool FUN_00699180(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int in_ECX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  bVar1 = *(int *)(in_ECX + 0x1b8) < 0x20;
  if (bVar1) {
    *(undefined4 *)(in_ECX + 0xb8 + *(int *)(in_ECX + 0x1c0) * 4) = param_1;
    *(undefined4 *)(in_ECX + 0x138 + *(int *)(in_ECX + 0x1c0) * 4) = param_2;
    *(int *)(in_ECX + 0x1b8) = *(int *)(in_ECX + 0x1b8) + 1;
    *(uint *)(in_ECX + 0x1c0) = *(int *)(in_ECX + 0x1c0) + 1U & 0x1f;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x70));
  if (bVar1) {
    SetEvent(*(HANDLE *)(in_ECX + 0x60));
  }
  return bVar1;
}

