/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56d760; label: FUN_0056d760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056d760(int param_1,int param_2,float *param_3,int param_4)

{
  float fVar1;
  float fVar2;
  
  if ((((param_2 != 0) && (param_1 != 0)) &&
      ((param_4 != 0 ||
       ((*(float *)(param_2 + 0x14) <= *(float *)(param_1 + 0x188) &&
        (*(float *)(param_1 + 0x17c) <= *(float *)(param_2 + 0x28))))))) &&
     (fVar1 = *(float *)(param_1 + 0x80) - *(float *)(param_2 + 0x10),
     fVar2 = *(float *)(param_1 + 0x88) - *(float *)(param_2 + 0x18),
     fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 <= *(float *)(param_2 + 0x2c))) {
    if (param_3 == (float *)0x0) {
      return 1;
    }
    *param_3 = fVar1;
    return 1;
  }
  return 0;
}

