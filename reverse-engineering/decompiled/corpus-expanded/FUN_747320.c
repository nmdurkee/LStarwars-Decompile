/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x747320; label: FUN_00747320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00747320(char *param_1,char *param_2,undefined1 param_3)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int in_ECX;
  void *_Dst;
  
  iVar3 = FUN_00746bb0(param_1);
  if (iVar3 == 0) {
    pcVar4 = param_1;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pvVar2 = *(void **)(in_ECX + 0x948);
    *(char **)(in_ECX + 0x948) = pcVar4 + (int)pvVar2 + (1 - (int)(param_1 + 1));
    _memcpy(pvVar2,param_1,(size_t)(pcVar4 + (1 - (int)(param_1 + 1))));
    if (param_2 == (char *)0x0) {
      _Dst = (void *)0x0;
    }
    else {
      pcVar4 = param_2;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      _Dst = *(void **)(in_ECX + 0x948);
      *(char **)(in_ECX + 0x948) = pcVar4 + (int)_Dst + (1 - (int)(param_2 + 1));
      _memcpy(_Dst,param_2,(size_t)(pcVar4 + (1 - (int)(param_2 + 1))));
    }
    puVar5 = *(undefined4 **)(in_ECX + 0x948);
    *(undefined4 **)(in_ECX + 0x948) = puVar5 + 3;
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = pvVar2;
      puVar5[1] = _Dst;
      *(undefined1 *)(puVar5 + 2) = param_3;
    }
    *(undefined4 **)(in_ECX + *(int *)(in_ECX + 0x4b0) * 4) = puVar5;
    *(int *)(in_ECX + 0x4b0) = *(int *)(in_ECX + 0x4b0) + 1;
    return;
  }
  if (param_2 != (char *)0x0) {
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pvVar2 = *(void **)(in_ECX + 0x948);
    *(char **)(in_ECX + 0x948) = pcVar4 + (int)pvVar2 + (1 - (int)(param_2 + 1));
    _memcpy(pvVar2,param_2,(size_t)(pcVar4 + (1 - (int)(param_2 + 1))));
    *(void **)(iVar3 + 4) = pvVar2;
    *(undefined1 *)(iVar3 + 8) = param_3;
    return;
  }
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined1 *)(iVar3 + 8) = param_3;
  return;
}

