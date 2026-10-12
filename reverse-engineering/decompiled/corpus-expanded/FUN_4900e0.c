/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x4900e0; label: FUN_004900e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004900e0(int param_1,float *param_2)

{
  float fVar1;
  float local_c;
  float local_8;
  float local_4;
  
  if ((param_1 != 0) && (param_2 != (float *)0x0)) {
    local_c = *(float *)(param_1 + 0x4c);
    local_8 = *(float *)(param_1 + 0x50);
    local_4 = *(float *)(param_1 + 0x54);
    FUN_005b3620(&local_c,&local_c,*(undefined2 *)(param_1 + 0x88));
    fVar1 = *(float *)(param_1 + 0x70);
    *param_2 = *(float *)(param_1 + 0x68) + local_c;
    param_2[1] = local_8;
    param_2[2] = fVar1 + local_4;
  }
  return;
}

