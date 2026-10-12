/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b41c0; label: FUN_005b41c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005b41c0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 >> 0x17 & 0xff) - 0x70;
  uVar2 = (int)(param_1 & 0x7fffff) >> 0xd;
  if ((int)uVar1 < 0) {
    return (param_1 >> 0x1f) << 0xf | uVar2;
  }
  if (0x1f < (int)uVar1) {
    uVar1 = 0x1f;
  }
  return (uVar1 & 0x1f | (param_1 >> 0x1f) << 5) << 10 | uVar2;
}

