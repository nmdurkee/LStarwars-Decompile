/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b4390; label: FUN_005b4390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4390(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = param_1;
  uVar1 = *param_1;
  if (uVar1 == 0) {
    param_1 = (ushort *)0x0;
  }
  else {
    param_1 = (ushort *)
              (((uVar1 & 0xffff8000) * 8 | uVar1 & 0x3ff) << 0xd |
              ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000);
  }
  *param_2 = (uint)param_1;
  uVar1 = puVar2[1];
  if (uVar1 == 0) {
    param_1 = (ushort *)0x0;
  }
  else {
    param_1 = (ushort *)
              (((uVar1 & 0xffff8000) * 8 | uVar1 & 0x3ff) << 0xd |
              ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000);
  }
  param_2[1] = (uint)param_1;
  uVar1 = puVar2[2];
  if (uVar1 == 0) {
    param_1 = (ushort *)0x0;
  }
  else {
    param_1 = (ushort *)
              (((uVar1 & 0xffff8000) * 8 | uVar1 & 0x3ff) << 0xd |
              ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000);
  }
  param_2[2] = (uint)param_1;
  uVar1 = puVar2[3];
  if (uVar1 == 0) {
    param_2[3] = 0;
    return;
  }
  param_2[3] = ((uVar1 & 0xffff8000) * 8 | uVar1 & 0x3ff) << 0xd |
               ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000;
  return;
}

