/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748bf0; label: FUN_00748bf0
 */

void FUN_00748bf0(char *param_1,size_t param_2,int *param_3,size_t param_4,undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int local_46c;
  undefined4 local_468;
  char *local_464;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_46c;
  local_464 = param_1;
  local_468 = param_5;
  if ((int)param_2 < 0) {
    pcVar1 = param_1 + 1;
    do {
      cVar2 = *param_1;
      param_1 = param_1 + 1;
    } while (cVar2 != '\0');
    param_2 = (int)param_1 - (int)pcVar1;
  }
  iVar3 = param_4 + param_2;
  param_3[1] = 0;
  if (param_3[2] < iVar3) {
    FUN_007484e0(iVar3);
  }
  param_3[1] = iVar3;
  _strncpy((char *)(*param_3 + param_4),local_464,param_2);
  _memset((void *)*param_3,0x20,param_4);
  iVar3 = 0;
  if (0 < (int)param_4) {
    do {
      *(undefined1 *)(iVar3 + *param_3) = 10;
      iVar3 = iVar3 + 100;
    } while (iVar3 < (int)param_4);
  }
  FUN_0074db90();
  FUN_0074b1c0(local_46c + 0x104);
  FUN_0074bef0(param_3,param_4,1,local_468);
  FUN_0074d790();
  __security_check_cookie(local_4 ^ (uint)&local_46c);
  return;
}

