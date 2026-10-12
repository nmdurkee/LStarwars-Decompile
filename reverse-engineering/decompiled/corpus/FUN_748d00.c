/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748d00; label: FUN_00748d00
 */

void FUN_00748d00(int *param_1)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  int *unaff_retaddr;
  
  iVar1 = 0;
  if (0 < in_ECX[0x2aa]) {
    piVar2 = in_ECX + 0x1b0;
    do {
      iVar1 = iVar1 + 1;
      *(undefined4 *)(*piVar2 + 0x20) = 0;
      piVar2 = piVar2 + 1;
    } while (iVar1 < in_ECX[0x2aa]);
  }
  in_ECX[0x2d5] = in_ECX[0x2d7];
  in_ECX[0x1af] = 0;
  (**(code **)(*in_ECX + 0x18))(param_1,in_ECX + 0x83);
  FUN_00748150(in_ECX[0x82],0);
  FUN_00748150(in_ECX[0x82],0);
  FUN_00747320("_SHADERBUILDER_DEBUG",0,0);
  if (unaff_retaddr != (int *)0x0) {
    unaff_retaddr[1] = 0;
    in_ECX[0x2e2] = 0;
    FUN_00746810(unaff_retaddr);
    FUN_00748150(in_ECX[0x82],unaff_retaddr);
    iVar1 = unaff_retaddr[1];
    if ((0 < iVar1) && (*(char *)(*unaff_retaddr + -1 + iVar1) != '\0')) {
      if (unaff_retaddr[2] < iVar1 + 1) {
        FUN_007484e0((iVar1 * 3 + 3) / 2);
      }
      *(undefined1 *)(unaff_retaddr[1] + *unaff_retaddr) = 0;
      unaff_retaddr[1] = unaff_retaddr[1] + 1;
    }
  }
  if (param_1 != (int *)0x0) {
    param_1[1] = 0;
    in_ECX[0x2e2] = 1;
    FUN_00746810(param_1);
    FUN_00748150(in_ECX[0x82],param_1);
    iVar1 = param_1[1];
    if ((0 < iVar1) && (*(char *)(iVar1 + -1 + *param_1) != '\0')) {
      if (param_1[2] < iVar1 + 1) {
        FUN_007484e0((iVar1 * 3 + 3) / 2);
      }
      *(undefined1 *)(param_1[1] + *param_1) = 0;
      param_1[1] = param_1[1] + 1;
    }
  }
  return;
}

