/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b09b0; label: FUN_006b09b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006b09c9) */

float10 FUN_006b09b0(void)

{
  uint *in_EAX;
  
  return (float10)((float)(*in_EAX & 0x7fffffff) * 7.1771143e-07 - 764.6162);
}

