/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa240; label: FUN_004aa240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

