/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6144f0; label: FUN_006144f0
 */

/* WARNING: Type propagation algorithm not settling */

void FUN_006144f0(int *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int local_18 [6];
  
  local_18[5] = DAT_00829570 ^ (uint)local_18;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  if (param_1[1] != 0) {
    FUN_004ef660(local_18,param_1[2] + param_1[1],4);
    if (*param_1 != 0) {
      FUN_00621190(local_18);
    }
    param_1[2] = param_1[2] + 4;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_18 + 1,param_1[2] + param_1[1],0x10);
    param_1[2] = param_1[2] + 0x10;
  }
  if (local_18[0] != 0) {
    cVar3 = FUN_00611cc0(in_ECX + 0x10);
    if (cVar3 != '\0') {
      bVar2 = true;
      goto LAB_0061458c;
    }
  }
  bVar2 = false;
LAB_0061458c:
  iVar4 = 0;
  piVar5 = (int *)(in_ECX + 0xd838);
  while ((*piVar5 == 0 || (*piVar5 != param_2))) {
    iVar4 = iVar4 + 1;
    piVar5 = piVar5 + 5;
    if (7 < iVar4) {
      __security_check_cookie(local_18[5] ^ (uint)local_18);
      return;
    }
  }
  if (bVar2) {
    iVar1 = in_ECX + iVar4 * 0x14;
    if ((*(int *)(in_ECX + 0xd844 + iVar4 * 0x14) != 3) &&
       ((*(int *)(iVar1 + 0xd844) < 1 || (2 < *(int *)(iVar1 + 0xd844))))) {
      *(undefined4 *)(iVar1 + 0xd848) = 0;
      *(undefined4 *)(iVar1 + 0xd844) = 1;
      __security_check_cookie(local_18[5] ^ (uint)local_18);
      return;
    }
  }
  else {
    iVar4 = in_ECX + 0xd838 + iVar4 * 0x14;
    *(undefined4 *)(iVar4 + 0x10) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  __security_check_cookie(local_18[5] ^ (uint)local_18);
  return;
}

