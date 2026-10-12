/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8c20; label: FUN_004f8c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f8c20(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  bVar1 = *param_2;
  if (bVar1 == 0) {
    *param_1 = *param_2;
    return;
  }
  do {
    if (((byte)(bVar1 + 0x9f) < 0x1a) || (0xdf < bVar1)) {
      bVar1 = bVar1 - 0x20;
    }
    param_2 = param_2 + 1;
    *param_1 = bVar1;
    bVar1 = *param_2;
    param_1 = param_1 + 1;
  } while (bVar1 != 0);
  *param_1 = 0;
  return;
}

