/* Ghidra analysis pseudocode, not original source.
 * ev_ec9281a2aa4ea110a1eb16e51d284c9eba7f36598b96ab7e95af51b91ca91f37
 * Entry: 0x7416a0; label: FUN_007416a0
 */

int * FUN_007416a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 uStack_4;
  
  (**(code **)(*in_ECX + 8))(param_1,param_2);
  FUN_00744320(param_1,param_2,param_1,param_2);
  FUN_00744b70(&stack0x00000000,&stack0xffffffd4,(char)param_3 != '\0');
  iVar2 = 0;
  piVar3 = in_ECX + 3;
  do {
    if (*piVar3 == 0) {
      piVar3 = in_ECX + iVar2 * 0x136 + 1;
      if (piVar3 != (int *)0x0) {
        piVar3[1] = piVar3[1] + 1;
        return piVar3;
      }
      break;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 0x136;
  } while (iVar2 < 400);
  piVar3 = (int *)FUN_007414c0(&uStack_4);
  cVar1 = (**(code **)(*in_ECX + 4))(&stack0xffffffd4,param_3,piVar3,uStack_4);
  if (cVar1 != '\0') {
    piVar3[1] = piVar3[1] + 1;
    return piVar3;
  }
  return (int *)0x0;
}

