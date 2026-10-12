/* Ghidra pseudocode, not original source.
 * ev_73619ddf1363e83d16290e31c370c9dcae9e0ef7a000d1118e2b2a74fc34e424
 * Entry: 0x6eba38; label: FUN_006eba38
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006eba38(int param_1)

{
  uint in_EAX;
  bool in_ZF;
  unkbyte10 in_ST0;
  float10 fVar1;
  
  if (in_ZF) {
    if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
      fVar1 = (float10)FUN_006f690c();
      if (DAT_0297c180 != 0) {
        return fVar1;
      }
      fVar1 = (float10)__startOneArgErrorHandling();
      return fVar1;
    }
    fVar1 = _DAT_00829e8a;
    if ((in_EAX & 0x80000000) != 0) {
      fVar1 = -_DAT_00829e8a;
    }
  }
  else {
    fVar1 = (float10)fpatan(in_ST0,(float10)1);
  }
  if (DAT_0297c180 != 0) {
    return fVar1;
  }
  fVar1 = (float10)__math_exit();
  return fVar1;
}

