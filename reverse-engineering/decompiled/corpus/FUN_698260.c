/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x698260; label: FUN_00698260
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00698260(float *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_10;
  undefined1 local_c [12];
  
  if (((DAT_02973954 != 0) && (*(char *)(param_2 * 0x40c + 0x404 + DAT_02973954) != '\0')) &&
     (((param_1 < &DAT_02962b5c ||
       (((&DAT_02962b80 < param_1 || (DAT_02962b50 != *param_1)) || (DAT_02962b54 != param_1[1]))))
      || (DAT_02962b58 != param_1[2])))) {
    if (DAT_00810dd4 != 0x4000) {
      param_3 = DAT_00810dd4 * param_3 >> 0xf;
    }
    iVar4 = FUN_006977b0(param_1,param_3);
    if ((iVar4 != 0) &&
       (cVar3 = FUN_00697740(param_1,param_2,&local_10), uVar1 = _DAT_00810d9c, -1 < local_10)) {
      iVar5 = local_10 * 0x34;
      *(undefined4 *)(&DAT_02972c7c + iVar5) = DAT_02972c18;
      uVar2 = DAT_00810dc8;
      *(undefined4 *)(&DAT_02972c70 + iVar5) = uVar1;
      uVar1 = _DAT_00810d98;
      *(float **)(&DAT_02972c68 + iVar5) = param_1;
      *(undefined4 *)(&DAT_02972c74 + iVar5) = uVar1;
      (&DAT_02972c6c)[iVar5] = 1;
      *(int *)(&DAT_02972c78 + iVar5) = param_3;
      *(undefined4 *)(&DAT_02972c80 + iVar5) = uVar2;
      if (cVar3 == '\0') {
        FUN_00697880(local_10,local_c,1);
        if (0x3fff < iVar4) {
          iVar4 = 0;
        }
        FUN_00697580(local_10,1,(&DAT_02962bb0)[iVar4],param_5);
        _DAT_02972c10 = _DAT_02972c10 + 1;
        return;
      }
      FUN_00697880(local_10,local_c,0);
      FUN_00697920(local_10,iVar4);
      FUN_00697990(local_10,param_5);
      _DAT_02972c14 = _DAT_02972c14 + 1;
    }
  }
  return;
}

