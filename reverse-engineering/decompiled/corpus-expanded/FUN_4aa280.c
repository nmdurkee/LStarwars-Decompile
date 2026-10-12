/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4aa280; label: FUN_004aa280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

