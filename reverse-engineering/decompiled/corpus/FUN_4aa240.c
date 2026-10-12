/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4aa240; label: FUN_004aa240
 */

void FUN_004aa240(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xe39);
  if (cVar1 == '\x03') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x45;
    return;
  }
  if (cVar1 == '\x02') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x46;
    return;
  }
  if (cVar1 == '\x01') {
    *(undefined2 *)(param_1 + 0x7aa) = 0x47;
  }
  return;
}

