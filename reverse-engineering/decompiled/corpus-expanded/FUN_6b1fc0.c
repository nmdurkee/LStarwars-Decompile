/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b1fc0; label: FUN_006b1fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006b1fd9) */

float10 FUN_006b1fc0(void)

{
  uint *in_EAX;
  
  return (float10)((float)(*in_EAX & 0x7fffffff) * 7.1771143e-07 - 764.6162);
}

