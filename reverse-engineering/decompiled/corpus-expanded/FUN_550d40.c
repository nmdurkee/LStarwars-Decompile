/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550d40; label: FUN_00550d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00550d40(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
            float param_7,float param_8)

{
  float fVar1;
  
  fVar1 = (param_3 - param_5) * (param_8 - param_6) + (param_4 - param_6) * (param_5 - param_7);
  if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
    return 0;
  }
  fVar1 = (param_2 - param_6) * (param_5 - param_7) + (param_1 - param_5) * (param_8 - param_6);
  if (NAN(fVar1) || 0.0 < fVar1 == (fVar1 == 0.0)) {
    return 0;
  }
  if ((0.0 <= (param_3 - param_1) * (param_6 - param_2) + (param_4 - param_2) * (param_1 - param_5))
     && (0.0 <= (param_3 - param_7) * (param_2 - param_8) +
                (param_7 - param_1) * (param_4 - param_8))) {
    return 2;
  }
  return 1;
}

