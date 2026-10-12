/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52bcb0; label: FUN_0052bcb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052bcb0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5
                 ,uint *param_6)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  void *_Dst;
  uint *local_4c;
  int local_48;
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_4c;
  local_4c = param_6;
  local_48 = FUN_00513400(param_4);
  if (local_48 != 0) {
    if (*param_1 == 0) {
      _Dst = (void *)0x0;
      if (((param_5 == (int *)0x0) || (local_4c == (uint *)0x0)) || (*local_4c <= *param_5 + 0x58U))
      {
        FUN_00512850();
      }
      else {
        uVar2 = *param_5 + 0xf;
        _Dst = (void *)(uVar2 & 0xfffffff0);
        *param_5 = (uVar2 & 0xfffffff0) + 0x58;
        _memset(_Dst,0,0x58);
      }
      *param_1 = (int)_Dst;
      if (_Dst != (void *)0x0) {
        _memset(_Dst,0,0x58);
        FUN_004f1f10(local_44,param_3);
        puVar3 = (undefined1 *)FUN_004f8a70(local_44,&DAT_0075ffd8);
        if (puVar3 != (undefined1 *)0x0) {
          *puVar3 = 0;
        }
        uVar4 = FUN_00513100(local_44,local_4c);
        *(undefined4 *)(*param_1 + 8) = uVar4;
      }
    }
    iVar1 = local_48;
    FUN_005137a0(*param_1);
    FUN_004fa300(iVar1);
    __security_check_cookie(local_4 ^ (uint)&local_4c);
    return;
  }
  if (DAT_00922248 == 1) {
    FUN_00512860();
  }
  else {
    FUN_00512850(param_3);
  }
  __security_check_cookie(local_4 ^ (uint)&local_4c);
  return;
}

