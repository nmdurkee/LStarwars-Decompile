/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f2e60; label: FUN_004f2e60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2e60(byte *param_1,ushort *param_2)

{
  ushort uVar1;
  byte bVar2;
  
  if ((param_2 != (ushort *)0x0) && (param_1 != (byte *)0x0)) {
    *param_1 = 0;
    uVar1 = *param_2;
    while (uVar1 != 0) {
      if (uVar1 < 0x80) {
        bVar2 = (byte)*param_2;
      }
      else {
        if (uVar1 < 0x800) {
          bVar2 = (byte)(uVar1 >> 6) & 0x1f | 0xc0;
        }
        else {
          *param_1 = (byte)(uVar1 >> 0xc) | 0xe0;
          param_1 = param_1 + 1;
          bVar2 = (byte)(*param_2 >> 6) & 0x3f | 0x80;
        }
        *param_1 = bVar2;
        param_1 = param_1 + 1;
        bVar2 = (byte)*param_2 & 0x3f | 0x80;
      }
      param_2 = param_2 + 1;
      *param_1 = bVar2;
      param_1 = param_1 + 1;
      uVar1 = *param_2;
    }
    *param_1 = 0;
  }
  return;
}

