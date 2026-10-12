/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9760; label: FUN_006c9760
 */

void FUN_006c9760(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_1c [4];
  int local_18;
  undefined1 local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_1c;
  local_18 = param_2;
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = FUN_004f1ff0(param_1);
  cVar1 = *(char *)(param_1 + -1 + iVar2);
  iVar3 = param_1 + -1 + iVar2;
  if ('/' < cVar1) {
    do {
      if ('9' < cVar1) break;
      cVar1 = *(char *)(iVar3 + -1);
      iVar3 = iVar3 + -1;
      iVar5 = iVar5 + 1;
    } while ('/' < cVar1);
    if (0 < iVar5) {
      iVar2 = iVar2 - iVar5;
      iVar4 = FUN_004f29a0(param_1 + iVar2);
      goto LAB_006c97cc;
    }
  }
  iVar5 = 2;
LAB_006c97cc:
  iVar3 = local_18;
  if (param_3 <= iVar2 + iVar5) {
    iVar2 = (param_3 - iVar5) + -1;
  }
  FUN_004f1f40(local_18,param_1,iVar2 + 1);
  FUN_004f2740(local_14,"%%.%dd",iVar5);
  do {
    iVar4 = iVar4 + 1;
    FUN_004f2740(iVar2 + iVar3,local_14,iVar4);
    iVar5 = FUN_006c9640(iVar3);
  } while (iVar5 == 0);
  __security_check_cookie(local_4 ^ (uint)local_1c);
  return;
}

