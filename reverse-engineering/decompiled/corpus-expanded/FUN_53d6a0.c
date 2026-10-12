/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d6a0; label: FUN_0053d6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0053d6a0(int param_1,int param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  undefined1 *_Dst;
  undefined **ppuVar4;
  undefined1 uStack_1060;
  byte bStack_105f;
  char cStack_105e;
  char local_105d;
  undefined2 auStack_105c [2];
  ushort auStack_1058 [2];
  int iStack_1054;
  undefined4 uStack_1050;
  int *local_104c;
  int iStack_1048;
  undefined4 auStack_1044 [16];
  undefined1 auStack_1004 [4096];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&uStack_1060;
  local_104c = in_ECX;
  if ((DAT_00876d8c == (code *)0x0) || (iVar2 = (*DAT_00876d8c)(), iVar2 != 0)) {
    do {
      if (param_2 != 0) {
        FUN_004ef660(&local_105d,param_3 + param_2,1);
        param_3 = param_3 + 1;
      }
      if (local_105d == '\x01') {
        _memset(auStack_1004,0,0x1000);
        _memset(auStack_1044,0,0x40);
        if (param_2 != 0) {
          FUN_004ef660(&cStack_105e,param_3 + param_2,1);
          FUN_004ef660(auStack_1058,param_3 + 1 + param_2,2);
          if (param_1 != 0) {
            FUN_00621180(auStack_1058);
          }
          FUN_004ef660(auStack_105c,param_3 + 3 + param_2,2);
          if (param_1 != 0) {
            FUN_00621180(auStack_105c);
          }
          FUN_004ef660(&bStack_105f,param_3 + 5 + param_2,1);
          param_3 = param_3 + 6;
        }
        iStack_1048 = (**(code **)(*in_ECX + 0x2c))();
        uStack_1050 = (**(code **)(*in_ECX + 0x34))(auStack_105c[0]);
        uVar3 = (uint)bStack_105f;
        if (bStack_105f < 0x10) {
          iStack_1054 = 0;
          if (bStack_105f != 0) {
            _Dst = auStack_1004;
            do {
              if (param_2 != 0) {
                cVar1 = *(char *)(param_3 + param_2);
                _memset(_Dst,0,0x100);
                FUN_004ef660(_Dst,param_3 + 1 + param_2,(int)cVar1);
                uVar3 = (uint)bStack_105f;
                param_3 = param_3 + 1 + (int)cVar1;
                in_ECX = local_104c;
              }
              auStack_1044[iStack_1054] = _Dst;
              iStack_1054 = iStack_1054 + 1;
              _Dst = _Dst + 0x100;
            } while (iStack_1054 < (int)uVar3);
          }
          ppuVar4 = DAT_00922228;
          if (cStack_105e == '\0') {
            ppuVar4 = &PTR_DAT_008019c0;
          }
          if ((iStack_1048 != 0) &&
             (iVar2 = (*(code *)ppuVar4[(uint)auStack_1058[0] * 3 + 1])
                                (iStack_1048,0,uStack_1050,auStack_1044,uVar3,1,0), iVar2 != 1)) {
            FUN_0053d140(*ppuVar4);
          }
        }
      }
      if (param_2 == 0) goto LAB_0053d91e;
    } while (param_4 != param_3 && -1 < param_4 - param_3);
    if (*(uint *)(param_2 + 0x4b0) < 2) {
      *(undefined4 *)(param_2 + 0x4b0) = 0;
    }
    else {
      *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
    }
  }
  else if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x4b0) < 2) {
      *(undefined4 *)(param_2 + 0x4b0) = 0;
      __security_check_cookie(local_4 ^ (uint)&uStack_1060);
      return;
    }
    *(uint *)(param_2 + 0x4b0) = *(uint *)(param_2 + 0x4b0) - 1;
    __security_check_cookie(local_4 ^ (uint)&uStack_1060);
    return;
  }
LAB_0053d91e:
  __security_check_cookie(local_4 ^ (uint)&uStack_1060);
  return;
}

