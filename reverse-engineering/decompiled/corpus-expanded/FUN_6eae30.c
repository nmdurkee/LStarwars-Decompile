/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eae30; label: __alloca_probe_16
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2005 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}

