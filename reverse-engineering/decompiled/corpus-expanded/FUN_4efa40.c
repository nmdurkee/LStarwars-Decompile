/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efa40; label: FUN_004efa40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_004efa40(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint *in_ECX;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    return (uint *)0x0;
  }
  param_2 = param_2 + param_3;
  puVar2 = (uint *)(iVar1 + 0x10);
  while( true ) {
    if (puVar2 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if (param_2 + 0x10U < (*puVar2 & 0x7fffffff)) break;
    puVar2 = (uint *)puVar2[1];
  }
  if (puVar2[2] != 0) {
    *(uint *)(puVar2[2] + 4) = puVar2[1];
  }
  if (puVar2[1] != 0) {
    *(uint *)(puVar2[1] + 8) = puVar2[2];
  }
  FUN_004ef8a0(puVar2,&param_2,param_3);
  if (*(int *)(iVar1 + 0x14) != 0) {
    *(int **)(*(int *)(iVar1 + 0x14) + 8) = param_1;
  }
  param_1[1] = *(int *)(iVar1 + 0x14);
  param_1[2] = iVar1 + 0x10;
  *(int **)(iVar1 + 0x14) = param_1;
  param_1[2] = param_1[2] + 1;
  param_1[3] = param_1[3] + (*in_ECX & 0x7fffffff) + 0x10;
  return in_ECX + 3;
}

