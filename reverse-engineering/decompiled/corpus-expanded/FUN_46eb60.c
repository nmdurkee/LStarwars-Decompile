/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46eb60; label: FUN_0046eb60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_0046eb60(int *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*param_1 + 0x62);
  if (((bVar1 & 8) != 0) && ((bVar1 & 4) != 0)) {
    return bVar1 >> 1 & 1;
  }
  return 0;
}

