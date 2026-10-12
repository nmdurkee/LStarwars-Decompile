/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697740; label: FUN_00697740
 */

uint FUN_00697740(int param_1,int param_2,uint *param_3)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  
  if (DAT_00827610 == 0) {
    *param_3 = 0xffffffff;
    return (uint)param_3 & 0xffffff00;
  }
  uVar2 = 0;
  piVar1 = (int *)(in_ECX + 0x20);
  while (((piVar1[-1] != param_2 || (*piVar1 != param_1)) || (*(char *)((int)piVar1 + 5) != '\0')))
  {
    uVar2 = uVar2 + 1;
    piVar1 = piVar1 + 0xd;
    if (0x3f < (int)uVar2) {
      uVar2 = FUN_00697470(param_2,1);
      *param_3 = uVar2;
      return uVar2 & 0xffffff00;
    }
  }
  *param_3 = uVar2;
  return CONCAT31((int3)((uint)piVar1 >> 8),1);
}

