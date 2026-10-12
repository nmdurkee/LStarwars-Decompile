/* Ghidra pseudocode, not original source.
 * ev_b2a783233b211c47b682189f4533ad6a7c38bd84c0deaf183226d349bdd9b928
 * Entry: 0x520600; label: FUN_00520600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00520600(int param_1,undefined4 *param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  if (((param_1 != 0) && (DAT_0292fc68 != 0)) && (param_3 != -1)) {
    iVar2 = FUN_005da840(param_1);
    sVar1 = *(short *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4a + param_3 * 0x6c);
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        FUN_005da860(&local_c,param_1,iVar4);
        iVar3 = FUN_005cffb0(&local_c);
        if (iVar3 == sVar1) {
          *param_2 = local_c;
          param_2[1] = local_8;
          param_2[2] = local_4;
          return 1;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return 0;
}

