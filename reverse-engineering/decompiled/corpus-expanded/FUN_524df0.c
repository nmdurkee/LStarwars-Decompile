/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524df0; label: FUN_00524df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00524df0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *_Dst;
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  local_28 = param_3;
  if (((DAT_009242a4 != 0) && (unaff_ESI != 0)) && (*(int *)(unaff_ESI + 0x7c) != 0)) {
    _Dst = (void *)FUN_00517160(param_2,param_3,(uint)*(byte *)(unaff_ESI + 0x10) * 4);
    if (_Dst != (void *)0x0) {
      _memset(_Dst,0,(uint)*(byte *)(unaff_ESI + 0x10) * 4);
      uVar1 = (uint)*(byte *)(unaff_ESI + 0x10);
      iVar4 = 0;
      if (uVar1 != 0) {
        do {
          puVar2 = (undefined4 *)FUN_00517160(param_2,local_28,uVar1 * 4);
          iVar3 = 0;
          *(undefined4 **)((int)_Dst + iVar4 * 4) = puVar2;
          if (*(char *)(unaff_ESI + 0x10) != '\0') {
            do {
              *puVar2 = 0x7f7fffff;
              iVar3 = iVar3 + 1;
              puVar2 = puVar2 + 1;
            } while (iVar3 < (int)(uint)*(byte *)(unaff_ESI + 0x10));
          }
          uVar1 = (uint)*(byte *)(unaff_ESI + 0x10);
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)uVar1);
      }
      iVar4 = 0;
      if (*(char *)(unaff_ESI + 0x10) != '\0') {
        do {
          local_24 = 0;
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          local_8 = 0;
          FUN_00524cb0();
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)(uint)*(byte *)(unaff_ESI + 0x10));
      }
    }
    __security_check_cookie(local_4 ^ (uint)&local_28);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

