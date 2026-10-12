/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697990; label: FUN_00697990
 */

void FUN_00697990(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  
  iVar1 = param_1 * 0x34 + in_ECX;
  if ((*(int *)(param_1 * 0x34 + 0xc + in_ECX) != 0) &&
     (((-1 < (int)param_2 || (-1 < *(int *)(iVar1 + 0x3c))) && (*(uint *)(iVar1 + 0x3c) != param_2))
     )) {
    *(uint *)(iVar1 + 0x3c) = param_2;
    iVar2 = *(int *)(*(int *)(iVar1 + 0x1c) * 0x40c + 0x408 + *(int *)(in_ECX + 0xd0c));
    uVar3 = (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f);
    uVar5 = (int)uVar3 >> 0x1f;
    iVar4 = ((uVar3 ^ uVar5) - uVar5) * iVar2;
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x44))
              (*(int **)(iVar1 + 0xc),
               (((int)(iVar4 + (iVar4 >> 0x1f & 0xfffU)) >> 0xc) * 0x30) / (iVar2 / 1000));
  }
  return;
}

