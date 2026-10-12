/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c0e30; label: FUN_005c0e30
 */

float10 FUN_005c0e30(float param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  if (param_1 < 0.0) {
    if (param_1 <= -1.0) {
      return (float10)-1.5707964;
    }
    fVar1 = (float10)FUN_005c0240(param_1 + 1.0);
    fVar2 = (float10)param_1;
    return (float10)(float)((fVar2 * (float10)0.2121143937110901 + (float10)1.5707287788391113 +
                             (float10)0.07426100224256516 * fVar2 * fVar2 +
                            fVar2 * (float10)0.018729299306869507 * fVar2 * fVar2) * fVar1 -
                           (float10)1.5707963705062866);
  }
  if (!NAN(param_1) && 1.0 < param_1 != (param_1 == 1.0)) {
    return (float10)1.5707964;
  }
  fVar1 = (float10)FUN_005c0240(1.0 - param_1);
  fVar2 = (float10)param_1;
  return (float10)(float)((float10)1.5707963705062866 -
                         ((fVar2 * (float10)0.07426100224256516 * fVar2 +
                          ((float10)1.5707287788391113 - (float10)0.2121143937110901 * fVar2)) -
                         fVar2 * (float10)0.018729299306869507 * fVar2 * fVar2) * fVar1);
}

