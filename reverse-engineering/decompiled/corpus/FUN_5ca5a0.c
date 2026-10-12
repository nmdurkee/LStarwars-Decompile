/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5ca5a0; label: FUN_005ca5a0
 */

void FUN_005ca5a0(ushort *param_1,undefined4 param_2,uint param_3,float *param_4,float *param_5,
                 float *param_6)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)((int)param_1 + param_3);
  switch(param_2) {
  case 0:
    *param_5 = param_4[1] +
               *param_4 *
               ((float)*param_1 +
               ((float)(int)((uint)*puVar1 - (uint)*param_1) * (float)(param_1[1] & 0xfff)) / 4095.0
               );
    *param_6 = (((float)(int)((uint)*puVar1 - (uint)*param_1) * (float)(param_1[2] & 0xfff)) /
                4095.0 + (float)*param_1) * *param_4 + param_4[1];
    return;
  case 1:
    *param_5 = param_4[1] +
               *param_4 *
               ((float)*param_1 +
               ((float)(int)((uint)*puVar1 - (uint)*param_1) * (float)(param_1[2] & 0xfff)) / 4095.0
               );
    *param_6 = (((float)(int)((uint)*puVar1 - (uint)*param_1) * (float)(param_1[3] & 0xfff)) /
                4095.0 + (float)*param_1) * *param_4 + param_4[1];
    return;
  case 2:
    *param_5 = param_4[1] +
               *param_4 *
               ((float)*param_1 +
               ((float)(int)((uint)*puVar1 - (uint)*param_1) * (float)(param_1[3] & 0xfff)) / 4095.0
               );
    *param_6 = (((float)(ushort)((ushort)((ushort)*(byte *)((int)param_1 + 3) | param_1[3] & 0xf00f)
                                 >> 4 | (ushort)(*(byte *)((int)param_1 + 5) & 0xf0)) *
                (float)(int)((uint)*puVar1 - (uint)*param_1)) / 4095.0 + (float)*param_1) * *param_4
               + param_4[1];
    return;
  case 3:
    *param_5 = param_4[1] +
               *param_4 *
               ((float)*param_1 +
               ((float)(ushort)((ushort)(param_1[3] & 0xf00f | (ushort)*(byte *)((int)param_1 + 3))
                                >> 4 | (ushort)(*(byte *)((int)param_1 + 5) & 0xf0)) *
               (float)(int)((uint)*puVar1 - (uint)*param_1)) / 4095.0);
    *param_6 = (((float)(int)((uint)*(ushort *)((int)puVar1 + (param_3 & 0xfffffffe)) -
                             (uint)*puVar1) * (float)(puVar1[1] & 0xfff)) / 4095.0 + (float)*puVar1)
               * *param_4 + param_4[1];
  }
  return;
}

