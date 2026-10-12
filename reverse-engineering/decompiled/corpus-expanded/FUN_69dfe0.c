/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69dfe0; label: FUN_0069dfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069dfe0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  local_4 = 0;
  if (param_5 < 1) {
    return;
  }
  do {
    iVar1 = FUN_006a2db0(param_3,&local_8);
    if (iVar1 == 0) {
      iVar1 = FUN_0069c090(0,1,0);
      if (iVar1 == -2) {
        if (param_5 <= iVar2) {
          return;
        }
        iVar1 = FUN_006a2e40(param_1 + 0x1e0,&local_8);
        if (iVar1 == 0) {
          iVar1 = 0;
          if (*(int *)(param_2 + 4) < 1) {
            return;
          }
          do {
            _memset((void *)(*(int *)(param_4 + iVar1 * 4) + iVar2 * 4),0,param_5 * 4 - iVar2);
            iVar1 = iVar1 + 1;
          } while (iVar1 < *(int *)(param_2 + 4));
          return;
        }
        if (param_5 - iVar2 < iVar1) {
          iVar1 = param_5 - iVar2;
        }
        iVar4 = 0;
        if (*(int *)(param_2 + 4) < 1) {
          return;
        }
        do {
          _memcpy((void *)(*(int *)(param_4 + iVar4 * 4) + iVar2 * 4),
                  *(void **)(local_8 + iVar4 * 4),iVar1 * 4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(param_2 + 4));
        return;
      }
    }
    else {
      if (param_5 - iVar2 < iVar1) {
        iVar1 = param_5 - iVar2;
      }
      iVar3 = 0;
      iVar4 = iVar2;
      if (0 < *(int *)(param_2 + 4)) {
        do {
          _memcpy((void *)(*(int *)(param_4 + iVar3 * 4) + iVar2 * 4),
                  *(void **)(local_8 + iVar3 * 4),iVar1 * 4);
          iVar3 = iVar3 + 1;
          iVar4 = local_4;
        } while (iVar3 < *(int *)(param_2 + 4));
      }
      iVar2 = iVar4 + iVar1;
      local_4 = iVar2;
      FUN_006a2e10(param_3,iVar1);
    }
    if (param_5 <= iVar2) {
      return;
    }
  } while( true );
}

