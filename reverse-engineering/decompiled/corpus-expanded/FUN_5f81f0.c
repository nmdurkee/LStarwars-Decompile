/* Ghidra pseudocode, not original source.
 * ev_cf2ac3d06457ecccb228c84c214202b97dbe51dc177c28ee443aaf4c995f45e9
 * Entry: 0x5f81f0; label: FUN_005f81f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f81f0(int *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  float fVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  
  *(undefined2 *)(param_1 + 1) = param_2;
  *(undefined2 *)((int)param_1 + 6) = param_3;
  *(undefined2 *)((int)param_1 + 10) = param_4;
  *(undefined2 *)(param_1 + 3) = param_4;
  param_1[7] = param_6;
  *(undefined2 *)(param_1 + 2) = 0;
  param_1[4] = 1;
  param_1[5] = param_7;
  param_1[6] = param_5;
  param_1[0xb] = -1;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = (int)&DAT_012449d0;
  if (param_7 != 4) {
    uVar4 = FUN_005f7980(param_1[7],param_1);
    FUN_006e47d0((short)param_1[1],*(undefined2 *)((int)param_1 + 6),
                 *(undefined2 *)((int)param_1 + 10),extraout_ECX,uVar4);
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      sVar3 = (**(code **)(*piVar1 + 0x34))(piVar1);
      *(short *)((int)param_1 + 10) = sVar3;
      if (sVar3 == 1) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = 1.5;
      }
      DAT_02854bc0 = DAT_02854bc0 +
                     (int)(longlong)
                          ROUND((float)(int)((uint)*(ushort *)((int)param_1 + 6) *
                                             (uint)*(ushort *)(param_1 + 1) * 4) * fVar2);
    }
    return;
  }
  param_1[7] = 0;
  *(undefined2 *)((int)param_1 + 10) = 1;
  uVar4 = FUN_006e2130((&DAT_02976c08)[DAT_02976c00],0,param_1 + 10,0);
  uVar4 = FUN_005f7980(uVar4);
  FUN_006e46b0((short)param_1[1],*(undefined2 *)((int)param_1 + 6),uVar4);
  DAT_02854bc0 = DAT_02854bc0 +
                 (uint)*(ushort *)((int)param_1 + 6) * (uint)*(ushort *)(param_1 + 1) * 4;
  return;
}

