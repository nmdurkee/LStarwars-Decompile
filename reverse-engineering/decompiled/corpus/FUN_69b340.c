/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69b340; label: FUN_0069b340
 */

undefined8 FUN_0069b340(undefined4 param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  bool bVar6;
  
  if (param_3 < 0) goto LAB_0069b37d;
  if ((0 < param_3) || (param_2 != 0)) {
    bVar6 = CARRY4(param_2,*(uint *)(unaff_ESI + 8));
    param_2 = param_2 + *(uint *)(unaff_ESI + 8);
    param_3 = param_3 + *(int *)(unaff_ESI + 0xc) + (uint)bVar6;
  }
  while( true ) {
    while( true ) {
      if (((-1 < param_3) && ((0 < param_3 || (param_2 != 0)))) &&
         ((param_3 < *(int *)(unaff_ESI + 0xc) ||
          ((param_3 <= *(int *)(unaff_ESI + 0xc) && (param_2 <= *(uint *)(unaff_ESI + 8))))))) {
        return 0xffffffffffffffff;
      }
LAB_0069b37d:
      uVar4 = FUN_0069f540(unaff_ESI + 0x18,param_1);
      if (-1 < (int)uVar4) break;
      puVar1 = (uint *)(unaff_ESI + 8);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 - uVar4;
      *(int *)(unaff_ESI + 0xc) =
           (*(int *)(unaff_ESI + 0xc) - ((int)uVar4 >> 0x1f)) - (uint)(uVar2 < uVar4);
    }
    if (uVar4 != 0) {
      uVar2 = *(uint *)(unaff_ESI + 8);
      uVar3 = *(undefined8 *)(unaff_ESI + 8);
      *(uint *)(unaff_ESI + 0xc) =
           ((int)uVar4 >> 0x1f) + *(int *)(unaff_ESI + 0xc) + (uint)CARRY4(uVar4,uVar2);
      *(uint *)(unaff_ESI + 8) = uVar4 + uVar2;
      return uVar3;
    }
    if (param_2 == 0 && param_3 == 0) break;
    iVar5 = FUN_0069b270();
    if (iVar5 == 0) {
      return 0xfffffffffffffffe;
    }
    if (iVar5 < 0) {
      return 0xffffffffffffff80;
    }
  }
  return 0xffffffffffffffff;
}

