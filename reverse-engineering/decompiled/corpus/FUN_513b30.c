/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513b30; label: FUN_00513b30
 */

void FUN_00513b30(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *_Dst;
  undefined4 *puVar6;
  void *local_10;
  int local_c;
  
  for (iVar3 = FUN_004f1440(param_1); iVar3 != 0; iVar3 = FUN_004f1460(param_1,iVar3)) {
    if (((param_3 == (int *)0x0) || (param_4 == (uint *)0x0)) || (*param_4 <= *param_3 + 0x14U)) {
      FUN_00512850();
    }
    else {
      uVar4 = *param_3 + 0xf;
      puVar6 = (undefined4 *)(uVar4 & 0xfffffff0);
      *param_3 = (uVar4 & 0xfffffff0) + 0x14;
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      if (puVar6 != (undefined4 *)0x0) {
        sVar1 = *(int *)(iVar3 + 0xc) * 4;
        _Dst = (void *)0x0;
        if (*param_3 + sVar1 < *param_4) {
          _Dst = (void *)(*param_3 + 0xfU & 0xfffffff0);
          *param_3 = (*param_3 + 0xfU & 0xfffffff0) + sVar1;
          _memset(_Dst,0,sVar1);
        }
        else {
          FUN_00512850();
        }
        puVar6[2] = _Dst;
        iVar2 = *(int *)(iVar3 + 0xc);
        puVar6[3] = iVar2;
        local_c = 0;
        if (0 < iVar2) {
          do {
            iVar2 = *(int *)(*(int *)(iVar3 + 8) + local_c * 4);
            local_10 = (void *)0x0;
            if ((iVar2 != 0) && (iVar5 = FUN_004f1ff0(iVar2), iVar5 != 0)) {
              sVar1 = iVar5 + 1;
              local_10 = (void *)0x0;
              if (*param_3 + sVar1 < *param_4) {
                uVar4 = *param_3 + 0xf;
                local_10 = (void *)(uVar4 & 0xfffffff0);
                *param_3 = (uVar4 & 0xfffffff0) + sVar1;
                _memset(local_10,0,sVar1);
              }
              else {
                FUN_00512850();
              }
              FUN_004f1f10(local_10,iVar2);
            }
            *(void **)(puVar6[2] + local_c * 4) = local_10;
            local_c = local_c + 1;
          } while (local_c < (int)puVar6[3]);
        }
        puVar6[4] = *(undefined4 *)(iVar3 + 0x10);
        FUN_004f1310(param_2,puVar6);
      }
    }
  }
  return;
}

