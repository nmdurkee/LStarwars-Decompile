/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4aa200; label: FUN_004aa200
 */

void FUN_004aa200(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xe39);
  if (cVar1 == '\x03') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x42;
    return;
  }
  if (cVar1 == '\x02') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x43;
    return;
  }
  if (cVar1 == '\x01') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x44;
  }
  return;
}

