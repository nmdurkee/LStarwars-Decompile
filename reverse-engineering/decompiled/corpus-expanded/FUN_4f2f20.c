/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f2f20; label: FUN_004f2f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f2f20(ushort *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  if ((param_2 != (byte *)0x0) && (param_1 != (ushort *)0x0)) {
    *param_1 = 0;
    bVar2 = *param_2;
    while (bVar2 != 0) {
      if (bVar2 < 0x80) {
        *param_1 = (ushort)bVar2;
      }
      else if (bVar2 < 0xe0) {
        *param_1 = (ushort)(bVar2 & 0x1f) << 6;
        pbVar1 = param_2 + 1;
        param_2 = param_2 + 1;
        *param_1 = *param_1 | (ushort)(*pbVar1 & 0x3f);
      }
      else if (bVar2 < 0xf0) {
        *param_1 = (ushort)bVar2 << 0xc;
        *param_1 = *param_1 | (ushort)(param_2[1] & 0x3f) << 6;
        pbVar1 = param_2 + 2;
        param_2 = param_2 + 2;
        *param_1 = *param_1 | (ushort)(*pbVar1 & 0x3f);
      }
      else {
        *param_1 = 0x3f;
      }
      pbVar1 = param_2 + 1;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      bVar2 = *pbVar1;
    }
    *param_1 = 0;
  }
  return;
}

