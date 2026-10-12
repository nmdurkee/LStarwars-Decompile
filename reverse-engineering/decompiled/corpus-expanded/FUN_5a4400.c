/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a4400; label: FUN_005a4400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a4400(int param_1,float *param_2)

{
  float *pfVar1;
  
  if (param_1 != 0) {
    pfVar1 = (float *)(param_1 + 0x8c);
    *pfVar1 = -*param_2;
    *(float *)(param_1 + 0x90) = -param_2[1];
    *(float *)(param_1 + 0x94) = -param_2[2];
    FUN_005b3830(pfVar1,pfVar1,0x3ba3d70a);
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 0x80;
  }
  return;
}

