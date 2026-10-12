/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a31d0; label: FUN_006a31d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006a31e9) */

float10 FUN_006a31d0(void)

{
  uint *in_EAX;
  
  return (float10)((float)(*in_EAX & 0x7fffffff) * 7.1771143e-07 - 764.6162);
}

