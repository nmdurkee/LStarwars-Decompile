/* Ghidra pseudocode, not original source.
 * ev_c83b5e11bc7efa0def1389adc4a2304c53105cec15af0e74717438b1c42d0b82
 * Entry: 0x5b4210; label: FUN_005b4210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b4210(ushort param_1)

{
  if (param_1 == 0) {
    return (float10)0;
  }
  return (float10)(float)(((param_1 & 0xffff8000) * 8 | param_1 & 0x3ff) << 0xd |
                         ((param_1 >> 10 & 0x1f) + 0x70) * 0x800000);
}

