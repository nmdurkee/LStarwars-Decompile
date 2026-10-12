/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69fdd0; label: FUN_0069fdd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069fdd0(int *param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  
  pvVar2 = _realloc((void *)*param_1,param_1[2] * 4 + 8);
  *param_1 = (int)pvVar2;
  pvVar2 = _realloc((void *)param_1[1],param_1[2] * 4 + 8);
  param_1[1] = (int)pvVar2;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  *(int *)((int)pvVar2 + param_1[2] * 4) = (int)pcVar3 - (int)(param_2 + 1);
  pvVar2 = _malloc(*(int *)(param_1[1] + param_1[2] * 4) + 1);
  *(void **)(*param_1 + param_1[2] * 4) = pvVar2;
  pcVar3 = *(char **)(*param_1 + param_1[2] * 4);
  do {
    cVar1 = *param_2;
    *pcVar3 = cVar1;
    param_2 = param_2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_1[2] = param_1[2] + 1;
  *(undefined4 *)(*param_1 + param_1[2] * 4) = 0;
  return;
}

