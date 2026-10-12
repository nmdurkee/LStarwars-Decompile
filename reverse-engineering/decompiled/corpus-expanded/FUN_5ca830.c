/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5ca830; label: FUN_005ca830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005ca830(ushort *param_1,undefined4 param_2,int param_3,float param_4,float *param_5)

{
  float fVar1;
  uint uVar2;
  float local_4;
  
  local_4 = 0.0;
  switch(param_2) {
  case 0:
    return (float10)(((((float)(int)((param_1[2] & 0xfff) - (param_1[1] & 0xfff)) * param_4 +
                       (float)(param_1[1] & 0xfff)) / 4095.0) *
                      (float)(int)((uint)*(ushort *)((int)param_1 + param_3) - (uint)*param_1) +
                     (float)*param_1) * *param_5 + param_5[1]);
  case 1:
    return (float10)(((((float)(int)((param_1[3] & 0xfff) - (param_1[2] & 0xfff)) * param_4 +
                       (float)(param_1[2] & 0xfff)) / 4095.0) *
                      (float)(int)((uint)*(ushort *)((int)param_1 + param_3) - (uint)*param_1) +
                     (float)*param_1) * *param_5 + param_5[1]);
  case 2:
    uVar2 = param_1[3] & 0xfff;
    return (float10)(((((float)(int)((*(byte *)((int)param_1 + 5) & 0xf0 | (uint)(param_1[1] >> 0xc)
                                     | param_1[3] >> 4 & 0xf00) - uVar2) * param_4 + (float)uVar2) /
                      4095.0) * (float)(int)((uint)*(ushort *)((int)param_1 + param_3) -
                                            (uint)*param_1) + (float)*param_1) * *param_5 +
                    param_5[1]);
  case 3:
    uVar2 = (uint)*(ushort *)((int)param_1 + param_3);
    fVar1 = (float)*param_1 +
            ((float)(ushort)((ushort)(param_1[3] & 0xf00f | (ushort)*(byte *)((int)param_1 + 3)) >>
                             4 | (ushort)(*(byte *)((int)param_1 + 5) & 0xf0)) *
            (float)(int)(uVar2 - *param_1)) / 4095.0;
    local_4 = (fVar1 + param_4 * ((((float)(*(ushort *)((int)param_1 + param_3 + 2) & 0xfff) *
                                   (float)(int)(param_1[param_3] - uVar2)) / 4095.0 + (float)uVar2)
                                 - fVar1)) * *param_5 + param_5[1];
  }
  return (float10)local_4;
}

