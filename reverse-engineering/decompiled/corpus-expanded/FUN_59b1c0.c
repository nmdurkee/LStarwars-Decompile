/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59b1c0; label: FUN_0059b1c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 *
FUN_0059b1c0(int param_1,undefined4 *param_2,int param_3,uint param_4,undefined4 *param_5,
            undefined4 param_6,int param_7)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  
  if ((param_3 != 0) && (param_5 != (undefined4 *)0x0)) {
    iVar2 = 1;
    if ((*(byte *)((int)param_5 + 0x23) & 1) == 0) {
      iVar2 = param_7;
    }
    if (param_2 != (undefined4 *)0x0) {
      if (iVar2 == 0) {
        *param_2 = *param_5;
        param_2[1] = param_5[1];
        param_2[2] = param_5[2];
        FUN_005b3620(param_2,param_2,param_4 & 0xffff);
        FUN_005b37d0(param_2,param_2,param_3);
        param_2[3] = param_5[3];
        param_2[6] = param_5[6];
        param_2[7] = param_5[7];
        param_2[4] = (float)param_5[4] + *(float *)(param_3 + 4);
        param_2[5] = (float)param_5[5] + *(float *)(param_3 + 4);
        *(short *)(param_2 + 0xc) = *(short *)(param_5 + 8) + (short)param_4;
        cVar1 = *(char *)((int)param_5 + 0x22);
        param_2[8] = param_6;
        *(char *)((int)param_2 + 0x32) = cVar1;
        if (cVar1 == '\x01') {
          if ((float)param_2[6] <= (float)param_2[7]) {
            fVar4 = (float10)(float)param_2[7];
          }
          else {
            fVar4 = (float10)(float)param_2[6];
          }
        }
        else if (cVar1 == '\x02') {
          fVar4 = (float10)FUN_005c0240((float)param_2[6] * (float)param_2[6] +
                                        (float)param_2[7] * (float)param_2[7]);
        }
        else {
          fVar4 = (float10)(float)param_2[3];
        }
        FUN_0059a720(*(undefined4 *)(param_1 + 0xc),param_2,(float)fVar4,(float)fVar4,
                     (int)param_2 + 0x33,param_2 + 0xd,(int)param_2 + 0x35,(int)param_2 + 0x36);
        return param_2;
      }
      FUN_0059a6b0(param_1,param_2);
      return (undefined4 *)0x0;
    }
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)FUN_0059b0e0(param_1,param_3,param_4,param_5,param_6,0);
      return puVar3;
    }
  }
  return param_2;
}

