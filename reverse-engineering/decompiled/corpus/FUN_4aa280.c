/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4aa280; label: FUN_004aa280
 */

undefined4 FUN_004aa280(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0xe39);
  if (cVar1 == '\x01') {
    return 0x4c;
  }
  if (cVar1 != '\x02') {
    if (cVar1 != '\x03') {
      return 5;
    }
    return 0x28;
  }
  return 0x4b;
}

