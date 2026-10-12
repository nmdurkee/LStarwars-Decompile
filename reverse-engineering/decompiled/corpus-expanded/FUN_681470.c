/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681470; label: FUN_00681470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00681470(float *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                undefined2 param_6,int *param_7)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = DAT_02947bfc;
  if ((DAT_0292fc68 == (int *)0x0) || (param_7 == (int *)0x0)) {
    return -1;
  }
  if (DAT_0292fc68[0x2922] <= (int)(short)DAT_0292fc68[0x53]) {
    return -3;
  }
  if ((param_1 != (float *)0x0) && (param_2 != 0)) {
    if (DAT_02921870 <= DAT_02947bfc) {
      return -5;
    }
    iVar2 = 0;
    if (0 < param_7[0x2923]) {
      psVar3 = (short *)(param_7[0x1a] + 0x4a);
      while ((*(int *)(psVar3 + -5) == 0 || (*psVar3 != param_5))) {
        iVar2 = iVar2 + 1;
        psVar3 = psVar3 + 0x36;
        if (param_7[0x2923] <= iVar2) {
          return -6;
        }
      }
      if (iVar2 != -1) {
        puVar5 = (undefined4 *)(*param_7 + *(short *)(iVar2 * 0x6c + 0x48 + param_7[0x1a]) * 0x38);
        puVar6 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
        for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(undefined4 *)(*DAT_0292fc68 + 0x2c + (short)DAT_0292fc68[0x53] * 0x38) = 0;
        puVar5 = (undefined4 *)(DAT_02947c64 + iVar1 * 0x1c);
        puVar5[1] = param_2;
        puVar5[2] = param_3;
        *puVar5 = param_1;
        puVar5[3] = param_4;
        *(undefined2 *)(puVar5 + 6) = param_6;
        if (param_1[8] * param_1[2] - param_1[10] * *param_1 <= 0.0) {
          *(undefined2 *)((int)puVar5 + 0x1a) = 0;
        }
        else {
          *(undefined2 *)((int)puVar5 + 0x1a) = 1;
        }
        FUN_00680e90((int)(short)DAT_0292fc68[0x53],DAT_02924b4c,puVar5);
        iVar1 = DAT_02947c64 + DAT_02947bfc * 0x1c;
        *(short *)(iVar1 + 0x14) = (short)DAT_0292fc68[0x53];
        *(undefined4 *)(iVar1 + 0x10) =
             *(undefined4 *)(*DAT_0292fc68 + 0xc + (short)DAT_0292fc68[0x53] * 0x38);
        *(short *)(*DAT_0292fc68 + 0x30 + (short)DAT_0292fc68[0x53] * 0x38) =
             -1 - (short)DAT_02947bfc;
        *(undefined4 *)(*DAT_0292fc68 + 0xc + (short)DAT_0292fc68[0x53] * 0x38) = 0;
        *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + 1;
        DAT_02947bfc = DAT_02947bfc + 1;
        return (short)DAT_0292fc68[0x53] + -1;
      }
    }
    return -6;
  }
  return -4;
}

