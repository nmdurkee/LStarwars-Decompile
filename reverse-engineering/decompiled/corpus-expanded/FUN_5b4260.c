/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b4260; label: FUN_005b4260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4260(uint *param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (uVar1 >> 0x17 & 0xff) - 0x70;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x1f < (int)uVar2) {
    uVar2 = 0x1f;
  }
  *param_2 = (ushort)(((uVar1 >> 0x1f) << 5 | uVar2 & 0x1f) << 10) |
             (ushort)((int)(uVar1 & 0x7fffff) >> 0xd);
  uVar1 = param_1[1];
  uVar2 = (uVar1 >> 0x17 & 0xff) - 0x70;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x1f < (int)uVar2) {
    uVar2 = 0x1f;
  }
  param_2[1] = (ushort)((uVar2 & 0x1f | (uVar1 >> 0x1f) << 5) << 10) |
               (ushort)((int)(uVar1 & 0x7fffff) >> 0xd);
  uVar1 = param_1[2];
  uVar2 = (uVar1 >> 0x17 & 0xff) - 0x70;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x1f < (int)uVar2) {
    uVar2 = 0x1f;
  }
  param_2[2] = (ushort)((uVar2 & 0x1f | (uVar1 >> 0x1f) << 5) << 10) |
               (ushort)((int)(uVar1 & 0x7fffff) >> 0xd);
  uVar1 = param_1[3];
  uVar2 = (uVar1 >> 0x17 & 0xff) - 0x70;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x1f < (int)uVar2) {
    uVar2 = 0x1f;
  }
  param_2[3] = (ushort)((uVar2 & 0x1f | (uVar1 >> 0x1f) << 5) << 10) |
               (ushort)((int)(uVar1 & 0x7fffff) >> 0xd);
  return;
}

