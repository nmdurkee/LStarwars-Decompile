/* Ghidra pseudocode, not original source.
 * ev_d64f82d79bd9036ef98f897f1d4209ad19800693bd01752bbb2d417690313147
 * Entry: 0x698100; label: FUN_00698100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00698100(float *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 local_c [12];
  
  if (((DAT_02973954 != 0) && (*(char *)(param_2 * 0x40c + 0x404 + DAT_02973954) != '\0')) &&
     (((param_1 < &DAT_02962b5c ||
       (((&DAT_02962b80 < param_1 || (DAT_02962b50 != *param_1)) || (DAT_02962b54 != param_1[1]))))
      || (DAT_02962b58 != param_1[2])))) {
    if (DAT_00810dd4 != 0x4000) {
      param_3 = DAT_00810dd4 * param_3 >> 0xf;
    }
    iVar1 = FUN_006977b0(param_1,param_3);
    if ((iVar1 != 0) && (iVar2 = FUN_00697470(param_2,0), -1 < iVar2)) {
      FUN_00697880(iVar2,local_c,1);
      if (0x3fff < iVar1) {
        iVar1 = 0;
      }
      FUN_00697580(iVar2,0,(&DAT_02962bb0)[iVar1],param_5);
      _DAT_02972c0c = _DAT_02972c0c + 1;
    }
  }
  return;
}

