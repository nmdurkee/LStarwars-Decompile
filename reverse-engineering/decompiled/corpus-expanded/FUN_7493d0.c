/* Ghidra pseudocode, not original source.
 * ev_e0447f8e73d2150c5385a8aa294440164da99c01f5f62ba5bd70b4e5b4546b39
 * Entry: 0x7493d0; label: FUN_007493d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007493d0(undefined4 param_1,int *param_2,size_t param_3,undefined4 param_4)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  int iVar3;
  int local_670;
  undefined4 local_66c;
  undefined4 local_668;
  undefined4 local_664;
  char local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_670;
  iVar3 = 0;
  local_664 = param_1;
  local_66c = param_4;
  local_668 = 0;
  local_670 = FUN_004f0d50();
  FUN_004f0d40(0);
  do {
    cVar2 = FUN_00748ee0(in_ECX + 0x104,&local_668,local_104);
    if (cVar2 == '\0') break;
    _sprintf(local_204,"%s\\%s",local_104,local_664);
    iVar3 = FUN_004fa5f0(local_204,0);
  } while (iVar3 == 0);
  FUN_004f0d40(local_670);
  if (iVar3 == 0) {
    FUN_00749330(local_204,in_ECX + 0x104);
  }
  local_670 = FUN_004f6b40(iVar3);
  if (local_670 < 1) {
    FUN_00749330();
  }
  else {
    iVar1 = param_3 + local_670;
    param_2[1] = 0;
    if (param_2[2] < iVar1) {
      FUN_007484e0(iVar1);
    }
    param_2[1] = iVar1;
    FUN_004fb550(iVar3,*param_2 + param_3,local_670);
    FUN_004f99e0(iVar3);
    _memset((void *)*param_2,0x20,param_3);
    iVar3 = 0;
    if (0 < (int)param_3) {
      do {
        *(undefined1 *)(iVar3 + *param_2) = 10;
        iVar3 = iVar3 + 100;
      } while (iVar3 < (int)param_3);
    }
    FUN_0074db90();
    FUN_0074b1c0(local_104);
    FUN_0074bef0(param_2,param_3,1,local_66c);
    FUN_0074d790();
  }
  __security_check_cookie(local_4 ^ (uint)&local_670);
  return;
}

