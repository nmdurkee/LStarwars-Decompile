/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69b270; label: FUN_0069b270
 */

int FUN_0069b270(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 0;
  if (in_EAX[0xb0] == 0) {
    return -1;
  }
  if (*in_EAX != 0) {
    uVar2 = FUN_0069f4a0(in_EAX + 6,0x10000);
    iVar3 = (*(code *)in_EAX[0xb0])(uVar2,1,0x10000,*in_EAX);
    if (0 < iVar3) {
      FUN_0069f520(in_EAX + 6,iVar3);
    }
    if ((iVar3 == 0) && (piVar4 = (int *)FUN_006ead5f(), *piVar4 != 0)) {
      return -1;
    }
    return iVar3;
  }
  return 0;
}

