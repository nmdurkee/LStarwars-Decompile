/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c3c0; label: FUN_0074c3c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c3c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,
                 undefined4 param_5,char *param_6,undefined4 param_7,undefined4 param_8)

{
  char cVar1;
  void *_Dst;
  char *pcVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *_Dst_00;
  
  FUN_0074bbc0();
  pcVar2 = param_4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Dst = *(void **)(*(int *)(in_ECX + 0x11c) + 4);
  *(char **)(*(int *)(in_ECX + 0x11c) + 4) = pcVar2 + (int)_Dst + (1 - (int)(param_4 + 1));
  _memcpy(_Dst,param_4,(size_t)(pcVar2 + (1 - (int)(param_4 + 1))));
  if (param_6 == (char *)0x0) {
    _Dst_00 = (void *)0x0;
  }
  else {
    pcVar2 = param_6;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    _Dst_00 = *(void **)(*(int *)(in_ECX + 0x11c) + 4);
    *(char **)(*(int *)(in_ECX + 0x11c) + 4) = pcVar2 + (int)_Dst_00 + (1 - (int)(param_6 + 1));
    _memcpy(_Dst_00,param_6,(size_t)(pcVar2 + (1 - (int)(param_6 + 1))));
  }
  puVar3 = *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4);
  *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4) = puVar3 + 10;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[2] = param_1;
    puVar3[3] = param_2;
    puVar3[4] = param_3;
    puVar3[6] = param_5;
    *puVar3 = 3;
    puVar3[1] = 0;
    puVar3[5] = _Dst;
    puVar3[7] = _Dst_00;
    puVar3[8] = param_7;
    puVar3[9] = param_8;
  }
  if (*(undefined4 **)(in_ECX + 0x118) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 0x114) = puVar3;
    *(undefined4 **)(in_ECX + 0x118) = puVar3 + 1;
    return;
  }
  **(undefined4 **)(in_ECX + 0x118) = puVar3;
  *(undefined4 **)(in_ECX + 0x118) = puVar3 + 1;
  return;
}

