/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a0f00; label: FUN_006a0f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_006a0f00(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_1c;
  undefined1 local_14 [8];
  void *local_c;
  
  iVar1 = *(int *)(param_1 + 0x68);
  uVar6 = *(undefined4 *)(param_1 + 4);
  local_1c = 0xffffff7e;
  if (iVar1 == 0) {
    local_1c = 0xffffff7f;
  }
  else {
    FUN_006a3490(local_14);
    iVar2 = FUN_006a0a30();
    if (iVar2 == 0) {
      if (*(void **)(iVar1 + 0x40) != (void *)0x0) {
        _free(*(void **)(iVar1 + 0x40));
      }
      sVar3 = FUN_006a3db0(local_14);
      pvVar4 = _malloc(sVar3);
      *(void **)(iVar1 + 0x40) = pvVar4;
      sVar3 = FUN_006a3db0(local_14);
      _memcpy(*(void **)(iVar1 + 0x40),local_c,sVar3);
      *param_3 = *(undefined4 *)(iVar1 + 0x40);
      uVar5 = FUN_006a3db0(local_14);
      param_3[1] = uVar5;
      param_3[2] = 1;
      param_3[3] = 0;
      param_3[4] = 0;
      param_3[5] = 0;
      param_3[6] = 0;
      param_3[7] = 0;
      FUN_006a38a0(local_14);
      iVar2 = FUN_006a0b20(param_2);
      if (iVar2 == 0) {
        if (*(void **)(iVar1 + 0x44) != (void *)0x0) {
          _free(*(void **)(iVar1 + 0x44));
        }
        sVar3 = FUN_006a3db0(local_14);
        pvVar4 = _malloc(sVar3);
        *(void **)(iVar1 + 0x44) = pvVar4;
        sVar3 = FUN_006a3db0(local_14);
        _memcpy(*(void **)(iVar1 + 0x44),local_c,sVar3);
        *param_4 = *(undefined4 *)(iVar1 + 0x44);
        uVar5 = FUN_006a3db0(local_14);
        param_4[1] = uVar5;
        param_4[2] = 0;
        param_4[3] = 0;
        param_4[4] = 0;
        param_4[5] = 0;
        param_4[6] = 1;
        param_4[7] = 0;
        FUN_006a38a0(local_14);
        iVar2 = FUN_006a0c50(uVar6);
        if (iVar2 == 0) {
          if (*(void **)(iVar1 + 0x48) != (void *)0x0) {
            _free(*(void **)(iVar1 + 0x48));
          }
          sVar3 = FUN_006a3db0(local_14);
          pvVar4 = _malloc(sVar3);
          *(void **)(iVar1 + 0x48) = pvVar4;
          sVar3 = FUN_006a3db0(local_14);
          _memcpy(*(void **)(iVar1 + 0x48),local_c,sVar3);
          *param_5 = *(undefined4 *)(iVar1 + 0x48);
          uVar6 = FUN_006a3db0(local_14);
          param_5[1] = uVar6;
          param_5[2] = 0;
          param_5[3] = 0;
          param_5[4] = 0;
          param_5[5] = 0;
          param_5[6] = 2;
          param_5[7] = 0;
          FUN_006a38e0(local_14);
          return 0;
        }
      }
    }
  }
  FUN_006a38e0(local_14);
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  *param_5 = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  param_5[5] = 0;
  param_5[6] = 0;
  param_5[7] = 0;
  if (iVar1 != 0) {
    if (*(void **)(iVar1 + 0x40) != (void *)0x0) {
      _free(*(void **)(iVar1 + 0x40));
    }
    if (*(void **)(iVar1 + 0x44) != (void *)0x0) {
      _free(*(void **)(iVar1 + 0x44));
    }
    if (*(void **)(iVar1 + 0x48) != (void *)0x0) {
      _free(*(void **)(iVar1 + 0x48));
    }
    *(undefined4 *)(iVar1 + 0x40) = 0;
    *(undefined4 *)(iVar1 + 0x44) = 0;
    *(undefined4 *)(iVar1 + 0x48) = 0;
  }
  return local_1c;
}

