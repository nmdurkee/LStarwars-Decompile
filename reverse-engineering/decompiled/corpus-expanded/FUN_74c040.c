/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74c040; label: FUN_0074c040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c040(char *param_1)

{
  char cVar1;
  void *_Dst;
  char *pcVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  FUN_0074bbc0();
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Dst = *(void **)(*(int *)(in_ECX + 0x11c) + 4);
  *(char **)(*(int *)(in_ECX + 0x11c) + 4) = pcVar2 + (int)_Dst + (1 - (int)(param_1 + 1));
  _memcpy(_Dst,param_1,(size_t)(pcVar2 + (1 - (int)(param_1 + 1))));
  puVar3 = *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4);
  *(undefined4 **)(*(int *)(in_ECX + 0x11c) + 4) = puVar3 + 3;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 2;
    puVar3[1] = 0;
    puVar3[2] = _Dst;
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

