/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8de0; label: FUN_004f8de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f8de0(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    cVar1 = *param_1;
    if (((byte)(cVar1 + 0xbfU) < 0x1a) || ((byte)(cVar1 + 0x40U) < 0x20)) {
      cVar1 = cVar1 + ' ';
    }
    *param_1 = cVar1;
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  return;
}

